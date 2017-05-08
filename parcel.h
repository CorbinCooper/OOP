#pragma once

namespace parcels
{
	class Parcel {

	private: int _serial;
	private: double _width;
	private: double _height;
	private: double _depth;
	private: double _volume;
	private: double _weight;
	private: bool _hazmat;

	public: Parcel();
	public: Parcel(const int &serial, const double &width, const double &height,
		const double &depth, const double &weight, const bool &hazmat);

	public: void genSerial();
	public: void setWidth(const double &width);
	public: void setHeight(const double &height);
	public: void setDepth(const double &depth);
	public: void setWeight(const double &weight);
	public: void setHazmat(const bool &hazmat);

	public: int getSerial() const;
	public: double getWidth() const;
	public: double getHeight() const;
	public: double getDepth() const;
	public: virtual double getVolume();
	public: virtual double getWeight() const;
	public: virtual bool isHazmat() const;

	};
}