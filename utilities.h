#ifndef UTILITIES_H
#define UTILITIES_H

void clear_buffer();
void wait_for_enter();
void clear_screen();
int get_valid_int(const char* prompt);
float get_valid_float(const char* prompt);
void get_valid_string(const char* prompt, char* buffer, int size);

#endif