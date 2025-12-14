#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "gameplay.h"

void go_outside(Player *p) {
    int choice;
    int earned;

    while (1) {
        if (p->health <= 0) return;
        clear_screen();
        printf("========================================\n");
        printf("PLAYER: %s | HP: %d | ENERGY: %d | $: %d\n", p->name, p->health, p->energy, p->money);
        printf("========================================\n");
        printf("You Are Outside!\n\n");

        printf("1. Work at Construction Site (+$$$, -20 Energy)\n");
        printf("2. Go to Gym (+20 HP, -40 Energy)\n");
        printf("3. Go to Market (Coming Soon)\n");
        printf("4. Go To Park (-20 Energy)\n");
        printf("0. Return Home\n");

        choice = get_valid_int(">> ");

        switch (choice) {
            case 1:
                if (p->energy >= 20) {
                    earned = rand() % 31 + 20; 
                    p->money += earned;
                    p->energy -= 20;
                    if ((rand() % 100) < 20) {
                        int damage = rand() % 11 + 10;
                        p->health -= damage;
                        printf("\n[!] ACCIDENT AT WORK!\n");
                        printf("You got some trouble while at work.\n");
                        printf("You earned $%d, but took %d damage!\n", earned, damage);
                        if (p->health < 0) p->health = 0;
                    } else {
                    printf("\nYou worked hard carrying bricks.\n");
                    printf("You earned $%d!\n", earned);
                    }
                    p->money += earned;
                } else {
                    printf("\nYou are too exhausted to work! Go home and sleep.\n");
                }
                wait_for_enter();
                break;

            case 2:
                if (p->energy >= 40) {
                    p->health += 20;
                    if (p->health > 100) 
                    p->health = 100; 
                    p->energy -= 40;
                    printf("\nYou lifted heavy weights. You feel stronger!\n");
                } else {
                    printf("\nYou are too weak to lift. Eat or sleep first.\n");
                }
                wait_for_enter();
                break;

            case 3:
                printf("\nOngoing to the market...\n");
                wait_for_enter();
                market_event(p);
                break;

            case 4:
                if (p->energy >= 20) {
                    p->energy -= 20;
                    printf("\nYou had a relaxing time at the park. Your mood improves!\n");
                } else {
                    printf("\nYou are too tired to enjoy the park. Rest first.\n");
                }
                wait_for_enter();
                break;
            case 0:
                return;

            default:
                printf("Invalid choice.\n");
                wait_for_enter();
        }
    }
}
void market_event(Player *p) {
    int choice;

    while(1){
        clear_screen();
        printf("========================================\n");
        printf("PLAYER: %s | HP: %d | ENERGY: %d | $: %d\n", p->name, p->health, p->energy, p->money);
        printf("========================================\n");
        printf("Welcome to the Market!\n\n");
        printf("Please Buy Something You Need!\n");
        printf("1. Bandage ($30) - Restores 50 HP\n");
        printf("2. Energy Drink ($20) - Restores 50 Energy\n");
        printf("3. Snack ($10) - Restores 20 Energy\n");
        printf("4. Souvenir ($15) - Accesories\n");
        printf("5. Lucky Charm ($25) - Accesories\n");
        printf("6. Fresh Fruit ($5) - Restores 10 HP and 5 Energy\n");
        printf("0. Exit Market\n");

        choice = get_valid_int(">> ");

        switch (choice) {
            case 1:
                if (p->money >= 30) {
                    p->money -= 30;
                    p->health += 50;
                    if (p->health > 100) p->health = 100;
                    printf("\nYou applied the bandage. Health restored!\n");
                } else {
                    printf("\nYou are too poor! Need $30.\n");
                }
                wait_for_enter();
                break;

            case 2:
                if (p->money >= 20) {
                    p->money -= 20;
                    p->energy += 50;
                    if (p->energy > 100) p->energy = 100;
                    printf("\nYou chugged the drink. You feel buzzed!\n");
                } else {
                    printf("\nYou can't afford that. Need $20.\n");
                }
                wait_for_enter();
                break;

            case 3:
                if (p->money >= 10) {
                    p->money -= 10;
                    p->energy += 20;
                    if (p->energy > 100) p->energy = 100;
                    printf("\nYum. Tasty.\n");
                } else {
                    printf("\nYou can't afford that. Need $10.\n");
                }
                wait_for_enter();
                break;

            case 4:
                if (p->money >= 15) {
                    p->money -= 15;
                    printf("\nYou bought a souvenir. It does absolutely nothing.\n");
                    printf("But it looks cool.\n");
                } else {
                    printf("\nYou can't afford that. Need $15.\n");
                }
                wait_for_enter();
                break;

            case 5:
                if (p->money >= 25) {
                    p->money -= 25;
                    printf("\nYou feel luckier... maybe? (No stat change)\n");
                } else {
                    printf("\nYou can't afford that. Need $25.\n");
                }
                wait_for_enter();
                break;

            case 6:
                if (p->money >= 5) {
                    p->money -= 5;
                    p->health += 10;
                    p->energy += 5;
                    if (p->health > 100) p->health = 100;
                    if (p->energy > 100) p->energy = 100;
                    printf("\nFresh and healthy!\n");
                } else {
                    printf("\nBELI BUAH JA GABISA?! AOWKOAWKOKAWOKAWWOKA MISKIN LI JIR!!!\n");
                }
                wait_for_enter();
                break;

            case 0:
                printf("\nThank you! And don't forget to comeback ya?\n");
                wait_for_enter();
                return;

            default:
                printf("\nWe don't sell that here.\n");
        }
    }
}