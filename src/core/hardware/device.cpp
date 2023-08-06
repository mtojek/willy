#include "core/hardware/device.h"

#define TAG "device"

int melody[] = {NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
                NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_F5,
                NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
                NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {8, 8, 4, 8, 8, 4,  8,  8, 8, 8, 2, 8, 8,
                       8, 8, 8, 8, 8, 16, 16, 8, 8, 8, 8, 4, 4};

Device::Device()
    : display(Display(PCD8544_DC_PIN, PCD8544_CS_PIN, PCD8544_RST_PIN,
                      PCD8544_CONTRAST, PCD8544_BIAS)),
      led(Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800)),
      joystick(
          Joystick(JOYSTICK1_VRX_PIN, JOYSTICK1_VRY_PIN, JOYSTICK1_SW_PIN)),
      transceiver24(
          Transceiver24(TRANSCEIVER_24_CE_PIN, TRANSCEIVER_24_CSN_PIN)),
      transceiver433(Transceiver433(TRANSCEIVER_433_CSN_PIN,
                                    TRANSCEIVER_433_GDO0_PIN,
                                    TRANSCEIVER_433_GDO2_PIN)),
      buzzer(Buzzer(BUZZER_PIN)) {}

bool Device::initialize() {
  Serial.begin(115200);
  while (!Serial)
    ;

  ESP_LOGI(TAG, "Willy is starting...");
  printHardwareInfo();

  if (!display.initialize()) {
    return false;
  }

  boot();

  ezBuzzer *b = buzzer.getDriver();

  int length = sizeof(noteDurations) / sizeof(int);
  b->playMelody(melody, noteDurations, length);
  return true;
}

void Device::printHardwareInfo() {
  ESP_LOGI(TAG, "Chip model: %s rev. %d", ESP.getChipModel(),
           ESP.getChipRevision());
  ESP_LOGI(TAG, "CPU cores: %d", ESP.getChipCores());

  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  ESP_LOGI(TAG, "Flash: %dMB %s", spi_flash_get_chip_size() / (1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded"
                                                         : "external");
  ESP_LOGI(TAG, "Flash memory embedded: %s",
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "yes" : "no");
  ESP_LOGI(TAG, "2.4GHz WiFi: %s",
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "yes" : "no");
  ESP_LOGI(TAG, "Bluetooth LE: %s",
           (chip_info.features & CHIP_FEATURE_BLE) ? "yes" : "no");
  ESP_LOGI(TAG, "Bluetooth Classic: %s",
           (chip_info.features & CHIP_FEATURE_BT) ? "yes" : "no");
  ESP_LOGI(TAG, "IEEE 802.15.4: %s",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? "yes" : "no");
  ESP_LOGI(TAG, "PSRAM embedded: %s",
           (chip_info.features & CHIP_FEATURE_EMB_PSRAM) ? "yes" : "no");
  ESP_LOGI(TAG, "Silicon revision: %d", chip_info.revision);

  uint64_t chipID = ESP.getEfuseMac();
  ESP_LOGI(TAG, "Chip ID: %04X", (uint16_t)(chipID >> 32));
  ESP_LOGI(TAG, "MAC address: %08X", (uint32_t)chipID);

  ESP_LOGI(TAG, "CPU temperature: %.2f C", temperatureRead());
}

void Device::boot() {
  Adafruit_PCD8544 *d = display.getDriver();
  d->fillScreen(1);
  d->display();

  led.setPixelColor(0, 255, 0, 0); // red pixel
  for (int i = 1; i <= LED_BRIGHTNESS; i++) {
    led.setBrightness(i);
    led.show();
    delay(100);
  }

  d->clearDisplay();
  d->display();
}

void Device::sync() {
  joystick.sync();
  buzzer.sync();
}

Display *Device::getDisplay() { return &display; }

Joystick *Device::getJoystick() { return &joystick; }

Transceiver24 *Device::getTransceiver24() { return &transceiver24; }

Transceiver433 *Device::getTransceiver433() { return &transceiver433; }

Buzzer *Device::getBuzzer() { return &buzzer; }