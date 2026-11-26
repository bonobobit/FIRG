#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Attributes {STR, DEX, CON, INT, WIS, CHA};
enum AttributeLevelModifiers {PRI = 2, SEC = 1};

struct character {
    // Attributes
    int baseAttribute[6];
    int attributeLevelModifier[6];
    int attribute[6];
};

void rollAttributes(struct character *);
int roll(int, int);
void characterSheet(struct character *);
void setPrimSec(struct character *);
void calcAttributes(struct character *);

int main(void) {
    srand(time(NULL));
    struct character PC1; //player character 1
    struct character *pPC1 = &PC1;
    // roll 3d6 for each attribute score
    rollAttributes(pPC1);
    setPrimSec(pPC1);
    calcAttributes(pPC1);
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
    PC->baseAttribute[STR] = roll(3, 6);
    PC->baseAttribute[DEX] = roll(3, 6);
    PC->baseAttribute[CON] = roll(3, 6);
    PC->baseAttribute[INT] = roll(3, 6);
    PC->baseAttribute[WIS] = roll(3, 6);
    PC->baseAttribute[CHA] = roll(3, 6);

}

void setPrimSec(struct character *PC) {
    printf("Choose primary attributes,\n");
    printf("STR = %d\n", STR);
    printf("DEX = %d\n", DEX);
    printf("CON = %d\n", CON);
    printf("INT = %d\n", INT);
    printf("WIS = %d\n", WIS);
    printf("CHA = %d\n", CHA);
    printf("e.g.: choosing \"1 2\" selects STR & DEX: ");
    int attr1 = 0, attr2 = 0;
    scanf("%d %d", &attr1, &attr2);
}

void calcAttributes(struct character *PC) {
    for (int a = STR; a <= CHA; a++) {
        PC->attribute[a] = PC->baseAttribute[a] + PC->attributeLevelModifier[a];
    }
}


void characterSheet(struct character *PC) {
    printf("Character Sheet\n");
    printf("STR = %d (+%d)\n", PC->attribute[STR], PC->attributeLevelModifier[STR]);
    printf("DEX = %d (+%d)\n", PC->attribute[DEX], PC->attributeLevelModifier[DEX]);
    printf("CON = %d (+%d)\n", PC->attribute[CON], PC->attributeLevelModifier[CON]);
    printf("INT = %d (%d)\n", PC->attribute[INT], PC->attributeLevelModifier[INT]);
    printf("WIS = %d %d\n", PC->attribute[WIS], PC->attributeLevelModifier[WIS]);
    printf("CHA %d %d\n", PC->attribute[CHA], PC->attributeLevelModifier[CHA]);
}

# need to implement level