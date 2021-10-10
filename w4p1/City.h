//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           07.10.2021
//==============================================

#ifndef SDDS_CITY_H
#define SDDS_CITY_H
namespace sdds
{
	//extern const int POPULATION;
	class City
	{
	public:
		City();
		City(const char* name, int population);
		void setEmpty();
		void setCityName(const char* name);
		void setPopulation(int population);
		void addPopulation(int population);
		bool isEmpty()const;
		int getPeople()const;
		void display()const;
	private:
		char m_cityName[31];// holds the city name up to 30 chars
		int m_population;//number of people. A city can have zero population.
	};
}
#endif // !SDDS_CITY_H