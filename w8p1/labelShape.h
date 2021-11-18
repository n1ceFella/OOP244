#ifndef SDDS_LABEL_SHAPE_H
#define SDDS_LABEL_SHAPE_H
#include "baseShape.h"
namespace sdds
{
	class labelShape : public baseShape
	{
	public:
		labelShape();
		labelShape(const char* label);
		~labelShape();
		labelShape(const labelShape& lineLabel) = delete;
		labelShape& operator=(int value) = delete;
		void readShape(std::istream& istr);
		//void drawShape(std::ostream& ostr); //delete it
	protected:
		char* label()const;
	private:
		char* m_label{};
	};
}
#endif
