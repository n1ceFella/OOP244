//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           22.09.2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "Fighter.h"
namespace sdds {
	//assign name of fighter from keyboard
	void fighter(char* name)
	{
		cout << "Enter Fighter Name: ";
		cin >> name;
	}
	//assign power of fighter from keyboard
	void fighter(int& power)
	{
		cout << "Enter Fighter Power: ";
		cin >> power;
	}

	void addFighter(Competition& myCompetition)
	{
		int i; //index used in for loop
		int size = myCompetition.numfighters; //get size for fighters array depending on the current number of fighters
		Fighter* fightersArray = new Fighter[size + 1]; // Here we use DMA for expending fighters array
			for (i = 0; i < size; i++) {
				fightersArray[i] = myCompetition.fighters[i]; //copy all fighters from previous array to newly created array
			}
			cout << "Information of the new fighter:" << endl;
			fighter(fightersArray[size].name);
			fighter(fightersArray[size].power);
			delete[] myCompetition.fighters; //delete pointer to out of date array
			myCompetition.fighters = fightersArray; //assign new pointer to uptodate arra
			myCompetition.numfighters++; //increment number of fighters
	}
	//display fighter data
	void display(const Fighter& myFighter)
	{
		cout << "Name: " << myFighter.name << ", Power: " << myFighter.power << endl;
	}
	//iterate through array and call fuction to display fighter data
	void display(const Competition& mycompetition)
	{
		int i;
		for (i = 0; i < mycompetition.numfighters; i++) {
			display(mycompetition.fighters[i]);
		}
	}
	void removeFighter(Competition& mycompetition, const Fighter& loserFighter)
	{
		int i; //index used in for loop
		int loserIndex = findFighter(mycompetition, loserFighter); //get index of loser fighter
		int size = mycompetition.numfighters; //get size for fighters array depending on the current number of fighters
		Fighter* fightersArray = new Fighter[size -1]; // Here we use DMA for shrinking fighters array
			if (loserIndex != -1) { //if name is present in fighter array check
				//copy all fighters from previous array to newly created array
				for (i = 0; i < size - 1; i++) {
					if (i >= loserIndex) { //shift left one position if current index >= loserIndex 
						fightersArray[i] = mycompetition.fighters[i + 1];
					}
					else fightersArray[i] = mycompetition.fighters[i];
				}
			}
		mycompetition.numfighters--; //decrement number of fighters
		delete[] mycompetition.fighters; //delete pointer to out of date array
		mycompetition.fighters = fightersArray; //assign new pointer to uptodate array
	}
	//check if loser fighter name is present in the array
	int findFighter(const Competition& mycompetition, const Fighter& theFighter)
	{
		int index = -1;
		int i = 0;
		for (i = 0; i < mycompetition.numfighters; i++) {
			if (mycompetition.fighters[i].name == theFighter.name) {
				return i;
			}
		}
		return index;
	}
	//compare two fighters power and return true (1) if power of 1st greater than 2nd
	bool fight(const Fighter& f1, const Fighter& f2)
	{
		return (f1.power > f2.power);
	}
	//display message and call fight function to compare fighters
	//call removeFighters function for 2nd fighter if power of 1st is greater than 2nd, and vice versa
	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2)
	{
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		cout << "    The winner => ";
		if (fight(f1, f2)) {
			display(f1);
			removeFighter(mycompetition, f2);
		}
		else {
			display(f2);
			removeFighter(mycompetition, f1);
		}
	}
}