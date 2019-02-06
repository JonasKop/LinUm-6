/*
 * Linux som utvecklingsmiljö
 * Övning 6. Bibliotek
 * VT2019
 * David Sandquist
 */

#include <stdio.h>

/* Calculates effect as P=U^2/R */
float calc_power_r(float volt, float resistance){
	return (volt*volt)/resistance;
}

/* Calculates effect as P=U*I */
float calc_power_i(float volt, float current){
	return volt*current;
}
