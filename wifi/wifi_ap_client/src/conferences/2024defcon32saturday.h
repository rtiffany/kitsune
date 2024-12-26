// Bash to generate MAC address
// Note: least significant bit of first byte must be zero, here it's fixed to 0xF2
// printf '0xF2, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n' $[RANDOM%256] $[RANDOM%256] $[RANDOM%256] $[RANDOM%256] $[RANDOM%256]

//WIFI_POWER_19_5dBm 78
//WIFI_POWER_19dBm 76
//WIFI_POWER_18_5dBm 74
//WIFI_POWER_17dBm 68
//WIFI_POWER_15dBm 60
//WIFI_POWER_13dBm 52
//WIFI_POWER_11dBm 44
//WIFI_POWER_8_5dBm 34
//WIFI_POWER_7dBm 28
//WIFI_POWER_5dBm 20
//WIFI_POWER_2dBm 8
//WIFI_POWER_MINUS_1dBm -4

#if defined(EASY_AP)
#define AP
// set mac address
#define MAC_ADDR {0xF2, 0x75, 0x47, 0xFC, 0x51, 0x5A}
// Network config
#define FSSID "Isis"
#define PSK "k38cjh2lsdjelzi3i"
// 1-13 permitted 0 means random
#define CHANNEL 1
// 0 broadcast 1 hidden
#define SSID_HIDDEN  0
// 1-4 permitted
#define MAX_CLIENTS 1
#define TIME_TO_WAKE 15
#define TIME_TO_SLEEP 5
// checks run during startup so we want to stay
// running no longer than a few minutes to force
// checks to run and led to update
#define TXPOWER WIFI_POWER_17dBm
#endif

#if defined(HARD_AP)
#define AP
// set mac address
#define MAC_ADDR {0xF2, 0xCE, 0xF0, 0xAF, 0x0C, 0x55}
// Network config
#define FSSID "Ba'al"
#define PSK "k38cjh2lsdjelzi3i"
// 1-13 permitted 0 means random
#define CHANNEL 0
// 0 broadcast 1 hidden
#define SSID_HIDDEN 0
// 1-4 permitted
#define MAX_CLIENTS 1
// checks run during startup so we want to stay
// running no longer than a few minutes to force
// checks to run and led to update
#define TIME_TO_WAKE 30
#define TIME_TO_SLEEP 45
#define TXPOWER WIFI_POWER_7dBm
#endif

#if defined(EASY_CLIENT)
#define CLIENT
// set mac address
#define MAC_ADDR {0xF2, 0xB3, 0x3C, 0xB5, 0xCD, 0xAA}
// Network config
#define FSSID "WiFi Client Easy"
#define PSK "0z83lk4jah1oplqw"
// checks run during startup so we want to stay
// running no longer than a few minutes to force
// checks to run and led to update
#define TIME_TO_WAKE 300
#define TIME_TO_SLEEP 1
#define TXPOWER WIFI_POWER_17dBm
#endif

#if defined(HARD_CLIENT)
#define CLIENT
// set mac address
#define MAC_ADDR {0xF2, 0x36, 0x6A, 0xE8, 0xA5, 0x4A}
// Network config
#define FSSID "WiFi Client Hard"
#define PSK "0z83lk4jah1oplqw"
// checks run during startup so we want to stay
// running no longer than a few minutes to force
// checks to run and led to update
#define TIME_TO_WAKE 300
#define TIME_TO_SLEEP 0
#define TXPOWER WIFI_POWER_17dBm
#endif
