#include<iostream>
#include<list>
using namespace std;

// class base
class BaseObject {
private:
	int m_id;
	string m_name;
	int m_position;
public:
	BaseObject() 
	{
		
	}

	~BaseObject() 
	{
		cout << "huy base"<<endl;
	}
	// get Name
	virtual void getName() {}
	// get Id
	virtual void getId() {}
	// move object
	virtual void move() {}
	// print object
	virtual void printPosition() {}
};

//class static
class StaticObject:public BaseObject {
public:
	StaticObject(){}
	~StaticObject() { cout << "huy static"<<endl; }
	void move()
	{
		cout << "khong the di chuyen"<<endl;
	}
};

//class dynamic
class DynamicObject :public BaseObject {
public:
	DynamicObject(){}
	~DynamicObject() { cout << "huy Dynamic"<<endl; }
	
};

//class tree
class Tree :public StaticObject {
public:
	static int m_countTree;
	Tree(){}
	~Tree() { cout << "huy tree"<<endl; }
	void getName()
	{
		m_countTree += 1;
		cout << "Tree: " << m_countTree<<endl;
	}
	void getId()
	{
		cout << "Id Tree: " << m_countTree<<endl;
	}
	void printPosition()
	{
		cout << "Position Tree: " << m_countTree << endl;
	}
};
int Tree::m_countTree = 0;
//class house
class House :public StaticObject {
public:
	static int m_countHouse;
	House() {}
	~House() { cout << "huy house"; }
	void getName()
	{
		m_countHouse += 1;
		cout << "House: " << m_countHouse << endl;
	}
	void getId()
	{
		cout << "Id House: " << m_countHouse << endl;
	}
	void printPosition()
	{
		cout << "Position House: " << m_countHouse << endl;
	}
};
int House::m_countHouse = 0;
//class motobike
class Motobike :public DynamicObject {
public:
	static int m_countMotobike;
	Motobike() {}
	~Motobike() { cout << "huy motobike"; }
	void getName()
	{
		m_countMotobike += 1;
		cout << "Motobike: " << m_countMotobike << endl;
	}
	void getId()
	{
		cout << "Id Motobike: " << m_countMotobike << endl;
	}
	void move()
	{
		cout << "move Motobike: " << m_countMotobike << endl;
	}
	void printPosition()
	{
		cout << "Position Motobike: " << m_countMotobike << endl;
	}
};
int Motobike::m_countMotobike = 0;
//class car
class Car : public DynamicObject {
public:
	static int m_countCar;
	Car() {}
	~Car() { cout << "huy car"; }
	void getName()
	{
		m_countCar += 1;
		cout << "Car: " << m_countCar << endl;
	}
	void getId()
	{
		cout << "Id Car: " << m_countCar << endl;
	}
	void move() 
	{
		cout << "move Car: " << m_countCar << endl;
	}
	void printPosition() 
	{
		cout << "Position Car: " << m_countCar << endl;
	}
};
int Car::m_countCar = 0;
//main
int main() 
{
	Tree ob[10];
	list<Tree> listObj;
	for (int i = 0; i < 10; i++)
	{
		//ob[i] = new Tree();
		listObj.push_back(ob[i]);
	}
	for (auto obj : listObj)
	{
		obj.getName();
		obj.getId();
		obj.move();
		obj.printPosition();
	}
	//delete[] ob;
	listObj.clear();
	
}
