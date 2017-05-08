#pragma once

namespace trans 
{
	struct Drivetrain {
		virtual Trans getTrans() const = 0;
		virtual void setTrans(const Trans &value) = 0;
		virtual ~Drivetrain();
	};
}