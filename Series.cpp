#include "Series.h"

namespace nerf {
	Series::~Series() {
		for (auto nerfable : isNerf) {
			delete nerfable;
		}
	}
}