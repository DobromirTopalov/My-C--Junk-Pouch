#include <iostream>
#include "Singleton.h"

Singleton* Singleton::ptr = NULL;

int main()
{
	Singleton *ptr1=Singleton::getuniobj();
	Singleton *ptr2=Singleton::getuniobj();

	ptr1->dosomething();
	ptr2->setVar(10);
	ptr1->dosomething();
	ptr2->setVar(7);
	ptr1->setVar(5);
	ptr2->dosomething();
	ptr1->dosomething();
	ptr1->setVar(0);
	ptr2->dosomething();



	return 0;
}