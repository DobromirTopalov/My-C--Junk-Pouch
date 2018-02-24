#pragma once
#include <cstring>											

class Dynamic {
private:
	char* memoryBox;										
	int size;
	int capacity;

public:
	Dynamic();												// pravilno li sum napisal operatorite i 4kata
	Dynamic(const char* string);							// dobre li sum izpolzval heapa i pointerite
	Dynamic(const Dynamic& obj);							// kude i zashto izticha pamet,ako izticha
	Dynamic& operator=(const Dynamic& obj);
	Dynamic operator+(const Dynamic& obj);
	~Dynamic();

	char operator[](int a);									

	void add(const char* neshto);					//dobavq element/tekst v kraq
	void insert(const char* neshto,int a);			//vmukva element/tekst na dadena poziciq
	void del(int value);							//reje kolkoto elementa si zadal ot kraq
	int changeCap();								//promenqm capacity (ama ne mi e qsno mnogo s kolko da go smenqm i koga i zashto,kak)
	void clear();									//trie vsichko

	int length();									//dava duljinata na obekta(mislq che bez da hvashta '\0')
	bool isEmpty();									//true-ako ima neshto vutre/false-ako nqma
	char* getBox();									//vzimam teksta v chlen dannata
	int getSize();									//vzimam size chlen dannata a ne siza na obekta

};