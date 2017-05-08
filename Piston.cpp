#include "Piston.h"

namespace engines {
	Piston::Piston(const double &bore, const double &stroke, const double &cyls)
		: _bore(bore), _stroke(stroke), _cyls(cyls), _disp(bore*stroke*cyls),
		_trans(false, false, false)
	{

	}

	double Piston::getBore() const {
		return _bore;
	}

	void Piston::setBore(const double &value) {
		if (_bore != value) {
			_bore = value;
			updateDisp();
		}
	}

	double Piston::getStroke() const {
		return _stroke;
	}

	void Piston::setStroke(const double &value) {
		if (_stroke != value) {
			_stroke = value;
			updateDisp();
		}
	}

	double Piston::getCyls() const {
		return _cyls;
	}

	void Piston::setCyls(const double &value) {
		if (_cyls != value) {
			_cyls = value;
			updateDisp();
		}
	}

	void Piston::updateDisp() {
		_disp = _bore * _stroke * _cyls;
	}

	double Piston::getDisp() const {
		return _disp;
	}

}
