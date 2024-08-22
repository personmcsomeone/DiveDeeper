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
#define MONSTERS 10

creature getMonster() {
    int rand_num = (rand() % MONSTERS) + 1;
    //creature enemy;
    //massive fucking switch case to pick monster. VERY EFFICENT!!!!!!
    switch(rand_num){
        case 1: creature gslime = { .hlth = 15, .mana = 0, .strn = 1, .def = 3, .spd = 2, .wis = 1, .intl = 0, .name = "green slime"};
                return gslime;
                break;
        case 2: creature bear = { .hlth = 10, .mana = 0, .strn = 5, .def = 5, .spd = 1, .wis = 0, .intl = 0, .name = "bear"};
                return bear;
                break;
        case 3: creature zomb = { .hlth = 15, .mana = 0, .strn = 4, .def = 2, .spd = 1, .wis = 0, .intl = 0, .name = "zombie"};
                return zomb;
                break;
        case 4: creature vamp = { .hlth = 10, .mana = 20, .strn = 4, .def = 0, .spd = 3, .wis = 5, .intl = 5, .name = "vampire"};
                return vamp;
                break;
        case 5: creature rat = { .hlth = 20, .mana = 0, .strn = 2, .def = 4, .spd = 1, .wis = 0, .intl = 0, .name = "large rat"};
                return rat;
                break;
        case 6: creature mage = { .hlth = 10, .mana = 50, .strn = 1, .def = 1, .spd = 1, .wis = 0, .intl = 0, .name = "rogue mage"};
                return mage;
                break;
        case 7: creature theif = { .hlth = 9, .mana = 0, .strn = 2, .def = 0, .spd = 8, .wis = 0, .intl = 0, .name = "theif"};
                return theif;
                break;
        case 8: creature skel = { .hlth = 15, .mana = 0, .strn = 8, .def = 1, .spd = 3, .wis = 0, .intl = 0, .name = "skel"};
                return skel;
                break;
        case 9: creature bslime = { .hlth = 12, .mana = 0, .strn = 3, .def = 1, .spd = 2, .wis = 5, .intl = 5, .name = "blue slime"};
                return bslime;
                break;
        case 10: creature feral = { .hlth = 5, .mana = 0, .strn = 7, .def = 0, .spd = 7, .wis = 0, .intl = 0, .name = "feral hog"};
                return feral;
                break;
    }
}

creature resetPlayer() {
    creature player = { .hlth = MAX_HEALTH, .mana = 0, .strn = 3, .def = 3, .spd = 3, .wis = 3, .intl = 3, .name = "Player"};
    return player;
}

int getAction(creature player) {
    int actionNum = 0;
    //print action statement
    do{
    printf(" Actions:\n  1. Attack\n  2. Cast Heal\n  3. Do Nothing\n  4. See Status\n -----> ");
    scanf(" %d", &actionNum);
    if(actionNum == 4){
        funcStatusCheck(player);
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
    
    printf("  You survive another floor, choose how to level up:\n 1. Restore Health\n 2. Strength Up\n 3. Defense Up\n 4. Speed Up\n 5. Wisdom Up\n 6. Intellegence Up\n Input Selection (1-6): ");
    scanf(" %d", &input);

    switch(input){
        case 2:{
            player->strn += 1 + crit;
            printf("   You feel your muscles grow,\n+%d strength\n", 1 + crit);
            break;
        }
        case 3:{
            player->def += 1 + crit;
            printf("   You grow in fortitude,\n+%d defense\n", 1 + crit);
            break;
        }
        case 4:{
            player->spd += 1 + crit;
            printf("   You feel springier, ready to fight,\n+%d spped\n", 1 + crit);
            break;
        }
        case 5:{
            player->wis += 1 + crit;
            printf("   You understand the dungeon further,\n+%d wisdom\n", 1 + crit);
            break;
        }
        case 6:{
            player->intl += 1 + crit;
            printf("   You strategize for the next decent,\n+%d intellegence\n", 1 + crit);
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

void combatPhase(creature* enemy, creature* player){
    int firstActionPerformed = 0;
    while(1){
        //speed check
        if(player->spd >= enemy->spd){ //player faster
            goto PlayerAction;
        } else{
            goto EnemyAction;
        }

        //player actions TODO: allow for expanssion in switch case.
        PlayerAction:
        switch(getAction(*player)){
            case 1:{ //attack    
                if((rand() % (40 - enemy->spd + player->spd + 1)) == 0){
                    printf("You miss your attack!!!\n");
                    firstActionPerformed += 1;
                    goto StatusCheck;
                }
                int dmg = ((player->strn - (enemy->def / 3)) < 0) ? 0 : player->strn - (enemy->def / 3);
                printf("You deal %d damage. \n", dmg);
                enemy->hlth -= dmg;
                break;
                }
            case 2:{ //heal
                printf("You gain 2 health. \n");
                player->hlth += 2;   
                break;
                }
            case 3:{ //nothing
                break;
                }
            default:{
                goto PlayerAction; //misinput, restart loop
                }
        }
        firstActionPerformed += 1; //player
        goto StatusCheck;

        //enemy actions TODO: expand enemy potential actions
        EnemyAction:
        switch((rand() % 10)){
            case 1:{
                printf("The %s missed.\n", enemy->name);
                break;
            }
            default:{
                int dmg = ((enemy->strn - (player->def / 3)) < 0) ? 0 : enemy->strn - (player->def / 3);
                printf("The %s attacks for %d damage.\n", enemy->name, dmg);
                player->hlth -= dmg;
            }
        }   
        firstActionPerformed += 2;
        goto StatusCheck;

        //check for health and order of attacks
        StatusCheck:
        if(player->hlth <= 0 || enemy->hlth <= 0){
            break;  //someone is dead, get out of combat
        }
        switch(firstActionPerformed){
            case 1:{
                goto EnemyAction;
            }
            case 2:{
                goto PlayerAction;
            }
            case 3:{
                firstActionPerformed = 0;
                continue;
            }
        }
    }
}