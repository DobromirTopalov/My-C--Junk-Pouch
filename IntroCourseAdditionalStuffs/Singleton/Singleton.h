#pragma once
#include <string>

class Singleton {
private:
	static Singleton* ptr;

	int variable;
	Singleton() {
		variable = 0;
	}
	~Singleton() {}
public:
	static Singleton* getuniobj()
	{
		if (ptr == NULL)
		{
			ptr = new Singleton();
		}
		return ptr;

	}

	static void deleteSingleton()
	{
		delete ptr;
		ptr = NULL;
	}

	void setVar(int value)
	{
		variable = value;
	}
	void dosomething()
	{
		std::cout << "Value: " << variable << "\n";
	}

};