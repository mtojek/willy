#include "core/hardware/sdcard.h"

const char *SDCARD_TAG = "sdcard";

SDCard::SDCard(int csPin) : csPin(csPin) {}

bool SDCard::initialize() {
  pinMode(csPin, OUTPUT);
  if (!SD.begin(csPin)) {
    ESP_LOGE(SDCARD_TAG, "SD card failed initialization.");
    return false;
  }

  uint8_t cardType = SD.cardType();

  if (cardType == CARD_NONE) {
    ESP_LOGE(SDCARD_TAG, "SD card is not attached.");
    return false;
  }

  if (cardType == CARD_MMC) {
    ESP_LOGI(SDCARD_TAG, "SD card type: MMC");
  } else if (cardType == CARD_SD) {
    ESP_LOGI(SDCARD_TAG, "SD card type: SDSC");
  } else if (cardType == CARD_SDHC) {
    ESP_LOGI(SDCARD_TAG, "SD card type: SDHC");
  } else {
    ESP_LOGI(SDCARD_TAG, "SD card type: UNKNOWN");
  }

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  ESP_LOGI(SDCARD_TAG, "SD card size: %lluMB", cardSize);

  return true;
}