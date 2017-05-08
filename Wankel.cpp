#include "Wankel.h"

namespace engines {
	Wankel::Wankel(const double &width, const double &eccen, const double &length, const double &rotors)
		: _width(width), _eccen(eccen), _length(length), _rotors(rotors), _disp(width*length*eccen*rotors),
		_trans(false, false, false)
	{

	}

	double Wankel::getWidth() const {
		return _width;
	}

	void Wankel::setWidth(const double &value) {
		if (_width != value) {
			_width = value;
			updateDisp();
		}
	}

	double Wankel::getEccen() const {
		return _eccen;
	}

	void Wankel::setEccen(const double &value) {
		if (_eccen != value) {
			_eccen = value;
			updateDisp();
		}
	}

	double Wankel::getLength() const {
		return _length;
	}

	void Wankel::setLength(const double &value) {
		if (_length != value) {
			_length = value;
			updateDisp();
		}
	}

	double Wankel::getRotors() const {
		return _rotors;
	}

	void Wankel::setRotors(const double &value) {
		if (_rotors != value) {
			_rotors = value;
			updateDisp();
		}
	}

	void Wankel::updateDisp() {
		_disp = _width * _eccen * _length * _rotors;
	}

	double Wankel::getDisp() const {
		return _disp;
	}

}
