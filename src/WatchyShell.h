#ifndef WATCHY_SHELL_H
#define WATCHY_SHELL_H

#include <Watchy.h>
#include "fonts/FiraCode_Light8pt7b.h"
#include "fonts/FiraCode_Regular8pt7b.h"
#include "fonts/FiraCode_Regular14pt7b.h"
#include "fonts/FiraCode_SemiBold28pt7b.h"

class WatchyShell : public Watchy {
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        void drawTime();
        void drawDate();
        void drawBattery();
};

#endif
