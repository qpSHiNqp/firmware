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
#define USE_LORA_UART
#define LORA_TX 1
#define LORA_RX 3
#define LORA_AUX 5
#define LORA_M0 6
#define LORA_M1 7
