#include <iostream>
#include "Nerfable.h"
#include "Series.h"

namespace nerf {
	Nerfable::Nerfable(Series &_series) : series(_series) {
		//std::cout << "Nerfable()@" << (void*) this << std::endl;
		std::cout << "A toy made by NERF" << std::endl;
		series.isNerf.push_back(NerfPtr(this));
	}
	Nerfable::~Nerfable() {
		//std::cout << "~Nerfable()@" << (void*) this << std::endl;
	}
}