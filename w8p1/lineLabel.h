#ifndef SDDS_LINE_LABEL_H
#define SDDS_LINE_LABEL_H
#include "labelShape.h"
namespace sdds
{
	class lineLabel : public labelShape
	{
	private:
		int m_length;
		lineLabel();
		lineLabel(const char* label, int lenght);
		void readShape(std::istream& istr);
		void drawShape(std::ostream& ostr);
	};
}
#endif
