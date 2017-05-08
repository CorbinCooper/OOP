#include <iostream>

#include "parcel.h"

namespace parcels {

	Parcel::Parcel() {};

	Parcel::Parcel(const int &serial, const double &width, const double &height,
		const double &depth, const double &weight, const bool &hazmat) {}

	void Parcel::genSerial()
	{
		_serial = rand() % 899999 + 100000;
	}

	void Parcel::setWidth(const double &width)
	{
		if (width > 0) _width = width;

		else std::cout << "Width must be greater than 0!" << std::endl;
	}

	void Parcel::setHeight(const double &height)
	{
		if (height > 0) _height = height;

		else std::cout << "Height must be greater than 0!" << std::endl;
	}

	void Parcel::setDepth(const double &depth)
	{
		if (depth > 0) _depth = depth;

		else std::cout << "Depth must be greater than 0!" << std::endl;
	}

	void Parcel::setWeight(const double &weight)
	{
		if (weight > 0) _weight = weight;

		else std::cout << "Weight must be greater than 0!" << std::endl;
	}

	void Parcel::setHazmat(const bool &hazmat)
	{
		if (hazmat) _hazmat = true;
		else _hazmat = false;
	}

	int Parcel::getSerial() const
	{
		return _serial;
	}

	double Parcel::getWidth() const
	{
		return _width;
	}

	double Parcel::getHeight() const
	{
		return _height;
	}

	double Parcel::getDepth() const
	{
		return _depth;
	}

	double Parcel::getWeight() const
	{
		return _weight;
	}

	double Parcel::getVolume()
	{
		_volume = _width*_height*_depth;
		return _volume;
	}

	bool Parcel::isHazmat() const
	{
		return _hazmat;
	}
}