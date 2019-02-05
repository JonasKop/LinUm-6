/**
 * @author David Sandquist
 * @file libpower.h
 * @brief libpower is used to calculate the power(P) current heating effect.
 * */

#ifndef libpower_H
#define LIBPOWER_H

float calc_power_r(float volt, float resistance);
float calc_power_i(float volt, float current);

#endif
