//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           18.09.2021
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "drink.h"
#include "file.h"

using namespace std;
namespace sdds
{
    FILE* fp = NULL;
    //here we read every line of the file and assign to strcuture members
    void readFile(const char* filename, Drink machine[])
    {
  
        int i = 0;
        fp = fopen(filename, "r");
        if (fp != NULL) {
            while (fscanf(fp, "%s%d%lf%d", machine[i].name, &(machine[i].volume), &(machine[i].price), &(machine[i].quantity))
                != EOF && i < MAXDRINKS) {
                i++;
            }
            fclose(fp);
        }
    }
}