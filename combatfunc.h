#ifndef __STRUCT_DEF_H__
#define __STRUCT_DEF_H__

//------------------------------------------
//Struct types

typedef struct{
    int hlth; //health
    int mana; //total mana
    int strn; //strength
    int def; //defence stat
    int spd; //speed stat
    int wis; //wisdom stat
    int intl; //intellegence stat
    char* name;
} creature;

//------------------------------------------
// functions
//------------------------------------------
creature getMonster();
void funcStatusCheck( int playerHealth);
int getAction();
void gameIntro();
void gameOutro();

#endif //end inclsion guard