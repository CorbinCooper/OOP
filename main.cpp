#include <iostream>
#include <string>
#include <vector>

#include "Shootable.h"
#include "Stryfe.h"
#include "Clipable.h"
#include "Series.h"

void main()
{
	/*
	std::cout << "new Shooter" << std::endl;
	shoots::Shootable *shooter = new shoots::Shootable();
	*/

	nerf::Series *Nstrike = new nerf::Series();

	std::cout << "new Stryfe" << std::endl;
	shoots::Stryfe *stryfe = new shoots::Stryfe(*Nstrike, "Mad Max", 19.99);

	std::cout << stryfe->getName() << std::endl << "MSRP: " << stryfe->getMSRP() << std::endl;
	stryfe->fire();
	stryfe->clip();

	system("pause");

	delete Nstrike;

}