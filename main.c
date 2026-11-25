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
int d6();
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

int d6() {
    return (rand() % 6) + 1;
}

void rollAttributes(struct character *PC) {
    printf("Rolling Attributes\n");
    PC->STR = d6()+d6()+d6();
    PC->DEX = d6()+d6()+d6();
    PC->CON = d6()+d6()+d6();
    PC->INT = d6()+d6()+d6();
    PC->WIS = d6()+d6()+d6();
    PC->CHA = d6()+d6()+d6();
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
