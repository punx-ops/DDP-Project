#ifndef GAMEPLAY_H
#define GAMEPLAY_H

typedef struct {
    char name[50];
    int health;
    int energy;
    int money;
} Player;

void go_outside(Player *p);
void market_event(Player *p);

#endif