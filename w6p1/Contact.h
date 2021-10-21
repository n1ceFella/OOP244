//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           20.10.2021
//==============================================

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
using namespace std;
namespace sdds {
	const int MaxNameLength = 55;
	class Contact
	{
	private:
		char* m_name{}; // sets m_name to nullptr before any constructor invocation 
		int m_area;
		int m_exchangeCode;
		int m_number;
		void allocateAndCopy(const char* name);
		void extractChar(std::istream& istr, char ch)const;
		bool validPhone(int areaCode, int exchangeCode, int number)const;
		bool validName(const char* name) const;
		void setEmpty();
		void set(const char* name, int areaCode, int exchangeCode, int number);
	public:
		Contact(const char* name, int area, int exCode, int number);
		Contact();
		Contact(const Contact& cnt);
		~Contact();
		bool isValidContact() const;
		Contact& operator=(const Contact& cnt);
		ostream& printPhoneNumber(ostream& istr)const;
		ostream& print(ostream& ostr, bool toFile = true) const;
		istream& read(istream& istr);
		operator bool() const;
	};
	ostream& operator<<(ostream& ostr, const Contact& cnt);
	istream& operator>>(istream& istr, Contact& cnt);
}
#endif // !SDDS_CONTACT_H


