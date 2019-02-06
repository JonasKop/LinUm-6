/*
 * Description: Component which calculates which 3 series connected resistors in
 *              the E12 series which closest replaces the desired resistance.
 *******************************************************************************
 * Course:      Linux Development Environment (Spring 2019)
 * Assignment:  6, libraries
 * Author:      Jonas Sjödin
 * Date:        February 2019
 */

#include <stdio.h>
#include <stdlib.h>

#include "libcomponent.h"

int e_resistance(float orig_resistance, float *res_array) {
    float values[] = {1, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2},
            left_val = orig_resistance;

    int i;
    for (i = 0; i < 3; i++) {
        float size = 1, next_size = 10;
        while (1) {
            if ((size < left_val && left_val < next_size) || size == left_val) {
                break;
            }
            size = next_size;
            next_size *= 10;
        }
        int j;
        for (j = 0; j < 12; j++) {
            if (left_val < values[j] * size) {
                break;
            }
        }
        res_array[i] = size * values[j - 1];
        left_val -= res_array[i];
        if (left_val < 1) {
            break;
        }
    }
    return i;
}
