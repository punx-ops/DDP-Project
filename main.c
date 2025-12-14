#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "gameplay.h"

int main() {
    Player hero;
    hero.health = 100;
    hero.energy = 100;
    hero.money = 50;
    int choice;

    //SETUP
    clear_screen();
    get_valid_string("Enter your character's name: ", hero.name, sizeof(hero.name));
    
    printf("Welcome, %s.\n", hero.name);
    wait_for_enter();

    //GAMEPLAY
    while (1) {
        if (hero.health <= 0) break;
        clear_screen();
        printf("========================================\n");
        printf("PLAYER: %s | HP: %d | ENERGY: %d | $: %d\n", hero.name, hero.health, hero.energy, hero.money);
        printf("========================================\n");
        printf("You are at home!\n\n");

        printf("1. Clean House (-20 Energy)\n");
        printf("2. Go Outside\n");
        printf("3. Sleep (Restore Energy)\n");
        printf("0. Quit\n");

        choice = get_valid_int(">> ");

        switch (choice) {
            case 1:
                if (hero.energy >= 20) {
                    printf("You cleaned the house.\n");
                    hero.energy -= 20;
                } else {
                    printf("Too tired.\n");
                }
                wait_for_enter();
                break;

            case 2:
                printf("You step outside...\n");
                wait_for_enter();
                go_outside(&hero);
                break;

            case 3:
                printf("Zzz... Energy restored.\n");
                hero.energy = 100;
                wait_for_enter();
                break;

            case 0:
                printf("Goodbye.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                wait_for_enter();
        }
    }
    clear_screen();
    printf("\n\n");
    printf("########################################\n");
    printf("#              YOU DIED                #\n");
    printf("########################################\n");
    printf("\n");
    printf("Rest in Peace, %s.\n", hero.name);
    printf("You died with $%d in your pocket.\n", hero.money);
    printf("\n");
    printf("GAME OVER\n");
    return 0;
}
