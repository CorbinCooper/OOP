#include <iostream>
#include <vector>
using namespace std;

class Observer;
class Subject;
class CoffeeMaker;
class BedroomLights;

class Subject {

private: vector <class Observer*> observers;
private: int timeState;
private: int presentState;

public: int getTimeState()
{
	return timeState;
}

public: void setTimeState(int timeState)
{
	this->timeState = timeState;
	notifyAllObservers("timeState");
}

public: int getPresentState()
{
	return presentState;
}

public: void setPresentState(int presentState)
{
	this->presentState = presentState;
	notifyAllObservers("presentState");
}

public: void attach(Observer *observer)
{
    cout << "anything" << endl;
	observers.push_back(observer);
}

public: void notifyAllObservers(string s);
};


class Observer {
protected: Subject subject;

public: virtual void update(string stateType) = 0;
};

void Subject::notifyAllObservers(string s)
{
    cout << observers.size() << endl;
	for (Observer *observer : observers)
	{
	    cout << "notify" << endl;
		observer->update(s);
	}
}

class CoffeeMaker : public Observer {

private: int coffeeMakerState;

public: int getCoffeeMakerState() {
	return coffeeMakerState;
}

public: CoffeeMaker(Subject subj) {
    cout << "coffee" << endl;
	this->subject = subj;
	this->subject.attach(this);
}

private: void updCoffee() {
	cout << "updating coffee maker" << endl;

	int currState = subject.getTimeState();

	if (subject.getPresentState() == 1) {
		switch (currState) {

		case 630:
			cout << "Turning the coffee maker on" << endl;
			coffeeMakerState = 1;
			break;

		case 730:
			cout << "Turning the coffee maker off" << endl;
			coffeeMakerState = 0;
			break;

		default:
			break;
		}
	}

	else if (coffeeMakerState == 1) {
		cout << "Turning the coffee maker off" << endl;

		coffeeMakerState = 0;
	}
}

public: void update(string s) {

    cout << "Test" << endl;

	if (s == "timeState") {
		updCoffee();
	}
}
};

class BedroomLights : public Observer {

private: int lightState;

public: int getLightState() {
	return lightState;
}

public: BedroomLights(Subject subj) {
	this->subject = subj;
	this->subject.attach(this);
}

private: void updLights() {
	cout << "updating lights" << endl;

	int currState = subject.getTimeState();

	switch (currState) {

	case 630:

	case 2145:

	case 9999:
		cout << "Turning bedroom lights on" << endl;
		lightState = 1;
		break;

	case 815:

	case 2330:
		cout << "Turning bedroom lights off" << endl;
		lightState = 0;
		break;

	default:
		break;
	}
}

private: void updPresentState() {

	int currState = subject.getPresentState();

	if (currState == 1) {
		cout << "updating presence" << endl;
		cout << "Welcome home" << endl;
	}

	else if (currState == 0) {
		cout << "updating presence" << endl;
		cout << "Goodbye" << endl;
	}

	else {
		cout << "out of range" << endl;
	}
}

public: void update(string s) {

	if (s == "timeState") {
		updLights();
	}

	else if (s == "presentState") {
		updPresentState();
	}
}
};

int main() {

	Subject subject = Subject();

	new BedroomLights(subject);
	new CoffeeMaker(subject);

	cout << "First state change:" << endl;
	subject.setPresentState(1);
	subject.setTimeState(630);
	cout << endl;

	cout << "Second state change:" << endl;
	subject.setTimeState(730);
	cout << endl;

	cout << "Third state change:" << endl;
	subject.setTimeState(815);
	subject.setPresentState(0);
	cout << endl;

	system("pause");
	return 0;
}
