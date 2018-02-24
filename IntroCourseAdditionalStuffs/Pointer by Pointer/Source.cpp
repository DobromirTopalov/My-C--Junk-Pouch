#include <iostream>

int* copy(int** arr1, int* arr2)
{
	int* newarr = new int[5];
	for (int i=0;i<5;i++)
	{
		newarr[i] = arr2[i];
	}
	delete[] *arr1;
	*arr1 = newarr;
	newarr = nullptr;
	
	std::cout << (newarr == NULL ? "NULL" : "not NULL") << std::endl;

	return *arr1;
}

void print(int* arr)
{
	for (int i = 0; i<4; i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout << arr[4] << "\n";
}

int main()
{
	int size = 5;
	int* dobri = new int[size] {3, 8, 7, 4, 6};
	int* blagoi = new int[size] {8, 8, 8, 8, 8};

	print(dobri);
	print(blagoi);
	std::cout << "After copy___________>\n";
	copy(&dobri, blagoi);
	print(dobri);
	print(blagoi);


	std::cout << *dobri << " before delete\n";
	std::cout << dobri << " before delete\n";
	delete[] dobri;
	delete[] blagoi;
	std::cout << *dobri <<" after delete\n";
	std::cout << dobri	<< " after delete\n";
	dobri = nullptr;
	blagoi = nullptr;
	std::cout << (dobri == NULL ? "NULL" : "not NULL") << std::endl;
	std::cout << (blagoi == NULL ? "NULL" : "not NULL") <<std::endl;

	
	return 0;
}






/*
In this function, char *cp is a "pointer being passed by copy" what means that they are pointing to the same memory address 
but they are not the same pointer. When you change the pointer inside, making it to point somewhere else, the original pointer
that has been passed will keep pointing to 0.

int main(){
char *cp = 0;
func(cp);
//code
delete[] cp;
}

void func(char *cp){
cp = new char[100];
}


int main() {
int* pt = allocate(5);
deallocate(pt);
cout << (pt == NULL ? "NULL" : "not NULL") << endl;
return 0;
}

*/