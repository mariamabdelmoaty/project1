#include "00_lib/std_types.h"
#include "00_lib/bit_math.h"
#include "03_app/app_interface.h"

int main(void)
{
    /* System Initialization */
    APP_vInit();

    while(1)
    {
        /* Main System Super-Loop */
        APP_vUpdateSystem();
    }

    return 0;
}