#pragma once

#include "Nerfable.h"

namespace clips {

	class Clipable : public virtual nerf::Nerfable {
	public: Clipable(nerf::Series &series);
	public: virtual void clip() const;
	public: virtual ~Clipable();
	};
}