#include <iostream>

namespace {
	int kk = 9;
	namespace one 
	{
		int k = 1;
		int kk = 7;
		namespace {
			int kk = 8;
			namespace two
			{
				int k = 2;
				int kk = 10;
			}
		}
	}
}


//using namespace one;
//using namespace two;

int main()
{
	std::cout << one::k << " and " << one::two::k << "\n";
	std::cout << one::kk << " and " << kk << " and " << one::two::kk<<" or "<<one::kk << "\n";


	// kak da dostupq kk=8?
	return 0;
}