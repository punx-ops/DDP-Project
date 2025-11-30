#ifndef UTILITIES_H
#define UTILITIES_H

// Clears the input buffer
void clear_buffer();

// Pauses execution
void wait_for_enter();

// Clears the terminal screen
void clear_screen();

// scanf Integer
int get_valid_int(const char* prompt);

// Scanf Float
float get_valid_float(const char* prompt);

// Fgets String
void get_valid_string(const char* prompt, char* buffer, int size);

#endif