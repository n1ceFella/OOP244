//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           02.12.2021
//==============================================

// Workshop 10:
// Version: 2.0
// 2021-11-19
// Author: Fardad Soleimanloo
// Revised by: Wail Mardini
// // Description:
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
/////////////////////////////////////////////
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "searchNlist.h"
using namespace std;
using namespace sdds;

int main()
{
    Car C[7] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"),
                 Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"),
                 Car("GVDEFG", "Tesla Model X") };
    Student S[6] = { Student(23456, "Lisa Simpson",4.0),Student(45678, "Ralph Wiggum",2.1), Student(56789, "Milhouse Van Houten",4.0),
                 Student(67890, "Todd Flanders", 3.5), Student(34567, "Nelson Muntz",3.0),Student(12345, "Bart Simpson",1.5) };
    Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56,111), Employee(122345, "Mindy Simmons", 65432.44,222),
                 Employee(435678, "Lenny Leonard", 43213.22,111), Employee(546789, "Waylon Smithers", 654321.55,333),
                 Employee(657890, "Frank Grimes", 34567.88,333), Employee(364567, "Homer Simpson", 55432.11,111) };

    //these collections will hold the results of the searches
    Collection<Car> Cres1;
    Collection<Car> Cres2;
    Collection<Student> Sres;
    Collection<Employee>Eres;

    //constant string ,  collection of Cars(C) and size of it (7) inserted
    //to display all elements
    listArrayElements("All the cars:", C, 7);
    cout << "Searching for Tesla cars: " << endl;

    //array of Cars(C), size , key, and reference to (Collection)Cres1 object injected
    //to find all matches "a" in C and add them to Cres1
    if (search(C, 7, "a", &Cres1))
    {
        cout << Cres1.size() << " match" << (Cres1.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Cres1.size(); i++)
        {
            cout << (i + 1) << ": " << Cres1[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    //array of Cars(C), size , key, and reference to (Collection)Cres2 object injected
    //to find all matches "b" in C and add them to Cres2
    if (search(C,7,"b",&Cres2))
    {
        cout << Cres2.size() << " match" << (Cres2.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Cres1.size(); i++)
        {
            cout << (i + 1) << ": " << Cres1[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    //inject two collections of Cars (Cres1,Cres2) to compare
    if (sizeCheck(Cres1,Cres2))
        cout << "Collection 1 got more results!!" << endl;
    else
        cout << "Collection 1 got less than or equal collection 2 results!!" << endl;

    cout << endl;

    //constant string ,  collection of Students(S) and size of it (6) inserted
    //to display all elements
    listArrayElements("All students:",S,6);

    cout << "Searching for students with 4.0 Gpa:" << endl;
    //array of Student(S), size , key, and reference to (Collection)Sres object injected
    //to find all matches 4.0 in S and add them to Sres
    if (search(S,6,4.0,&Sres))
    {
        cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Sres.size(); i++)
        {
            cout << (i + 1) << ": " << Sres[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    //constant string ,  collection of Employee(E) and size of it (6) inserted
    //to display all elements
    listArrayElements("All employees:",E,6);

    cout << "Searching for employees who share office number 111:" << endl;
    //array of Employee(E), size , key, and reference to (Collection)Eres object injected
    //to find all matches 111 in E and add them to Eres
    if (search(E,6,111,&Eres))
    {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++)
        {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    cout << "Searching for employees who share office number 555:" << endl;
    //array of Employee(E), size , key, and reference to (Collection)Eres object injected
    //to find all matches 555 in E and add them to Eres
    if (search(E,6,555,&Eres))
    {
        cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
        for (int i = 0; i < Eres.size(); i++)
        {
            cout << (i + 1) << ": " << Eres[i] << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    cout << endl;

    int a[]{ 10,20,30,40,50,60 };

    //constant string ,  collection of integers a and size of it (6) inserted
    //to display all integers
    listArrayElements("INTEGERS", a, 6);
    return 0;
}
