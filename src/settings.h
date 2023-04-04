#ifndef SETTINGS_H
#define SETTINGS_H

// Weather settings
#define CITY_ID ""
#define OPENWEATHERMAP_APIKEY ""
#define OPENWEATHERMAP_URL ""
#define TEMP_UNIT "imperial"
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 60
// NTP settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * -8

watchySettings settings {
    .cityID = CITY_ID,
    .weatherAPIKey = OPENWEATHERMAP_APIKEY,
    .weatherURL = OPENWEATHERMAP_URL,
    .weatherUnit = TEMP_UNIT,
    .weatherLang = TEMP_LANG,
    .weatherUpdateInterval = WEATHER_UPDATE_INTERVAL,
    .ntpServer = NTP_SERVER,
    .gmtOffset = GMT_OFFSET_SEC,
};

#endif
