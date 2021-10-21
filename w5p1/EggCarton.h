//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           14.10.2021
//==============================================

#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>

using namespace std;
namespace sdds {

	const int RegularEggWieght = 50; // in grams
	const int JumboEggWieght = 75; // in grams

	class EggCarton
	{
	private:
		int m_size;
		int m_noOfEggs;
		bool m_jumbo;
		void setBroken();
	public:
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		bool isIntact() const;
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		operator int() const;
		operator double() const;
		EggCarton operator--();
		EggCarton operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);
		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;
	};
	int operator+(int left, const EggCarton& right);
	std::ostream& operator<<(ostream& ostr, EggCarton& Ro);
	std::istream& operator>>(istream& istr, EggCarton& Ro);
}
#endif