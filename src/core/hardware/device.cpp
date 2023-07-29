#include "core/hardware/device.h"

#define TAG "device"

Device::Device()
    : display(Display(PCD8544_DC_PIN, PCD8544_CS_PIN, PCD8544_RST_PIN,
                      PCD8544_CONTRAST, PCD8544_BIAS)),
      led(Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800)),
      joystick(Joystick(JOYSTICK_VRX_PIN, JOYSTICK_VRY_PIN, JOYSTICK_SW_PIN)),
      transceiver24(Transceiver24(RADIO_CE_PIN, RADIO_CSN_PIN)),
      transceiver433(
          Transceiver433(CC1101_CSN_PIN, CC1101_GDO0_PIN, CC1101_GDO2_PIN)) {}

volatile long last_micros;
volatile long last_millis;

int timings[1024] = {0};
int t = 0;

void radioHandlerOnChange() {
  int now = micros();
  int delta_micros = now - last_micros;
  timings[t++] = delta_micros;
  last_micros = now;
}

bool Device::initialize() {
  Serial.begin(115200);
  while (!Serial)
    ;

  ESP_LOGI(TAG, "Willy is starting...");
  printHardwareInfo();

  /*if (!transceiver24.initialize()) {
    ESP_LOGE(TAG, "Transceiver 2.4Ghz initialization failed");
    return false;
  }*/
  if (!transceiver433.initialize()) {
    ESP_LOGE(TAG, "Transceiver 433Mhz initialization failed");
    return false;
  }

  // TODO Device initialize can fatal

  ESP_LOGI(TAG, "Initialization done");

  CC1101 *radio = transceiver433.getDriver();
  radio->setMHZ(433.92);
  radio->setTXPwr(TX_0_DBM);
  radio->setRxBW(RX_BW_58_KHZ);
  radio->setDataRate(10000);
  radio->setModulation(ASK_OOK);
  radio->setRx();

  int interruptPin = digitalPinToInterrupt(CC1101_GDO2_PIN);
  attachInterrupt(interruptPin, radioHandlerOnChange, CHANGE);

  while (true) {
    if (millis() > (last_millis + 5000)) {
      radio->setIdle();

      Serial.printf("Received: %d\n", t);
      for (int i = 0; i < t; i++) {
        Serial.print(timings[i]);
        Serial.print(", ");
      }
      Serial.println();

      t = 0;
      radio->setRx();

      last_millis = millis();
    }
  }

  // display.initialize();
  // boot();
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

void Device::sync() { joystick.sync(); }

Display *Device::getDisplay() { return &display; }

Joystick *Device::getJoystick() { return &joystick; }

Transceiver24 *Device::getTransceiver24() { return &transceiver24; }

Transceiver433 *Device::getTransceiver433() { return &transceiver433; }