#pragma once

#include <memory>
#include <vector>

#include "Nerfable.h"

namespace nerf {

	class Series {
	private: std::vector < NerfPtr > isNerf;
	public: ~Series();
		friend Nerfable;
	};
}