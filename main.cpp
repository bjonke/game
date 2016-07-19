#include <iostream>
#include <ctime>

using namespace std;

#include "game.h"

int main()
{
	// Initierar randomizer f�r slumpv�rden
	srand ( static_cast<unsigned int> ( time ( 0 ) ) );

	// Deklarera och initiera 'created_weapon'
	Weapon* created_weapon = CreateWeapon();

	//string *ballong = new string;
	// Skriver ut inneh�llet i 'created_weapon' structen p� sk�rmen			
	 ShowWeaponInfo(created_weapon);

	// Deklarera och initiera 'created_armour'
	Armour* created_armour = CreateArmour();
	
	// Skriver ut inneh�llet i 'created_armour' structen p� sk�rmen			
	 ShowArmourInfo(created_armour);

	// Deklarera och initiera 'player1' enligt CreatePlayer(string name, string type, Weapon* w, Armour* a);
	Player* player1 = CreatePlayer( "player1", "Soldier", created_weapon, created_armour);
	
	// Deklarera och initiera 'player2' enligt CreatePlayer(string name, string type, Weapon* w, Armour* a);
	Player* player2 = CreatePlayer( "player2", "Ogre", created_weapon, created_armour);
	
	// Utrusta 'attacker' vapen och 'victim' rustning
	EquipPlayerWeapon( player1, created_weapon );
	EquipPlayerArmour( player2, created_armour );

	// Skriver ut inneh�llet i 'attacker' och 'victim' structen p� sk�rmen	
	ShowPlayerInfo(player1);
	ShowPlayerInfo(player2);
	 
	// Starta en strid mellan 'attacker' och 'victim'
	DoBattle(player1,player2);
	
	//Avallokera allt det tilldelade minnet och avsluta programmet
	DestroyArmour(created_armour);
	DestroyWeapon(created_weapon);
	DestroyPlayer(player1);
	DestroyPlayer(player2);

	return 0;
}
