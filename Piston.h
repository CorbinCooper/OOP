#pragma once

#include "Engine.h"
#include "Drivetrain.h"

namespace engines
{
	class Piston : public Engine, public Drivetrain {
	private: double _bore;
	private: double _stroke;
	private: double _cyls;
	private: double _disp;

	private: Trans _trans;
	public: Trans getTrans() const { return _trans; }
	public: void setTrans(const Trans &value) { _trans = value; }

	public: Piston(const double &bore, const double &stroke, const double &cyls);

	public: double getBore() const;
	public: void setBore(const double &value);

	public: double getStroke() const;
	public: void setStroke(const double &value);

	public: double getCyls() const;
	public: void setCyls(const double &value);

	public: double getDisp() const;

	private: void updateDisp();

	};
}