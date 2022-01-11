//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           02.12.2021
//==============================================

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"

namespace sdds {
	//inject Collection of objects to find element in it under index 
	template <typename ObjArr, typename Key>
	bool check(ObjArr arr, int index, Key element)
	{
		return (arr[index] == element);
	}
	//inject array of object to to find element with Key (element) and save it to array of objects under address arrTo
	template <typename ObjArr, typename Key>
	bool search(ObjArr* arrFrom, int size,const Key element, Collection<ObjArr>* arrTo)
	{
		int matchesFound = 0;
		for (int i = 0; i < size; i++) {
			if (check(arrFrom, i, element)) {
				arrTo->add(arrFrom[i]);
				matchesFound++;
			}
		}
		return matchesFound;
	}
	//inject array of objects and display data of every element of it
	template <typename ObjArr>
	void listArrayElements(const char* title, const ObjArr* objArr, int size )
	{
		std::cout << title << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << i+1 << ": " << objArr[i] << std::endl;
		}
		

	}
	//inject two arrays of objects and compare them
	template <typename T>
	bool sizeCheck(Collection<T> col1, Collection<T> col2)
	{
		return col1.size() > col2.size();
	}
	


}
#endif // !SDDS_SEARCH_H_

