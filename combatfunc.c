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

creature getMonster() {
    int rand_num = (rand() % MONSTERS) + 1;
    //creature enemy;
    //massive fucking switch case to pick monster. VERY EFFICENT!!!!!!
    switch(rand_num){
        case 1: creature slime = { .hlth = 20, .mana = 0, .strn = 1, .def = 1, .spd = 1, .wis = 0, .intl = 0, .name = "slime"};
                return slime;
                break;
        case 2: creature bear = { .hlth = 10, .mana = 0, .strn = 5, .def = 5, .spd = 1, .wis = 0, .intl = 0, .name = "bear"};
                return bear;
                break;
        case 3: creature zomb = { .hlth = 15, .mana = 0, .strn = 4, .def = 2, .spd = 1, .wis = 0, .intl = 0, .name = "zombie"};
                return zomb;
                break;
    }

}

void funcStatusCheck(int playerHealth){
    printf("Current Health: %d\n", playerHealth);
    //TODO: Add additional spells/mana/equipment here
}

int getAction(creature player) {
    int actionNum = 0;
    //print action statement
    do{
    printf("Actions:\n 1. Attack\n 2. Cast Heal\n 3. Do Nothing\n 4. See Status\n -----> ");
    scanf(" %d", &actionNum);
    if(actionNum == 4){
        funcStatusCheck(player.hlth);
    }
    }while(actionNum > 3 || actionNum < 1);
    return actionNum;
}

void gameIntro(){
    for(int i = 0; i < 20; i++){
        printf("%c", 176); // light block
    }
    printf("\n");
    for(int i = 0; i < 20; i++){
        printf("%c", 177); // medium block
    }
    printf("\n");
    for(int i = 0; i < 20; i++){
        printf("%c", 178); // darker block
    }
    printf("\n");
    printf("You embark upon a deep dungeon,\n seeking fame and glory,\n and decide to Dive Deeper.\n");
}

void gameOutro(){
    printf("You feel the life leave your body\n without seeing the sun again\n YOU HAVE DIED\n");
    for(int i = 0; i < 20; i++){
        printf("%c", 178); // darker block
    }
    printf("\n");
    for(int i = 0; i < 20; i++){
        printf("%c", 177); // medium block
    }
    printf("\n");
    for(int i = 0; i < 20; i++){
        printf("%c", 176); // light block
    }
    printf("\n");
}