#include <iostream>
#include <ctime>
#include <string>

using namespace std;

#include "player.h"

// Utför beräkningar och avdrag av skada genom en attack mellan två spelare
void Attack( Player *attacker, Player *victim )
{
	// Skriver ut vem som attackerar vem och med vad
	cout << endl;
	cout << attacker->name << " attacks " << victim->name 
		 << " with his " << endl << attacker->weapon->name;
	
	// Initierar variabler inför användning
	int damage = 0;
	// Minsta skadan som vapnet kan göra
	int min_damage = attacker->weapon->min_damage;
	// Maximala skadn som vapnet kan göra
	int max_damage = attacker->weapon->max_damage;

	// Hur mycket det skiljer mellan min och max värdet
	int damage_span = ((attacker->weapon->max_damage) - (attacker->weapon->min_damage));

	// Slumpar ut värdet som vapnet skall göra i skada
	damage = (min_damage + (rand() % damage_span));
	

	// forts. på vem som attackerar vem o.s.v
	cout << " doing " << damage << " damage" << ", the " << victim->armour->name 
		 << " absorbs " << victim->armour->armour_class << endl << endl;
	
	// Tar bort mängden HP som penetrerar rustningen annars meddelar att ingen skada skedde
	if( damage - victim->armour->armour_class > 0)
	{
		victim->health -= damage - victim->armour->armour_class;
		cout << "Health: " << victim->health << endl;
	}
	else
	{
		// Detta för att försäkra sig om att även en spelare med ett vapen som inte kan göra tillräckligt
		// med skada på rustningen skall ha möjlighet att döda en sån spelare med lite tur.
		int perfect = rand() % 2;
		if(perfect == 1)
		{
			cout << "The weapon finds a chink in the armour and does full damage" << endl;
			victim->health -= damage;
			cout << "Health: " << victim->health << endl;
		}
		else
		{
			cout << attacker->name << "'s " << attacker->armour->name << " absorbed the damage" << endl;
		}
	}	
}

// Slumpar vilken spelare som börjar och kollar så ingen spelare är död, därefter anropar attack
// tills någon spelare har dött
void DoBattle( Player *p1, Player *p2 )
{
	int random = 0;
	int finished = 0;

	// Slumpar ett värde för att se ifall player1 eller player2 attackerar först
	random = rand() % 2;

	while( finished == 0)
	{
	if(random == 0)
	{
		Attack(p1,p2);
		if( p2->health <= 0 )
		{
			cout << p2->name << " died" << endl;
			finished = 1;
		}
				
		Attack(p2,p1);
		if( p1->health <= 0 )
		{
			cout << p1->name << " died" << endl;
			finished = 1;
		}
	}
	else
	{
		Attack(p2,p1);
		if ( p1->health <= 0)
		{
			cout << p2->name << " died, please try reviving that person." << endl;
			finished = 1;
		}
		
		Attack(p1,p2);
		if( p2->health <= 0 )
		{
			cout << p2->name << " died, please try reviving that person." << endl;
			finished = 1;
		}
	}
	
	cout << "Turn ended." << endl;
	cin.get();
	}
}
