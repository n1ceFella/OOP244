//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           15.11.2021
//==============================================

#ifndef SDDS_LINE_LABEL_H
#define SDDS_LINE_LABEL_H
#include "labelShape.h"
namespace sdds
{
	class lineLabel : public labelShape
	{
	public:
		lineLabel();
		lineLabel(const char* label, int lenght);
		void readShape(std::istream& istr);
		void drawShape(std::ostream& ostr) const;
	private:
		int m_length;
	};
}
#endif
