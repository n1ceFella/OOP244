//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           16.10.2021
//==============================================

#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
using namespace std;
namespace sdds {
    const double ticketPrice = 125.34; //price in $
   
   class Bus {
   private:
       int m_seatsNumber;
       int m_passengersNumber;
   public: 
       Bus(int setsNum = 20, int passNum = 0);
       bool inService() const;
       void setOutOfService();
       void drawBus(ostream& ostr, int seats, int psng) const;
       std::ostream& display(std::ostream& ostr)const;
       std::istream& read(std::istream& istr);
       operator bool() const;
       operator int() const;
       operator double() const;
       Bus& operator=(int value);
       bool operator--();
       bool operator++();
       bool operator++(int);
       bool operator--(int);
       Bus& operator+=(int value);
       Bus& operator+=(Bus& right);
       bool operator==(const Bus& right) const;
   };
   int operator+(int left, const Bus& right);
   std::ostream& operator<<(ostream& ostr, Bus& Ro);
   std::istream& operator>>(istream& istr, Bus& Ro);
}
#endif