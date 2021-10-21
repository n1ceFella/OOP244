//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           16.10.2021
//==============================================

#include "Bus.h"
namespace sdds {
	//assign data or set bus out of service is data is invalid
	Bus::Bus(int seatsNum, int passNum)
	{
		m_seatsNumber = seatsNum;
		m_passengersNumber = passNum;
		if (!*this) {
			setOutOfService();
		}
	}
	//check if bus in service (valid)
	bool Bus::inService() const
	{
		bool coeficient = (m_seatsNumber % 2) == 0;
		return (coeficient && (m_seatsNumber >= 10 && m_seatsNumber <= 40) && (m_passengersNumber >= 0 && m_passengersNumber <= m_seatsNumber));
	}
	//set all data to invalid state
	void Bus::setOutOfService()
	{
		m_passengersNumber = -1;
		m_seatsNumber = -1;
	}
	//call drawBus function to display all data and display total price
	std::ostream& Bus::display(std::ostream& ostr) const
	{
		if (*this) {
			drawBus(ostr, m_seatsNumber, m_passengersNumber);
			ostr.precision(2);
			ostr.setf(ios::fixed);
			ostr << "Total Fare Price: " << (double)*this << endl;
			ostr.unsetf(ios::fixed);
		} else 	ostr << "Out of service!" << endl;
		return ostr;
	}
	// draws a bus with 
// seat = number of seats
// psng = number of passengers
// on ostream
	void Bus::drawBus(ostream& ostr, int seats, int psng) const
	{
			int i, p;
			ostr.fill('_');
			ostr.width((seats / 2) * 3 + 4);
			ostr << "_";
			ostr << endl << "| ";
			for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
			ostr << "|_\\_" << endl;
			ostr << "| ";
			ostr.fill(' ');
			ostr.width(((seats / 2) * 3 - 14) / 2);
			ostr << " " << "Seneca College";
			ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
			ostr << " " << "    )" << endl;
			ostr << "`---OO";
			ostr.fill('-');
			ostr.width((seats / 2) * 3 - 5);
			ostr << "-" << "O---'" << endl;
	}
	//read data from keyboard
	std::istream& Bus::read(std::istream& istr)
	{
		istr >> m_seatsNumber;
		istr.ignore();
		istr >> m_passengersNumber;
		istr.ignore();
		if (!*this) {
			setOutOfService();
		}
		return istr;
	}
	//overloaded bool type  to check if bus is service
	Bus::operator bool() const
	{
		return inService();
	}
	//overloaded int type to return num of passengers or -1 if out of service
	Bus::operator int() const
	{
		return *this ? m_passengersNumber : -1;
	}
	//overloaded double type to return total price for bus or -1.0 if out of service
	Bus::operator double() const
	{
		return *this ? m_passengersNumber * ticketPrice : -1.0;
	}
	//overloaded prefix -- to decrement passengers number if possible
	bool Bus::operator--()
	{
		if (*this &&  m_passengersNumber > 0) {
			m_passengersNumber--;
			return true;
		}
		else return false;
	}
	//overloaded prefix ++ to increment number of passengers if possible
	bool Bus::operator++()
	{
		if (*this && m_passengersNumber < m_seatsNumber) {
			m_passengersNumber++;
			return true;
		}
		else return false;
	}
	//overloaded postfix -- to decrement passengers number if possible
	bool Bus::operator--(int)
	{
		if (*this && m_passengersNumber > 0) {
			m_passengersNumber--;
			return true;
		}
		else return false;
	}
	//overloaded postfix ++ to increment number of passengers if possible
	bool Bus::operator++(int)
	{
		if (*this && m_passengersNumber < m_seatsNumber) {
			m_passengersNumber++;
			return true;
		}
		else return false;
	}
	// set value of passenger to value
	Bus& Bus::operator=(int value)
	{
		m_passengersNumber = value;
		if (!*this) {
			setOutOfService();
		}
		return *this;
	}
	//if bus inService add value passengers to passengers number and handle overflow
	Bus& Bus::operator+=(int value)
	{
		if (*this) {
			m_passengersNumber += value;
			if (!*this) {
				setOutOfService();
			}
		}
		return *this;
	}
	// one by one move passengers to left until it's full , rest keep in the right
	Bus& Bus::operator+=(Bus& right)
	{
		if (*this && (bool)right) {
			bool isEmpty = (right.m_passengersNumber == 0);
				while ((m_passengersNumber < m_seatsNumber) && !isEmpty) {
					this->m_passengersNumber += 1;
					right.m_passengersNumber -= 1;
				}
		}
		return *this;
	}
	//check if buses have same number of passengers
	bool Bus::operator==(const Bus& right) const
	{
		return ((*this && (bool)right) && this->m_passengersNumber == right.m_passengersNumber) ? true : false;
	}
	//if right bus in service add left value (passengers number) to right bus 
	int operator+(int left, const Bus& right)
	{
		return (bool)right ? (int)right + left : left;
	}
	//overloaded cout operator to display data
	std::ostream& operator<<(ostream& ostr, Bus& Ro)
	{
		return Ro.display(ostr);
	}
	//overloaded cin operator to read data
	std::istream& operator>>(istream& istr, Bus& Ro)
	{
		return Ro.read(istr);
	}
}