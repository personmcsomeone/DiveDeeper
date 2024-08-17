//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>
//self defined headers
#include "combatfunc.h"
#define MONSTERS 3
/*typedef struct{
    int hlth; //health
    int mana; //total mana
    int strn; //strength
    int def; //defence stat
    int spd; //speed stat
    int wis; //wisdom stat
    int intl; //intellegence stat
    char* name; //creature name
} creature;*/

void funcStatusCheck(int playerHealth){
    printf("Current Health: %d\n", playerHealth);
    //TODO: Add additional spells/mana/equipment here
}


void gameIntro(){
    for(int i = 0; i < 40; i++){
        printf("%c", 176); // light block
    }
    printf("\n");
    for(int i = 0; i < 40; i++){
        printf("%c", 177); // medium block
    }
    printf("\n");
    for(int i = 0; i < 40; i++){
        printf("%c", 178); // darker block
    }
    printf("\n");
    printf("You embark upon a deep dungeon,\n seeking fame and glory,\n and decide to Dive Deeper.\n");
}

void gameOutro(){
    printf("\nYou feel the life leave your body\n without seeing the sun again\n\n            YOU HAVE DIED\n\n");
    for(int i = 0; i < 40; i++){
        printf("%c", 178); // darker block
    }
    printf("\n");
    for(int i = 0; i < 40; i++){
        printf("%c", 177); // medium block
    }
    printf("\n");
    for(int i = 0; i < 40; i++){
        printf("%c", 176); // light block
    }
    printf("\n");
}

void monsterEncounter( int level, char* name){
    printf("You encounter a %s on level %d\n", name, level );
}