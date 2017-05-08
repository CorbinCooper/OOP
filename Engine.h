#pragma once

namespace engines
{
	class Engine {
	public: Engine();
	public: virtual double getDisp() const;
	public: virtual ~Engine();
	};
}