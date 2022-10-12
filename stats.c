#include "stats.h"
#include <math.h>
#ifdef NAN
/* NAN is supported */
#endif
#ifdef INFINITY
/* INFINITY is supported */
#endif


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
		s.min = s.average ;
		s.max = s.min;

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
