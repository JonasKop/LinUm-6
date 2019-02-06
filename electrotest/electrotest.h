

#ifndef LINUM_ELECTROTEST_H
#define LINUM_ELECTROTEST_H


/**
 * Prompts the user with a string and gets user input which it saves to a
 * buffer which it takes as an argument.
 * @param str the string that should be printed
 * @param buf the buffer where the user input should be stored.
 */
void prompt(char *str, char *buf);

/**
 * Gets the input from the user and saves it to its parameters. If it cannot
 * be done it prints an error message and exits.
 *
 * @param vol pointer to where the voltage should be stored
 * @param type pointer to where the type should be stored
 * @param count pointer to where the nr of components should be stored
 * @param arr pointer to array where the components should be stored
 */
void get_input(float *vol, char *type, int *count, float *arr);

/**
 * Prints the result of the calculations
 *
 * @param res the resistance total
 * @param pow the power total
 * @param res_arr array containing the resistance of the resistors
 * @param res_arr_size the size of res_arr
 */
void print_result(float res, float pow, float *res_arr, int res_arr_size);

#endif //LINUM_ELECTROTEST_H

