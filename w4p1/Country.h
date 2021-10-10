//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           07.10.2021
//==============================================

#ifndef SDDS_COUNTRY_H
#define SDDS_COUNTRY_H
#include "City.h"
namespace sdds
{
	class Country
	{
	public:
		Country();
		Country(const char* name, int noOfCity, const City* cities);
		~Country();
		void setEmpty();
		void setName(const char* name);
		Country& addCity(const City& c);
		Country& migrate(int people);
		bool isEmpty()const;
		void display()const;

	private:
		char* m_name = nullptr;//points to a dynamically allocated Cstring holding the Country name
		int m_noOfCity;//size of the dynamically allocated array of cities
		City* m_city = nullptr;//pointer to the dynamically allocated array of cities
	};
}
#endif // !SDDS_COUNTRY_H