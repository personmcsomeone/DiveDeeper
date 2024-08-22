//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>
//self defined headers
#include "combatfunc.h"
#include "textfunc.h"

//starting player attributes TODO: make function to give player choice of starting loadout
//creature player = resetPlayer();

int main(){
    Start:
    gameIntro();
    creature player = resetPlayer();
    int game_loop = 1; // allows game to not crash
    int dungeon_lvl = 0;
    srand(time(NULL));
    while(game_loop){
        //combat
        creature lvl_monster = getMonster();
        monsterEncounter(dungeon_lvl, lvl_monster.name);                  //print
        combatPhase(&lvl_monster, &player);                               //actual fight
    
        //resolve combat results
        if(lvl_monster.hlth <= 0 ){
            char confirm;
            printf("You have defeated the %s\nYou have %d health left\n", lvl_monster.name, player.hlth);
            levelUp(&player);
            printf("Dive to Level: %d? (y/n) ", dungeon_lvl + 1);
            scanf(" %c", &confirm);
            if(confirm != 'n'){
                dungeon_lvl++;
                continue;
            } else{
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
    printf("New Game (1) or Close (0): ");
    scanf(" %d", &game_loop);
    if(game_loop != 0){
        resetPlayer();
        goto Start;
    }
    return 0;
}