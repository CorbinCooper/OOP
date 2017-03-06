#include <string>
#include <iostream>

#include "Stryfe.h"

namespace shoots {

	Stryfe::Stryfe(nerf::Series &series, const std::string &name, const double &msrp) :
		nerf::Nerfable(series),
		clips::Clipable(series),
		shoots::Shootable(series),
		_name(name),
		_msrp(msrp) {
		//std::cout << "Stryfe()@" << (void*) this << std::endl;
	}

	std::string Stryfe::getName() const {
		return _name;
	}

	void Stryfe::setName(const std::string &name) {
		if (_name != name) {
			_name = name;
		}
	}

	double Stryfe::getMSRP() const {
		return _msrp;
	}

	void Stryfe::setMSRP(const double &msrp) {
		if (_msrp != msrp) {
			_msrp = msrp;
		}
	}

	Stryfe::~Stryfe() {
		//std::cout << "~Stryfe()@" << (void*) this << std::endl;
	}

}