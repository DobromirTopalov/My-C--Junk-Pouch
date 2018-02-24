
#include "Bitmap.h"

#include <iostream>

int main()
{
	const size_t MAX_SIZE = 100000; // Можете да промените този размер,
									// според това с колко големи
									// изображения искате да работите 

	unsigned int width, height, image[MAX_SIZE];

	int rval;

	// В последните три параметъра, функцията връща изображението и
	// размерите му
	rval = LoadBitmap("test.bmp", image, MAX_SIZE, width, height);

	if (rval != ALL_OK)
	{
		std::cerr << "Cannot load image data from test.bmp! Error code " << rval << "\n";
		return 1;
	}


	// Тук можете да добавите код, който решава задачата
	// Препоръчваме да разбиете решението си в една или повече подходящи функции
	// и тук да направите подходящи обръщения към тях.


	// По-долу предполагаме, че резултата от обработката е записан отново в масива image
	// и че width и height са променени така, че да съдържат размера на изрязаното изображение
	rval = SaveBitmap("test_new.bmp", image, width, height);

	if (rval != ALL_OK)
	{
		std::cerr << "Cannot save image data to test_new.bmp! Error code " << rval << "\n";
		return 2;
	}

    return 0;
}

