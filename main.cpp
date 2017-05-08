#include <iostream>
#include <iomanip>
#include <string>

#include "parcel.h"

using namespace std;

void displayParcels(parcels::Parcel parcelList[])
{
	cout << setw(55) << setfill('*') << ' ' << endl;
	cout << setfill(' ') << left;
	cout << setw(9) << "| Serial" << setw(17) << "| Description" << setw(9) << "| Volume" <<
		setw(9) << "| Weight" << "| Hazmat |" << endl;
	cout << setw(54) << setfill('*') << ' ' << endl;
	cout << setfill(' ');

	char hazmat = 'N';

	for (int i = 0; i < 19; i++)
	{
		if (parcelList[i].isHazmat() == 1) hazmat = 'Y';
		if (parcelList[i].getSerial() > 0)
		{
			cout << "| " << parcelList[i].getSerial() << " | " << setw(15) << "Something" << "| " << setw(7) << parcelList[i].getVolume() <<
				"| " << setw(7) << parcelList[i].getWeight() << "| " << setw(7) << hazmat << "|" << endl;
		}
	}

	cout << setw(54) << setfill('*') << ' ' << endl;
}

void addParcel(parcels::Parcel parcelList[], int count)
{
	double width, height, depth, weight;
	char HM;
	bool hazmat;

	parcelList[count].genSerial();

	cout << "Enter width: ";
	cin >> width;
	parcelList[count].setWidth(width);

	cout << "Enter height: ";
	cin >> height;
	parcelList[count].setHeight(height);

	cout << "Enter depth: ";
	cin >> depth;
	parcelList[count].setDepth(depth);

	cout << "Enter weight: ";
	cin >> weight;
	parcelList[count].setWeight(weight);

	cout << "Hazardous Material? Y/N";
	cin >> HM;
	if (HM == 'Y' || HM == 'y')
		parcelList[count].setHazmat(true);
	else
		parcelList[count].setHazmat(false);
}

void main()
{
	parcels::Parcel not_assigned[20];

	int choice, count = 0;

	do {

		cin >> choice;


		switch (choice) {

		case 1:
			displayParcels(not_assigned);
			break;

		case 2:
			addParcel(not_assigned, count);
			count++;
			break;

		case 0:
			break;

		default:
			cout << "Invalid choice";
		}

	} while (choice != 0);


	system("pause");
}