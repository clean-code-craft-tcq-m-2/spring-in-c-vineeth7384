#include "stats.h"
#include <cstddef>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    s.setlength = setlength;
    s.numberset = numberset;
    return s;
}
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{};

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
