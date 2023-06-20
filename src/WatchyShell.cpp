#include "WatchyShell.h"

#define DARK_MODE true           // Black background (true), white background (false)
#define TIME_DISPLAY_24_HR false // 24-hour time (true), 12-hour time with am/pm (false)
#define NUM_BATT_SEGMENTS 19     // Number of '#' segments displayed at the bottom of the screen
#define MAX_BATT_V 4.2           // Approximate voltage of fully charged battery
#define MIN_BATT_V 3.2           // Approximate voltage of fully discharged battery

void WatchyShell::drawWatchFace() {
    display.fillScreen(DARK_MODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARK_MODE ? GxEPD_WHITE : GxEPD_BLACK);
    drawTime();
    drawDate();
    drawBattery();
}

void WatchyShell::drawTime() {
    // Draw time prompt
    display.setFont(&FiraCode_Regular8pt7b);
    display.setCursor(8, 20);
    if (TIME_DISPLAY_24_HR) {
        display.println("~$ date +\"%H:%M %p\"");
    } else {
        display.println("~$ date +\"%I:%M %p\"");
    }
    // Draw time
    display.setFont(&FiraCode_SemiBold28pt7b);
    display.setCursor(8, 80);
    int8_t hour = (TIME_DISPLAY_24_HR) ? currentTime.Hour : ((currentTime.Hour + 11) % 12) + 1;
    display.print(hour);
    display.print(":");
    if (currentTime.Minute < 10) {
        display.print(0);
    }
    display.print(currentTime.Minute);
    if (!TIME_DISPLAY_24_HR) {
        display.setFont(&FiraCode_Light8pt7b);
        if (currentTime.Hour < 12) {
            display.print("AM");
        } else {
            display.print("PM");
        }
    }
    display.println();
}

void WatchyShell::drawDate() {
    // Draw date prompt
    display.setFont(&FiraCode_Light8pt7b);
    display.setCursor(8, 110);
    display.println("~$ date +\"%a, %b %d\"");
    // Draw date
    display.setFont(&FiraCode_Regular14pt7b);
    display.setCursor(8, 150);
    String month = monthShortStr(currentTime.Month);
    String weekday = dayShortStr(currentTime.Wday);
    display.print(weekday + ", " + month + " ");
    if (currentTime.Day < 10) {
        display.print(0);
    }
    display.print(currentTime.Day);
    display.println();
}

void WatchyShell::drawBattery() {
    // Draw battery segments
    display.setFont(&FiraCode_Regular8pt7b);
    display.setCursor(4, 190);
    display.print("[");
    float batteryPercentage = (getBatteryVoltage() - MIN_BATT_V) / (MAX_BATT_V - MIN_BATT_V);
    int8_t batteryLevel = (int8_t) (batteryPercentage * NUM_BATT_SEGMENTS);
    batteryLevel = std::min(batteryLevel, (int8_t) NUM_BATT_SEGMENTS);
    for (int8_t i = 0; i < batteryLevel; ++i) {
        display.print("#");
    }
    for (int8_t i = batteryLevel; i < NUM_BATT_SEGMENTS; ++i) {
        display.print(".");
    }
    display.println("]");
}
