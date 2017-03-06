#pragma once

#include <string>

#include "Nerfable.h"
#include "Shootable.h"
#include "Clipable.h"

namespace shoots
{
	class Stryfe : public Shootable, public clips::Clipable {
	private: std::string _name;
	private: double _msrp;

	public: Stryfe(nerf::Series &series, const std::string &name, const double &msrp);

	public: virtual ~Stryfe();

	public: std::string getName() const;
	public: void setName(const std::string &name);

	public: double getMSRP() const;
	public: void setMSRP(const double &msrp);

	};
}