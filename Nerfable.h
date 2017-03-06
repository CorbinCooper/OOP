#pragma once

#include <memory>

namespace nerf {
	class Series;
	class Nerfable;
	typedef Nerfable * NerfPtr;

	class Nerfable {
	private: Series &series;
	public: Nerfable(Series &_series);
	public: virtual ~Nerfable();
	};

}