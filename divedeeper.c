//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>
//self defined headers
#include "combatfunc.h"

//starting player attributes TODO: make function to give player choice of starting loadout
creature player = { .hlth = 30, .mana = 0, .strn = 3, .def = 3, .spd = 1, .wis = 3, .intl = 3, .name = "Player"};

int main(){
    gameIntro();
    int game_loop = 1; // allows game to not crash
    int dungeon_lvl = 0;
    srand(time(NULL));
    while(game_loop){
        int level_loop = 1;
        creature lvl_monster = getMonster();
        //int attack_order = 0; //1 for player, 0 for monster
        monsterEncounter(dungeon_lvl ,lvl_monster.name);
        while(level_loop){
            //player action 
            switch(getAction(player)){
                case 1:{ //attack    
                    printf("You deal 5 damage. \n");
                    lvl_monster.hlth -= player.strn;
                    break;
                }
                case 2:{ //heal
                    printf("You gain 2 health. \n");
                    player.hlth += 2;   
                    break;
                }
                case 3:{ //nothing
                    break;
                }
                default:{
                    printf("You misinput, causing you to freeze. \n");
                }
            }
            
            if(lvl_monster.hlth<= 0){
                level_loop = 0;
                break;
            }

            //enemy action
            switch((rand() % 10)){
                case 1:{
                    printf("The %s missed.\n", lvl_monster.name);
                    break;
                }
                default:{
                    printf("The %s attacks for %d damage.\n", lvl_monster.name, lvl_monster.strn);
                    player.hlth -= lvl_monster.strn;
                }
            }

            //health check
            if(lvl_monster.hlth <= 0 || player.hlth <= 0){
                level_loop = 0;
            } 
            else{
                continue;
            }
        }
        
        //next level
        if(lvl_monster.hlth <= 0 ){
            char confirm;
            printf("You have defeated the %s\nYou have %d health left\n", lvl_monster.name, player.hlth);
            printf("Dive to Level: %d? (y/n) ", dungeon_lvl + 1);
            scanf(" %c", &confirm);
            if(confirm != 'n'){
                dungeon_lvl++;
                continue;
            }
            else
            {
                game_loop = 0;
            }
        }
        
        //game over
        else if(player.hlth <= 0){
            gameOutro();
            game_loop = 0; 
        }
        
    }

    //End of game
    return 0;
}