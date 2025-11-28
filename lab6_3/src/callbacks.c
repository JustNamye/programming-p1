#include <math.h>
#include "callbacks.h"

void for_positive(int from, int to, ActionInt act) {
    if (!act) return;
    if (from > to) return;

    for (int i = from; i <= to; i++)
    {
        if (i>0)
        {
            act(i);
        }
    }
        
    
}