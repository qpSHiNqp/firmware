#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// #define HAS_SCREEN 0
// #define HAS_SDCARD
// #define SDCARD_USE_SPI1

// #define USE_SSD1306

#define I2C_SDA 18 // 1 // I2C pins for this board
#define I2C_SCL 17 // 2

// #define LED_PIN 38     // This is a RGB LED not a standard LED

#define BUTTON_PIN 0 // This is the BOOT button
#define BUTTON_NEED_PULLUP

// supported modules list
#define USE_RF95 // RFM95/SX127x
#define USE_SX1262
#define USE_SX1280
#define USE_LLCC68

#define LORA_RXEN 3 // Input - RF switch RX control, connecting external MCU IO, valid in high level
#define LORA_TXEN 1 // Input - RF switch TX control, connecting external MCU IO or DIO2, valid in high level

#define LORA_MISO 3
#define LORA_SCK 5
#define LORA_MOSI 1
#define LORA_CS 7

#define LORA_RESET 8
#define LORA_DIO1 16

// RX/TX for RFM95/SX127x
#define RF95_RXEN LORA_RXEN
#define RF95_TXEN LORA_TXEN
// #define RF95_TCXO <GPIO#>

#ifdef USE_SX1262
#define SX126X_CS LORA_CS // FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN LORA_RXEN
#define SX126X_TXEN LORA_TXEN
#endif

// common pinouts for SX126X modules
#ifdef USE_SX1280
#define SX128X_CS LORA_CS
#define SX128X_DIO1 LORA_DIO1
#define SX128X_BUSY 15
#define SX128X_RESET LORA_RESET
#endif

#ifdef EBYTE_E22
// Internally the TTGO module hooks the SX126x-DIO2 in to control the TX/RX switch
// (which is the default for the sx1262interface code)
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif
