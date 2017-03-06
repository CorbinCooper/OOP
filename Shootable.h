#pragma once

#include "Nerfable.h"

namespace shoots
{
	class Shootable : public virtual nerf::Nerfable {
	public: Shootable(nerf::Series &series);
	public: virtual void fire() const;
	public: virtual ~Shootable();
	};
}
