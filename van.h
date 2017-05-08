#pragma once

#include "vehicle.h"
#include "parcel.h"

namespace vehicles
{
	class Van : public Vehicle {

	private: double _capacity;
	private: double _maxWeight;
	private: bool _isHazmat;

	public: Van(const double &capacity, const double &maxWeight, const bool &isHazmat);

	public: double getCapacity() const;
	public: double getMaxWeight() const;

	private: void updateCapacity();
	private: void updateMaxWeight();

	public: void addParcel(parcels::Parcel parcel);

	};
}