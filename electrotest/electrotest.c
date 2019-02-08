/*
 * Description: Example run of three shared libraries
 *******************************************************************************
 * Course:      Linux Development Environment (Spring 2019)
 * Assignment:  6, libraries
 * Authors:     David Sandqvist, Jonas Sjödin, and Magnus Sjögren
 * Date:        February 2019
 */

#define BUFSIZE 64

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#include "../libresistance/libresistance.h"
#include "../libpower/libpower.h" 
#include "../libcomponent/libcomponent.h"

#include "electrotest.h"

void terror(char *str) {
    fprintf(stdout, "Error: %s\n", str);
    exit(1);
}

/**
 * Prompts the user with a string and gets user input which it saves to a
 * buffer which it takes as an argument.
 * @param str the string that should be printed
 * @param buf the buffer where the user input should be stored.
 */
void prompt(char *str, char *buf) {
    printf("%s", str);
    if (!fgets(buf, sizeof(buf), stdin)) {
        terror("Kunde inte läsa in data");
    }
}

/**
 * Gets the input from the user and saves it to its parameters. If it cannot
 * be done it prints an error message and exits.
 *
 * @param vol pointer to where the voltage should be stored
 * @param type pointer to where the type should be stored
 * @param count pointer to where the nr of components should be stored
 * @param arr pointer to array where the components should be stored
 */
void * get_input(float *vol, char *type, int *count, float *arr) {
    char buffer[BUFSIZE], *p;
    prompt("Ange spänningskälla i V: ", buffer);
    *vol = strtof(buffer, &p);
    if (*vol == 0 && (errno != 0 || p == buffer)) {
        terror("Spänningen måste vara ett tal");
    }

    prompt("Ange koppling[S | P]: ", buffer);
    if (strlen(buffer) != 2 || (buffer[0] != 'S' && buffer[0] != 's' && 
        buffer[0] != 'p' && buffer[0] != 'P')) {
        terror("Kopplingen måste vara S eller P");
    }
    *type = toupper(buffer[0]);

    prompt("Antal komponenter: ", buffer);
    *count = (int) strtol(buffer, &p, 10);
    if ((*count == 0 && (errno != 0 || p == buffer)) || *count < 0) {
        terror("Antal komponenter måste vara ett positivt heltal");
    }

    arr = malloc(sizeof(float) * (*count));
    if (arr == NULL) {
        terror("Kunde inte allokera minne");
    }
    for (int i = 0; i < *count; ++i) {
        printf("Komponent %d i ohm: ", i + 1);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            terror("Kunde inte läsa in data");
        }    
        arr[i] = strtof(buffer, &p);
        if (arr[i] == 0 && (errno != 0 || p == buffer)) {
            terror("Spänningen måste vara ett tal");
        }
    }

    return arr;

}

/**
 * Prints the result of the calculations
 *
 * @param res the resistance total
 * @param pow the power total
 * @param res_arr array containing the resistance of the resistors
 * @param res_arr_size the size of res_arr
 */
void print_result(float res, float pow, float *res_arr, int res_arr_size) {
    printf("Ersättningsresistans: %.1f ohm\n", res);
    printf("Effekt: %.2f W\n", pow);

    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
    for (int i = 0; i < res_arr_size; ++i) {
        printf("%.1f%s", res_arr[i], i != res_arr_size - 1 ? ", " : "\n");
    }
}

int main() {
    float vol, *arr = NULL;
    char type;
    int count;
    arr = get_input(&vol, &type, &count, arr);

    float res_arr[3];
    float res = calc_resistance(count, type, arr);
    float pow = calc_power_r(vol, res);
    int res_arr_size = e_resistance(res, res_arr);
    print_result(res, pow, res_arr, res_arr_size);

    free(arr);
    return 0;
}
