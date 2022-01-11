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
namespace sdds {
   class LibApp {
   private:
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>
       void newPublication(); //print and confirm new publication
       void removePublication(); //print and confirm remove publication
       void checkOutPub(); //print and confirm check out publication
       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */


   public:
       LibApp();
       void run();
   };
}
#endif // !SDDS_LIBAPP_H



