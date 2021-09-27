//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           22.09.2021
//==============================================

#ifndef SDDS_FIGHTER_H
#define SDDS_FIGHTER_H
#include <iostream>
using namespace std;
namespace sdds {
	const int MAX_NAME = 50;

	struct Fighter {
		char name[MAX_NAME+1];
		int power;
	};

	struct Competition {
		Fighter* fighters;
		int numfighters;
	};

	//TODO: Declare the prototypes for the functions required as per the lab instructions
	void fighter(char* name);
	void fighter(int& power);
	void display(const Fighter& myFighter);
	void display(const Competition& mycompetition);
	void addFighter(Competition& myCompetition);
	void removeFighter(Competition& mycompetition, const Fighter& loserFighter);
	int findFighter(const Competition& mycompetition, const Fighter& theFighter);
	bool fight(const Fighter& f1, const Fighter& f2);
	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2);
}
#endif /* FIGHTER_H */



