#include <conio.h>
#include <cstdio>
#include <iostream>

//#define STATE_1
#define STATE



#ifdef STATE

class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual    char* ToString() = 0;
};

// State Locked
class Locked : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Locked";
	}
};

// State Closed
class Closed : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Closed";
	}
};

// State Opened
class Opened : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Opened";
	}
};


StateBase* Locked::GetNextState() {
	return new Closed();	
}

StateBase* Closed::GetNextState() {
	//srand(time(NULL));
	//int res = rand() % (1 - 0 + 1) + 0; // about [0;1]
	if (true) {
		return new Opened();
	}
	else {
		return new Locked(); 
	}
}

StateBase* Opened::GetNextState() {
	return new Closed();
}

class Door
{
public:
	Door() {}
	Door(StateBase* pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	}
	// Handles the next state
	void StateChanged() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}
protected:
	StateBase* m_pState;
};

#endif

void main()
{

#ifdef STATE

	Door objSun(new Locked);
	printf("Door %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door %s !!!\n\n", objSun.GetStateName());

#endif

	system("pause");

}