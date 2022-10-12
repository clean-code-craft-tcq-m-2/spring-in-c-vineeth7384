#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s {0,0,0};
     
    int i ;
    if (setlength > 0)
    {
       s.min = numberset[0];
       for (i = 0; i < setlength; i++)
	   {
			s.average += numberset[i];

			if (numberset[i] > s.max)
			{
				s.max = numberset[i];
			}

			if (numberset[i] < s.min)
			{
				s.min = numberset[i];
			}
		}

		 s.average /= setlength;
        
     }
    
    else
    {
                s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	        s.min = s.min+0;
	        s.max = s.max+0;
                s.average = s.average +0
    }
    
   
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alert_array[],Stats computedStats)
{
	if (computedStats.max > maxThreshold)
	{
		alert_array[0]();
		alert_array[1]();
	}
}


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
