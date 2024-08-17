//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>
//self defined headers
#include "combatfunc.h"
#include "textfunc.h"
//current numbers of monsters in the game UPDATE!!!
#define MONSTERS 3

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

void levelUp(creature* player){
    int input = 0;
    int crit = 0;
    if((rand() % 35) == 0){
        crit = 2;
    } 
    else{ 
        crit = 0;
    }
    printf("str %d\n", player->strn);
    printf("You survive another floor, choose how to level up:\n 1. Restore Health\n 2. Strength Up\n 3. Defense Up\n 4. Speed Up\n 5. Wisdom Up\n 6. Intellegence Up\n Input Selection (1-6): ");
    scanf(" %d", &input);

    switch(input){
        case 2:{
            player->strn += 1 + crit;
            printf("You feel your muscles grow,\n+%d strength\n", 1 + crit);
            break;
        }
        case 3:{
            player->def += 1 + crit;
            printf("You grow in fortitude,\n+%d defense\n", 1 + crit);
            break;
        }
        case 4:{
            player->spd += 1 + crit;
            printf("You feel springier, ready to fight,\n+%d spped\n", 1 + crit);
            break;
        }
        case 5:{
            player->wis += 1 + crit;
            printf("You understand the dungeon further,\n+%d wisdom\n", 1 + crit);
            break;
        }
        case 6:{
            player->intl += 1 + crit;
            printf("You strategize for the next decent,\n+%d intellegence\n", 1 + crit);
            break;
        }
        default:{
            // " error: lvalue required as left operand of assignment"
            //(((player->hlth + 15) >= 30 )? player->hlth = 30 : (player->hlth) = (player->hlth) + 15);
            //temp fix, full health for all!
            player->hlth = 30;
            printf("You take a small rest and clean your wounds\n");
        }
    }
    //free(lvlup);
}