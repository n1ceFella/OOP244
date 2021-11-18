/*
Name: Volodymyr Labliuk 
Email: vlabliuk@myseneca.ca
Student ID: 147302202
Data: 11.11.2021
Section: NBB
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	const int MAX_PLATE_NUM = 9;
	const int MAX_ADRESS_NUM = 21;
	class VehicleBasic
	{
	public:
		VehicleBasic(const char* plateNum, int buildYear);
		void NewAddress(const char* address);
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& in);
		const char* plateNumber() const;
		const char* currentAddress() const;
		int buildYear() const;
		void plateNumber(char* number);
		void currentAddress(const char* address);
		void buildYear(int buildYear);

	private:
		char m_plateNumber[MAX_PLATE_NUM]{};
		char m_address[MAX_ADRESS_NUM]{};
		int m_buildYear;
	};
	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle);
	std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle);
}

#endif