#include <stdio.h>
#include "utilities.h"

int main() {
    // --- STATE VARIABLES ---
    char name[50];
    int health = 100;
    int energy = 100;
    int money = 0;
    int choice;

    // --- SETUP ---
    clear_screen();
    get_valid_string("Enter your character's name: ", name, sizeof(name));
    
    printf("Welcome, %s.\n", name);
    wait_for_enter();

    // --- GAME LOOP ---
    while (1) {
        clear_screen();

        // HUD
        printf("========================================\n");
        printf("PLAYER: %s | HP: %d | ENERGY: %d | $: %d\n", name, health, energy, money);
        printf("========================================\n");
        printf("You are at home.\n\n");

        printf("1. Clean House (-20 Energy)\n");
        printf("2. Go Outside\n");
        printf("3. Sleep (Restore Energy)\n");
        printf("0. Quit\n");

        choice = get_valid_int(">> ");

        switch (choice) {
            case 1: // Clean
                if (energy >= 20) {
                    printf("You cleaned the house.\n");
                    energy -= 20;
                } else {
                    printf("Too tired.\n");
                }
                wait_for_enter();
                break;

            case 2: // Outside
                printf("You step outside... (feature coming soon)\n");
                wait_for_enter();
                break;

            case 3: // Sleep
                printf("Zzz... Energy restored.\n");
                energy = 100;
                wait_for_enter();
                break;

            case 0: // Quit
                printf("Goodbye.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                wait_for_enter();
        }
    }
    return 0;
}