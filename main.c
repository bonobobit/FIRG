#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Attributes {STR, DEX, CON, INT, WIS, CHA};
const char *Attributes_name(enum Attributes value) {
    switch (value) {
        case STR:    return "STR";
        case DEX:    return "DEX";
        case CON:    return "CON";
        case INT:    return "INT";
        case WIS:    return "WIS";
        case CHA:    return "CHA";
        default:     return "Unknown";
    }
}

struct character {
    // Attributes
    int attributeScore[6];
    int attributeLevelModifier[6];
    int attributeModifier[6];
    int attributeCheckBonus[6];
    int level;
};

int roll(int, int);
void rollAttributeScore(struct character *);
void setAttributeLevelModifier(struct character *);
void setAttributeModifier(struct character *);
void setAttributeCheckBonus(struct character *);
void characterSheet(struct character *);

int main(void) {
    srand(time(NULL));
    struct character PC1; //player character 1
    struct character *pPC1 = &PC1;
    // roll 3d6 for each attribute score
    rollAttributeScore(pPC1);
    setAttributeLevelModifier(pPC1);
    setAttributeModifier(pPC1);
    setAttributeCheckBonus(pPC1);
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

void rollAttributeScore(struct character *PC) {
    printf("Rolling Attributes\n");
    PC->attributeScore[STR] = roll(3, 6);
    PC->attributeScore[DEX] = roll(3, 6);
    PC->attributeScore[CON] = roll(3, 6);
    PC->attributeScore[INT] = roll(3, 6);
    PC->attributeScore[WIS] = roll(3, 6);
    PC->attributeScore[CHA] = roll(3, 6);

}

void setAttributeLevelModifier(struct character *PC) {
    // assign level 1
    PC->level = 1; // to be put into its own function
    // assign primary and secondary attr. modifiers based on level
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
    for (int i = STR; i <= CHA; i++) {
        if (i == (attr1-1) || i == (attr2-1)) {
            PC->attributeLevelModifier[i] = PC->level;
        } else {
            PC->attributeLevelModifier[i] = (int)((PC->level)/2);
        }
    }
}

void setAttributeModifier(struct character *PC) {
    for (int a = STR; a <= CHA; a++) {
        switch (PC->attributeScore[a]) {
            case 1:
                PC->attributeModifier[a] = -4;
                break;
            case 2:
            case 3:
                PC->attributeModifier[a] = -3;
                break;
            case 4:
            case 5:
                PC->attributeModifier[a] = -2;
                break;
            case 6:
            case 7:
            case 8:
                PC->attributeModifier[a] = -1;
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                PC->attributeModifier[a] = 0;
                break;
            case 13:
            case 14:
            case 15:
                PC->attributeModifier[a] = 1;
                break;
            case 16:
            case 17:
                PC->attributeModifier[a] = 2;
            case 18:
                PC->attributeModifier[a] = 3;
        }
    }
}

void setAttributeCheckBonus(struct character *PC) {
    for (int a = STR; a <= CHA; a++) {
        PC->attributeCheckBonus[a] = PC->attributeModifier[a] + PC->attributeLevelModifier[a];
    }
}


void characterSheet(struct character *PC) {
    printf("Character Sheet\n");
    for (int a = STR; a <= CHA; a++) {
        printf("%s check bonus = %d = [mod: %d (score: %d)]+[level mod:%d]\n",Attributes_name(a), PC->attributeCheckBonus[a], PC->attributeModifier[a], PC->attributeScore[a], PC->attributeLevelModifier[a]);
    }
}
