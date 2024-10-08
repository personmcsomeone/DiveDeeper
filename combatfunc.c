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
        case 5: creature rat = { .hlth = 10, .mana = 0, .strn = 2, .def = 4, .spd = 1, .wis = 0, .intl = 0, .name = "large rat"};
                return rat;
                break;
        case 6: creature mage = { .hlth = 10, .mana = 50, .strn = 1, .def = 1, .spd = 1, .wis = 0, .intl = 0, .name = "rogue mage"};
                return mage;
                break;
        case 7: creature theif = { .hlth = 9, .mana = 0, .strn = 2, .def = 0, .spd = 8, .wis = 0, .intl = 0, .name = "theif"};
                return theif;
                break;
        case 8: creature skel = { .hlth = 15, .mana = 0, .strn = 8, .def = 1, .spd = 3, .wis = 0, .intl = 0, .name = "skeleton"};
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
    creature player = { .hlth = 30, .mana = 0, .strn = 3, .def = 3, .spd = 3, .wis = 3, .intl = 3, .name = "Player"};
    return player;
}

creature copyPlayer(creature orig) {
    creature copy = { .hlth = orig.hlth, .mana = orig.mana, .strn = orig.strn, .def = orig.def, .spd = orig.spd, .wis = orig.wis, .intl = orig.intl, .name = orig.name};
    return copy;
}

int getAction(creature player) {
    int actionNum = 0;
    //print action statement
    do{
    printf(" Actions:\n  1. Attack\n  2. Cast Spell\n  3. Do Nothing\n  4. See Status\n -----> ");
    scanf(" %d", &actionNum);
    if(actionNum == 4){
        funcStatusCheck(player);
    }
    }while(actionNum > 3 || actionNum < 1);
    //cool spacing
    for(int i = 0; i < 60; i++){
        printf("%c", 176); // light block
    }
    printf("\n\n");
    return actionNum;
}
/*
int getSpell(creature player) {
    int actionNum = 0;
    //print action statement
    do{
        printf(" Choose Spell to Cast ----> ");
        scanf(" %d", &actionNum);
        
        //return to menu input
        if(actionNum == 0){
            break;
        }

        //spell input
        switch(actionNum){
            case 1:{ //fireball
                if(!(player.intl >= 4 && player.strn >= 4)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 11:{ //small heal
                break;
            }
            case 12:{ //shield shroud
                if(!(player.intl >= 5 && player.def >= 5)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 2:{ //magic missle
                if(!(player.intl >= 5)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 13:{ //stamina boost
                if(!((player.intl >= 5 && player.def >= 5) && player.spd >= 4)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 3:{ //flaming slash
                if(!(player.intl >= 7 && player.strn >= 8)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 14:{ //unrelent power
                if(!((player.intl >= 7 && player.def >= 10) && player.wis >= 5)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 22:{ //lightning
                if(!(player.intl >= 8)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            case 23:{ //spell denial
                if(!(player.intl >= 8 && player.wis >= 8)){
                    actionNum = 0;
                    printf(" You do not have the requirements for that spell.\n");
                }
                break;
            }
            default:{
                print(" Invalid Spell\n");
            }
        } //end of switch case
    }while(actionNum == 0);

    return actionNum;
}

void castSpell(int input, creature* caster, creature* opponent){
    int dmg = 0;
    switch(input){
        case 1:{ 
            dmg = caster->intl + caster->strn - opponent.wis;
            printf(" %s cast Fireball for %d damage\n", caster->name, dmg);
            break;
        }
        case 2:{ 
            caster->hlth += caster->wis;
            printf(" %s heals for %d health\n", caster->name, caster->wis);
            break;
        }
        case 1:{ 
            dmg = caster->intl + caster->strn - opponent.wis;
            printf(" %s cast Fireball for %d damage\n", caster->name, dmg);
            break;
        }        
    }
}
*/
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
    creature playerCpy = copyPlayer(*player);
    while(1){
        //speed check
        if(playerCpy.spd >= enemy->spd){ //player faster
            goto PlayerAction;
        } else{ //enemy faster, acts first
            goto EnemyAction;
        }

        //player actions TODO: allow for expanssion in switch case.
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        PlayerAction:
        switch(getAction(playerCpy)){
            case 1:{ //attack    
                if((rand() % (45 - enemy->spd + playerCpy.spd + 1)) == 0){
                    printf("You miss your attack!!!\n");
                    firstActionPerformed += 1;
                    goto StatusCheck;
                }
                int dmg = ((playerCpy.strn - (enemy->def / 3)) < 0) ? 0 : playerCpy.strn - (enemy->def / 3);
                printf("You deal %d damage. \n", dmg);
                enemy->hlth -= dmg;
                break;
                }
            case 2:{ //spells
                displaySpells(*player);
                //castSpell(getSpell()); 
                playerCpy.hlth += 2;  
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

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //enemy actions TODO: expand enemy potential actions
        EnemyAction:
        switch((rand() % 10)){
            case 1:{
                printf("The %s missed.\n", enemy->name);
                break;
            }
            default:{
                int dmg = ((enemy->strn - (playerCpy.def / 3)) < 0) ? 0 : enemy->strn - (playerCpy.def / 3);
                printf("The %s attacks for %d damage.\n", enemy->name, dmg);
                playerCpy.hlth -= dmg;
            }
        }   
        firstActionPerformed += 2;
        goto StatusCheck;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //check for health and order of attacks
        StatusCheck:
        if(playerCpy.hlth <= 0 || enemy->hlth <= 0){
            player->hlth = playerCpy.hlth;
            player->mana = playerCpy.mana;
            break;  //someone is dead, get out of combat
        }
        //check who acted last
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