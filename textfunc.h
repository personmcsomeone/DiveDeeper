#ifndef __TEXT_FUNC_H__
#define __TEXT_FUNC_H__
#include "combatfunc.h"
//------------------------------------------
// functions
//------------------------------------------
void funcStatusCheck(creature player);
void gameIntro();
void gameOutro();
void monsterEncounter(int level, char* name);
void displaySpells(creature player);

#endif //end inclsion guard