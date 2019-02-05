/*
 * Linux som utvecklingsmiljö
 * Övning 6. Bibliotek
 * VT2019
 * Magnus Sjögren
 */

#include <stdio.h>

#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
{
    int i;
    float result = 0;

    /* Check that arguments are valid */
    if ((count < 1) || ((conn != 'P') && (conn != 'S')) || (!array)) {
        return -1;
    }

    /* Serial attachment */
    if (conn == 'S') {
        for (i = 0; i < count; i++) {
            result += array[i];
        }
    /* Parallell attachment */
    } else {
        for (i = 0; i < count; i++) {
            if (array[i] == 0) {
                return 0;
            }
            result += (1 / array[i]);
        }
        result = (1 / result);
    }

    return result;

}
