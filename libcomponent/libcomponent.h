/*
 * Description: Component which calculates which 3 series connected resistors in
 *              the E12 series which closest replaces the desired resistance.
 *******************************************************************************
 * Course:      Linux Development Environment (Spring 2019)
 * Assignment:  6, libraries
 * Author:      Jonas Sjödin
 * Date:        February 2019
 */

#ifndef LIBCOMPONENT_H_
#define LIBCOMPONENT_H_

int e_resistance(float orig_resistance, float *res_array);

#endif // LIBCOMPONENT_H_

