//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           09.10.2021
//==============================================

#ifndef SDDS_CHAPTER_H
#define SDDS_CHAPTER_H
namespace sdds
{
	class Chapter
	{
	public:
		Chapter(const char* name, int pagesNum);
		Chapter();
		~Chapter();
		void display()const;
		void setEmpty();
		void setName(const char* name);
		void setPagesNum(int pages);
		bool isInvalid();
	private:
		char m_name[51];
		int m_pagesNumber;
	};
}
#endif // !SDDS_CHAPTER_H