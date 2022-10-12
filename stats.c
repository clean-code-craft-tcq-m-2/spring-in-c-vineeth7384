#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    setlength = 0;
    numberset = NULL;
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
