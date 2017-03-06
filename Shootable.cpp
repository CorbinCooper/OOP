#include <iostream>
#include "Shootable.h"

namespace shoots {

	Shootable::Shootable(nerf::Series &series) : nerf::Nerfable(series){
		//std::cout << "Shootable()@" << (void*) this << std::endl;
	}

	void Shootable::fire() const {
		std::cout << "It shoots darts!" << std::endl;
	}

	Shootable::~Shootable() {
		//std::cout << "~Shootable()@" << (void*) this << std::endl;
	}
}