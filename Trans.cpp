#include "Trans.h"

namespace trans {
	Trans::Trans(bool _fourspeed, bool _fivespeed, bool _automatic)
		: fourspeed(_fourspeed), fivespeed(_fivespeed), automatic(_automatic)
	{}

	void Trans::print(std::ostream &out) const {
		if (fourspeed() == True)
			out << "Four Speed Transmission" << endl;
		else
			out << "Five Speed Transmission" << endl;

		if (automatic() == True)
			out << "Automatic Shifting" << endl;
		else
			out << "Manual Shifting" << endl;
	}


		std::ostream& operator<< (std::ostream &out, const Trans &trans) {
			trans.print(out);
			return out;
		}
}