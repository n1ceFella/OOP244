#ifndef SDDS_BASE_SHAPE_H
#define SDDS_BASE_SHAPE_H
namespace sdds
{
	class baseShape
	{
	public:
		virtual void drawShape(std::ostream& ostr) const = 0;
		virtual void readShape(std::istream& istr) = 0;
		virtual ~baseShape();
	private:
	};
	std::ostream& operator<<(std::ostream& ostr, baseShape& baseShape);
	std::istream& operator>>(std::istream& istr, baseShape& baseShape);
}
#endif