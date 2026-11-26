#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct character {
    // Attributes
    int STR;
    int DEX;
    int CON;
    int INT;
    int WIS;
    int CHA;
};

void rollAttributes(struct character *);
int roll(int, int);
void characterSheet(struct character *);

int main(void) {
    srand(time(NULL));
    struct character PC1; //player character 1
    struct character *pPC1 = &PC1;
    // roll 3d6 for each attribute score
    rollAttributes(pPC1);
    characterSheet(pPC1);
    return 0;
}

int roll(int rolls, int die) {
    int sum = 0;
    for (int i = 0; i < rolls; i++) {
        sum += (rand() % die) +1;
    }
    return sum;
}

void rollAttributes(struct character *PC) {
    printf("Rolling Attributes\n");
    PC->STR = roll(3, 6);
    PC->DEX = roll(3, 6);
    PC->CON = roll(3, 6);
    PC->INT = roll(3, 6);
    PC->WIS = roll(3, 6);
    PC->CHA = roll(3, 6);
}

void characterSheet(struct character *PC) {
    printf("Character Sheet\n");
    printf("STR = %d\n", PC->STR);
    printf("DEX = %d\n", PC->DEX);
    printf("CON = %d\n", PC->CON);
    printf("INT = %d\n", PC->INT);
    printf("WIS = %d\n", PC->WIS);
    printf("CHA = %d\n", PC->CHA);
}
