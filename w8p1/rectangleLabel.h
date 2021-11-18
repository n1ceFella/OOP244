#ifndef SDDS_RECT_LABEL_H
#define SDDS_RECT_LABEL_H
#include "labelShape.h"
namespace sdds
{
	class rectangleLabel : public labelShape
	{
	private:
		int m_width;
		int m_spaces;
	public:
		rectangleLabel();
		rectangleLabel(const char* label, int width, int spaces );
		void readShape(std::istream& istr);
		void drawShape(std::ostream& ostr);
	};
}
#endif