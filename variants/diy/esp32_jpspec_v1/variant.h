// Serial
#define SERIAL_TX 1
#define SERIAL_RX 3

// I2C
#define I2C_SDA 21
#define I2C_SCL 22

// SPI
#define SPI_SS 5
#define SPI_MOSI 23
#define SPI_MISO 19
#define SPI_SCK 18

// DAC
#define DAC1 25
#define DAC2 26

// For GPS
//#define GPS_TX_PIN 15
//#define GPS_RX_PIN 12
//#define PIN_GPS_EN 4
//#define GPS_POWER_TOGGLE // Moved definition from platformio.ini to here
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

#define BUTTON_PIN 0 // This is the BOOT button
#define BUTTON_NEED_PULLUP

// Recommended pins for SerialModule:
#define SERIAL_TXD SERIAL0_TX_GPIO
#define SERIAL_RXD SERIAL0_RX_GPIO
#define SERIAL1_RXD 9
#define SERIAL1_TXD 10
#define SERIAL2_RXD 16
#define SERIAL2_TXD 17


// #define HAS_SCREEN 0
// #define HAS_SDCARD
// #define SDCARD_USE_SPI1

// #define USE_SSD1306


// #define LED_PIN 38     // This is a RGB LED not a standard LED


// supported modules list
#define USE_SX1262
#define USE_LLCC68

#define LORA_RXEN 3 // Input - RF switch RX control, connecting external MCU IO, valid in high level
#define LORA_TXEN 1 // Input - RF switch TX control, connecting external MCU IO or DIO2, valid in high level

#define LORA_MISO 3
#define LORA_SCK 5
#define LORA_MOSI 1
#define LORA_CS 7

#define LORA_RESET 8
#define LORA_DIO0 14
#define LORA_DIO1 15
#define LORA_DIO2 16

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
