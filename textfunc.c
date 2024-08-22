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

void funcStatusCheck(creature player){
    printf("\n");
    for(int i = 0; i < 60; i++){
        printf("%c", 177); // medium block
    }
    printf("\n%c%c%c%c",177,177,177,176);
    printf("Health:%02d", player.hlth);
    printf("%c", 176);
    printf("Mana:%02d", player.mana);
    printf("%c", 176);
    printf("STR:%02d", player.strn);
    printf("%c", 176);
    printf("DEF:%02d", player.def);
    printf("%c", 176);
    printf("SPD:%02d", player.spd);
    printf("%c", 176);
    printf("WIS:%02d", player.wis);
    printf("%c", 176);
    printf("INT:%02d", player.intl);
    printf("%c%c%c%c\n",176,177,177,177);
    for(int i = 0; i < 60; i++){
        printf("%c", 177); // medium block
    }
    printf("\n\n");  
    //TODO: Add additional spells/mana/equipment here
}

void gameIntro(){
    for(int i = 0; i < 60; i++){
        printf("%c", 176); // light block
    }
    printf("\n");
    for(int i = 0; i < 60; i++){
        printf("%c", 177); // medium block
    }
    printf("\n");
    for(int i = 0; i < 60; i++){
        printf("%c", 178); // darker block
    }
    printf("\n\n          You embark upon a deep dungeon,\n          seeking fame and glory,\n          and decide to Dive Deeper.\n\n");
    printf("  You step in and prepare to fihgt the first monster\n");
}

void gameOutro(){
    printf("\n\n          You feel the life leave your body\n          without seeing the sun again\n\n                  YOU HAVE DIED\n\n");
    for(int i = 0; i < 60; i++){
        printf("%c", 178); // darker block
    }
    printf("\n");
    for(int i = 0; i < 60; i++){
        printf("%c", 177); // medium block
    }
    printf("\n");
    for(int i = 0; i < 60; i++){
        printf("%c", 176); // light block
    }
    printf("\n");
}

void monsterEncounter( int level, char* name){
    printf("  You encounter a %s on level %d\n", name, level );
}

void displaySpells(creature player){
    for(int i = 0; i < 60; i++){
        printf("%c", 205); // double lines
    }
    printf("\n [ATTACK SPELLS] \n");
    if(player.intl >= 4 && player.strn >= 4){
        printf("01. Fireball   ");
    } else{
        printf("01. XXXXXXXX   ");
    }
    if(player.intl >= 5 ){
        printf("02. Magic Missle   ");
    } else{
        printf("02. XXXXXXXXXXXX   ");
    }
    if(player.intl >= 7 && player.strn >= 8){
        printf("03. Flaming Slash   ");
    } else{
        printf("03. XXXXXXXXXXXXX   ");
    }
////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n [DEFENSE SPELLS] \n");
    printf("11. Small Heal   ");
    if(player.intl >= 5 && player.def >= 5){
        printf("12. Shield Shroud   ");
    } else{
        printf("12. XXXXXXXXXXXXX   ");
    }
    if((player.intl >= 5 && player.def >= 5) && player.spd >= 4){
        printf("13. Stamina Boost   ");
    } else{
        printf("13. XXXXXXXXXXXXX   ");
    }
    if((player.intl >= 7 && player.def >= 10) && player.wis >= 5){
        printf("14. Unrelenting Power   ");
    } else{
        printf("14. XXXXXXXXXXXXXXXXX   ");
    }
////////////////////////////////////////////////////////////////////////////////////////////
    printf("\n [ARCANE SPELLS] \n");
    if(player.intl >= 4 && player.wis >= 4){
        printf("21. Mana Resolve   ");
    } else{
        printf("21. XXXXXXXXXXXX   ");
    }
    if(player.intl >= 8){
        printf("22. Lightning   ");
    } else{
        printf("22. XXXXXXXXX   ");
    }
    if(player.intl >= 8 && player.wis >= 8){
        printf("23. Spell Denial   ");
    } else{
        printf("23. XXXXXXXXXXXX   ");
    }

    printf("\n\n 00. Return to Menu\n");
}