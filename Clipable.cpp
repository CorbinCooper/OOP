#include <iostream>
#include "Clipable.h"

namespace clips {

	Clipable::Clipable(nerf::Series &series) : nerf::Nerfable(series) {
		//std::cout << "Clipable()@" << (void*) this << std::endl;
	}

	void Clipable::clip() const {
		std::cout << "It uses a clip to load!" << std::endl;
	}

	Clipable::~Clipable () {
		//std::cout << "~Clipable()@" << (void*) this << std::endl;
	}
}