#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void wait_for_enter() {
    printf("\n[Press Enter to continue...]");
    clear_buffer();
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int get_valid_int(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clear_buffer();
            return value;
        } else {
            printf("Invalid input. Please enter a number.\n");
            clear_buffer(); 
        }
    }
}

float get_valid_float(const char* prompt) {
    float value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &value) == 1) {
            clear_buffer();
            return value;
        } else {
            printf("Invalid input. Please enter a decimal.\n");
            clear_buffer();
        }
    }
}

void get_valid_string(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}