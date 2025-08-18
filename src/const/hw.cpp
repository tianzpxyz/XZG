#include "const/hw.h"

// Ethernet configurations
// Don't forget to edit ETH_CFG_CNT !
EthConfig ethConfigs[] = {
    {.addr = 0, .pwrPin = 12, .mdcPin = 23, .mdiPin = 18, .phyType = ETH_PHY_LAN8720, .clkMode = ETH_CLOCK_GPIO17_OUT}, // .pwrAltPin = -1},  // 0 Olimex-ESP32-POE
    {.addr = 1, .pwrPin = 16, .mdcPin = 23, .mdiPin = 18, .phyType = ETH_PHY_LAN8720, .clkMode = ETH_CLOCK_GPIO0_IN},   // .pwrAltPin = -1},  // 1 WT32-ETH01 / SLZB-06
    {.addr = 0, .pwrPin = 5, .mdcPin = 23, .mdiPin = 18, .phyType = ETH_PHY_LAN8720, .clkMode = ETH_CLOCK_GPIO17_OUT},  // .pwrAltPin = -1},  // 2 T-Internet-POE / UZG-01 / HamGeek POE Plus
};

// ZigBee configurations
// Don't forget to edit ZB_CFG_CNT !
ZbConfig zbConfigs[] = {
    {.txPin = 4, .rxPin = 36, .rstPin = 16, .bslPin = 32},  // 0 UZG-01 / LilyZig / Olizig
    {.txPin = 17, .rxPin = 5, .rstPin = 33, .bslPin = 32},  // 1 ZigStar LAN / SLZB-06 / TubesZB-eth
    {.txPin = 33, .rxPin = 32, .rstPin = 12, .bslPin = 14}, // 2 No name China-GW
    {.txPin = 5, .rxPin = 17, .rstPin = 33, .bslPin = 32},  // 3 TubesZB-eth_usb
    {.txPin = 16, .rxPin = 5, .rstPin = 33, .bslPin = 32},  // 4 TubesZB-poe
    {.txPin = 16, .rxPin = 5, .rstPin = 13, .bslPin = 4},   // 5 TubesZB-poe-2022
    {.txPin = 4, .rxPin = 36, .rstPin = 5, .bslPin = 16},   // 6 TubesZB-poe-2023
    {.txPin = 23, .rxPin = 22, .rstPin = 18, .bslPin = 19}, // 7 SLS-classic
};

// Mist configurations
// Don't forget to edit MIST_CFG_CNT !
MistConfig mistConfigs[] = {
    {.btnPin = -1, .btnPlr = 0, .uartSelPin = -1, .uartSelPlr = 0, .ledModePin = -1, .ledModePlr = 0, .ledPwrPin = -1, .ledPwrPlr = 0}, // 0 No mist cfg
    {.btnPin = 35, .btnPlr = 1, .uartSelPin = 33, .uartSelPlr = 1, .ledModePin = 12, .ledModePlr = 1, .ledPwrPin = 14, .ledPwrPlr = 1}, // 1 UZG-01 / CZC-1.0
    {.btnPin = 35, .btnPlr = 1, .uartSelPin = 4, .uartSelPlr = 1, .ledModePin = 12, .ledModePlr = 1, .ledPwrPin = 14, .ledPwrPlr = 1},  // 2 SLZB-06
    {.btnPin = 33, .btnPlr = 1, .uartSelPin = -1, .uartSelPlr = 0, .ledModePin = -1, .ledModePlr = 0, .ledPwrPin = -1, .ledPwrPlr = 0}, // 3 SLS-classic
    {.btnPin = 14, .btnPlr = 1, .uartSelPin = -1, .uartSelPlr = 0, .ledModePin = -1, .ledModePlr = 0, .ledPwrPin = -1, .ledPwrPlr = 0}, // 4 T-Internet-POE
};

// Board configurations
// Don't forget to edit BOARD_CFG_CNT !
BrdConfigStruct brdConfigs[] = {
    {"SLS-classic", .ethConfigIndex = -1, .zbConfigIndex = 7, .mistConfigIndex = 3},     // 0
    {"UZG-01", .ethConfigIndex = 2, .zbConfigIndex = 0, .mistConfigIndex = 1},           // 1
    {"SLZB-06", .ethConfigIndex = 1, .zbConfigIndex = 1, .mistConfigIndex = 2},          // 2
    {"ZigStar LAN", .ethConfigIndex = 1, .zbConfigIndex = 1, .mistConfigIndex = 0},      // 3
    {"LilyZig", .ethConfigIndex = 2, .zbConfigIndex = 0, .mistConfigIndex = 4},          // 4
    {"Olizig", .ethConfigIndex = 0, .zbConfigIndex = 0, .mistConfigIndex = 0},           // 5
    {"China-GW", .ethConfigIndex = 0, .zbConfigIndex = 2, .mistConfigIndex = 0},         // 6
    {"TubesZB-eth", .ethConfigIndex = 1, .zbConfigIndex = 1, .mistConfigIndex = 0},      // 7
    {"TubesZB-eth_usb", .ethConfigIndex = 1, .zbConfigIndex = 3, .mistConfigIndex = 0},  // 8
    {"TubesZB-poe", .ethConfigIndex = 0, .zbConfigIndex = 4, .mistConfigIndex = 0},      // 9
    {"TubesZB-poe-2022", .ethConfigIndex = 0, .zbConfigIndex = 5, .mistConfigIndex = 0}, // 10
    {"TubesZB-poe-2023", .ethConfigIndex = 0, .zbConfigIndex = 6, .mistConfigIndex = 0}, // 11
    {"CZC-1.0", .ethConfigIndex = 2, .zbConfigIndex = 0, .mistConfigIndex = 1},          // 12
    {"HG POE Plus", .ethConfigIndex = 2, .zbConfigIndex = 0, .mistConfigIndex = 1},      // 13
};
