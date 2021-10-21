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
		std::ostream& printPhoneNumber(std::ostream& istr)const;
		std::ostream& print(std::ostream& ostr, bool toFile = true) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Contact& cnt);
	std::istream& operator>>(std::istream& istr, Contact& cnt);
}
#endif // !SDDS_CONTACT_H


