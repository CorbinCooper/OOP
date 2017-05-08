#pragma once

#include "Engine.h"
#include "Drivetrain.h"

namespace engines
{
	class Wankel : public Engine, public Drivetrain {
	private: double _width;
	private: double _eccen;
	private: double _length;
	private: double _rotors;

	private: trans _trans;
	public: trans getTrans() const { return _trans; }
	public: void setTrans(const trans &value) { _trans = value; }

	public: Wankel(const double &width, const double &eccen, 
		const double &length, const double &rotors);

	public: double getWidth() const;
	public: void setWidth(const double &value);

	public: double getEccen() const;
	public: void setEccen(const double &value);

	public: double getLength() const;
	public: void setLength(const double &value);

	public: double getRotors() const;
	public: void setRotors(const double &value);

	public: double getDisp() const;

	private: void updateDisp();

	};
}