#include "Stringer.h"
#include <cstring>
Stringer::Stringer()
{
	pointerStr = NULL;
}

Stringer::Stringer(const char* initStr)
{
	pointerStr = NULL;
	setStringer(initStr);
}

Stringer::~Stringer()
{
	delete[] pointerStr;
	pointerStr = NULL;
	sizeOfStr = 0;
}

void Stringer::setStringer(const char* initStr)
{
	delete[] pointerStr;

	if (!initStr)
	{
		pointerStr = NULL;
		return;
	}
	sizeOfStr = strlen(initStr);
	pointerStr = new char[sizeOfStr + 1];
	strcpy(pointerStr, initStr);
}

const char* Stringer::getStringer() const
{
	return pointerStr;
}