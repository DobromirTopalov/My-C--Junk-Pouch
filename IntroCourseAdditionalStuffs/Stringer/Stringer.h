#pragma once

class Stringer
{
private:
	char* pointerStr;
	unsigned int sizeOfStr;

public:
	Stringer();
	Stringer(const char* initStr);
		void setStringer(const char* initStr);
		const char* getStringer() const;
	~Stringer();


};