#ifndef _GAME_H_
#define _GAME_H_

#include "player.h"

// attack by 'attacker' against 'victim'
void Attack( Player *attacker, Player *victim );

// Function that controlls the whole battle and calls for Attack
void DoBattle( Player *p1, Player *p2 );

#endif
