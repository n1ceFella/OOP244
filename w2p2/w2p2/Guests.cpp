//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           27.09.2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guests.h"
using namespace std;

namespace sdds {

    void addGuest(GuestList& theGuestList, const Guest& aGuest)
    {
        int i;
        int size = theGuestList.m_noOfGuests; //get size of previous array
        Guest* tempGuestList = new Guest[size + 1]; //DMA array to copy all guest from previous array + 1 empty slot for new guest
        //iterate through previous array and copy all guest data to newwly created array
        for (i = 0; i < size; i++) {
            strcpy(tempGuestList[i].m_name, theGuestList.m_gst[i].m_name);
            tempGuestList[i].m_phno = theGuestList.m_gst[i].m_phno;
        }
        strcpy(tempGuestList[size].m_name, aGuest.m_name); //add new guest name to the last element 
        tempGuestList[size].m_phno = aGuest.m_phno; //add new guest phone number to the last element 
        delete[] theGuestList.m_gst; //delete previous array from memory
        theGuestList.m_gst = tempGuestList; //assign new poiter of newly created array to previous array
        theGuestList.m_noOfGuests++; //add number of guests +1
    }
   void read(char* str, int len) {
      if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
      cin.getline(str, len);
   }
   //read phone number from keyboard
   void read(PhoneNumber& thePhoneNumber)
   {
       cout << "Enter Phone Number [area] [number]: ";
       cin >> thePhoneNumber.m_areacode;
       cin >> thePhoneNumber.m_number;
   }
   //check if name is empty (to exit) otherwise read number from keybard
   bool read(Guest& theGuest)
   {
       cout << "Guest name: ";
       read(theGuest.m_name, 20);
       if (strlen(theGuest.m_name) == 0) {
           return false;
       }
       read(theGuest.m_phno);
       return true;
       
   }
   //print number of single guest
   void print(const PhoneNumber& thePhoneNumber)
   {
       cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;
   }
   //print name of single guest
   void print(const Guest& theGuest)
   {
       cout << theGuest.m_name << ", ";
       print(theGuest.m_phno);
   }
   //iterate throught the list of guest and call function to print data
   void print(const GuestList& theGuestList)
   {
       int i;
       int size = theGuestList.m_noOfGuests;
       for (i = 0; i < size; i++) {
           cout << i+1 << "- ";
           print(theGuestList.m_gst[i]);
       }
   }
}