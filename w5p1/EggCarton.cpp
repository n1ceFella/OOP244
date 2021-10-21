//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           14.10.2021
//==============================================
#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds {
	//assign all data here
	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
	{
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumbo = jumboSize;
			if (!isIntact()) setBroken();
	}
	//check if carton is broken function
	bool EggCarton::isIntact() const
	{
		bool coeficient = (m_size % 6) == 0;
		return (coeficient && (m_size >= 6 && m_size <= 36) && (m_noOfEggs >= 0 && m_noOfEggs <= m_size));
	}
	//set carton to broken
	void EggCarton::setBroken()
	{
		m_size = -1;
		m_noOfEggs = -1;
	}
	//display eggs data properly
	std::ostream& EggCarton::display(std::ostream& ostr)const
	{
		if (*this) {
			// displays an Egg Carton
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++) {
				cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}
		else cout << "Broken Egg Carton!" << endl;
		return ostr;
	}
	//read data from keyboard
	std::istream& EggCarton::read(std::istream& istr)
	{
		char jumboChar;
		istr >> jumboChar;
		jumboChar == 'j' ? m_jumbo = true : m_jumbo = false;
		istr.ignore();
		istr >> m_size;
		istr.ignore();
		istr >> m_noOfEggs;
		return istr;
	}
	//call read function ( eggs data from keyboard )
	std::istream& operator>>(istream& istr, EggCarton& Ro)
	{
		return Ro.read(istr);
	}
	//display eggs carton
	std::ostream& operator<<(ostream& ostr, EggCarton& Ro)
	{
		return Ro.display(ostr);
	}
	//if carton is not broken add eggs to right, otherwise return left
	int operator+(int left, const EggCarton& right)
	{

		if (right.isIntact()) {
			return (int)right + left;
		}
		else return left;
	}
	//boolean type overloading, check if carton broken
	EggCarton::operator bool() const
	{
		return isIntact();
	}
	//double type overloading, return number of eggs, if carton is broken ( used bool overload ) return -1
	EggCarton::operator int() const
	{
		return *this ? m_noOfEggs : -1;
	}
	//double type overloading, determin egg type and calculate weight of carton 
	EggCarton::operator double() const
	{
		double weightOfAnEgg;
		if (m_jumbo) {
			weightOfAnEgg = JumboEggWieght;
		}
		else weightOfAnEgg = RegularEggWieght;
		return *this ? ((m_noOfEggs * weightOfAnEgg) / 1000.0) : -1.0;
	}
	//if carton is not broken decrement num of eggs
	EggCarton EggCarton::operator--()
	{
		if (isIntact()) {
			m_noOfEggs--;
		}
		return *this;
	}
	//copy calling carton to new carton call prefix operator -- and return new carton by value
	EggCarton EggCarton::operator--(int)
	{
		EggCarton eggCartonCopy = *this;
		this->operator--();
		return eggCartonCopy;
	}
	//if carton is not broken increment num of eggs, and manage overflow
	EggCarton EggCarton::operator++()
	{
		if (isIntact()) {
			m_noOfEggs++;
			if (m_noOfEggs > m_size) setBroken();
		}
		return *this;
	}
	//copy calling carton to new carton call prefix operator ++ and return new carton by value
	EggCarton EggCarton::operator++(int)
	{
		EggCarton eggCartonCopy = *this;
		this->operator++();
		return eggCartonCopy;
	}
	//set number of eggs to value and manage overflow
	EggCarton& EggCarton::operator=(int value)
	{
		m_noOfEggs = value;
		if (m_noOfEggs > m_size) setBroken();
		return *this;
	}
	//add value number of eggs to carton, and manage overflow
	EggCarton& EggCarton::operator+=(int value)
	{
		if (isIntact()) {
			m_noOfEggs += value;
			if (m_noOfEggs > m_size) setBroken();
		}
		return *this;
	}
	//move eggs from right carton to left as many as possible
	EggCarton& EggCarton::operator+=(EggCarton& right)
	{
		bool isEmpty = (right.m_noOfEggs == 0);
		if (isIntact()) {
			while ((m_noOfEggs < m_size) && !isEmpty) {
				this->m_noOfEggs += 1;
				right.m_noOfEggs -= 1;
			}
		}
		return *this;
	}
	//determin EggWeight and calculate difference, return true if they are equal
	bool EggCarton::operator==(const EggCarton& right) const
	{
		double weightOfCurrentCarton = m_jumbo ? m_noOfEggs * JumboEggWieght : m_noOfEggs * RegularEggWieght;
		double weightOfRightCarton = right.m_jumbo ? right.m_noOfEggs * JumboEggWieght : right.m_noOfEggs * RegularEggWieght;
		return (((weightOfCurrentCarton - weightOfRightCarton)/1000 < 0.001) &&
			((weightOfCurrentCarton - weightOfRightCarton)/1000 > -0.001)) ? true : false;
	}
}