/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: LibApp.h
Version 1.0
Author	Volodymyr Labliuk
Revision
-----------------------------------------------------------
Date      Reason
2021/11/14  Preliminary release
2021/11/14  Debugged DMA
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

        char m_pubFileName[256]{};
        Publication* m_pubPtrs[SDDS_LIBRARY_CAPACITY]{};
        int m_numOfPub; //ptrs
        int m_lastRefNum;
        Menu m_pubTypeMenu = "Choose the type of publication:";

        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;


        bool confirm(const char* message);
        void load(const char* fileName);  // prints: "Loading Data"<NEWLINE>
        void save(const char* fileName);  // prints: "Saving Data"<NEWLINE>
        void search(bool all = false, bool checkOut = false, bool onLoan = false);  // prints: "Searching for publication"<NEWLINE>
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
        //LibApp();
        LibApp(const char* name);
        void run();
    };
}
#endif // !SDDS_LIBAPP_H
