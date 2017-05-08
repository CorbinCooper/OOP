#include <iostream>
#include <vector>

#include "Engine.h"
#include "Piston.h"
#include "Wankel.h"
#include "Trans.h"

int main(int argc, char *argv[]) {
	engines::Engine *engine = new engines::Engine();
	engines::Piston *Piston = new engines::Piston(3, 6, 4);

	trans::Trans *T5 = new trans::Trans(false, true, false);

	std::cout << "T5 Transmisson: " << *T5 << std::endl;

	std::vector < engines::Engine* > engines;
	engines.push_back(new engines::Piston(3, 6, 4));
	engines.push_back(new engines::Engine());
	engines.push_back(new engines::Wankel(3, 1.5, 5, 3));

	for (auto engine : engines) {
		std::cout << "this engine's displacement is: " << engine->getDisp() << std::endl;
	}

	for (auto engine : engines) {
		delete engine;
	}

	std::cout << "Engine Displacement = " << engine->getDisp() << std::endl;

	std::cout << "Piston Engine Displacement = " << piston->getDisp() << std::endl;

	delete engine;
	delete piston;

	return 0;
}