#pragma once

//#include <stdint.h>
#include <iostream>
#include <string>

namespace trans {

	class Trans {

	public: bool fivespeed;
	public: bool fourspeed;
	public: bool Automatic;

	public: Trans(bool fivespeed, bool fourspeed, bool Automatic);

	public: virtual void print(std::ostream &out) const;
	};

	std::ostream& operator<< (std::ostream &out, const Trans &trans);

}