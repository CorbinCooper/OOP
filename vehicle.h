#pragma once

namespace vehicles
{
	class Vehicle {
	public: Vehicle();
	public: virtual double getCapacity() const;
	public: virtual double getMaxWeight() const;
	public: virtual ~Vehicle();
	};
}