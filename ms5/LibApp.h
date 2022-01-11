//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           03.12.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: LibApp.h
Version 1.0
Author	Volodymyr Labliuk
Revision
-----------------------------------------------------------
Date      Reason
2021/12/03  Preliminary release
2021/12/03  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Utils.h"
#include "Publication.h"
namespace sdds
{
    class LibApp
    {
    private:
       Menu m_pubTypeMenu;
       Menu m_mainMenu;
       Menu m_exitMenu;
       int m_numOfPub{}; //ptrs
       int m_lastRefNum{};
       bool m_changed{};
       Publication* m_pubPtrs[SDDS_LIBRARY_CAPACITY]{};
       char m_pubFileName[256]{};


        bool confirm(const char* message);
        void load(const char* fileName);  // prints: "Loading Data"<NEWLINE>
        void save(const char* fileName);  // prints: "Saving Data"<NEWLINE>
        int search(bool checkOut = false, bool onLoan = false);  // prints: "Searching for publication"<NEWLINE>
        void newPublication(); //print and confirm new publication
        void removePublication(); //print and confirm remove publication
        void checkOutPub(); //print and confirm check out publication
        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
        Publication* getPub(int libRef);
    public:
        LibApp(const char* name);
        ~LibApp();
        void run();
    };
}
#endif // !SDDS_LIBAPP_H
