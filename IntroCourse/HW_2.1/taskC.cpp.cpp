/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 2C
* @compiler VC
*
*/

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







	//Долният код може да бъде направен на функция,която да взима стойностите нужни за for-овете, но реших да ги оставя така.
	//Видях ви препоръката, въпреки това, така ми бе по-удобно.
	//Говоря за тези блокове find LeftLimit,RightLimit,TopLimit,BottomLimit
	//Би могло да има и функция за cut, подобно на find 
	//Знам, че не бива, че е лоша практика, повтаря се кода,води до грешки ...


	unsigned int* newImage = new unsigned int[MAX_SIZE];
	for (int i = 0; i < width*height; i++)
	{
		newImage[i] = false;
	}

	//find LeftLimit
	unsigned int saveLeft;
	bool different = false;

	for (int i = 0; i < width; i++)
	{
		if (different)
		{
			break;
		}
		for (int j = i; j < width*height; j += width)
		{
			if (image[j] != 0xFFFFFFFF)
			{
				//image[j] = 0xFFF33FFF;
				saveLeft = i;
				different = true;
				break;
			}
		}
	}

	//cut from left
	for (int i = saveLeft; i < width; i++)
	{
		for (int j = i; j < width*height; j += width)
		{
			newImage[j] = image[j];
		}
	}

	//find RightLimit
	unsigned int saveRight;
	bool different2 = false;

	for (int i = width - 1; i >= 0; i--)
	{
		if (different2)
		{
			break;
		}
		for (int j = i; j < width*height; j += width)
		{
			if (image[j] != 0xFFFFFFFF)
			{
				//newImage[j] = 0xFFF33FFF;
				saveRight = i;
				different2 = true;
				break;
			}
		}
	}

	//cut from right
	for (int i = saveRight + 1; i < width; i++)
	{
		for (int j = i; j < width*height; j += width)
		{
			newImage[j] = false;
		}
	}

	//find TopLimit
	unsigned int saveTop;
	bool different3 = false;

	for (int i = 0; i < height; i++)
	{
		if (different3)
		{
			break;
		}
		for (int j = i*width + 1; j < (i + 1) * width; j++)
		{
			if (image[j] != 0xFFFFFFFF)
			{
				//newImage[j] = 0xFFF33FFF;
				saveTop = i;
				different3 = true;
				break;
			}
		}

	}

	//cut from top
	for (int i = saveTop - 1; i >= 0; i--)
	{
		for (int j = i*width + 0; j < (i + 1) * width; j++)
		{
			newImage[j] = false;
		}
	}

	//find BottomLimit
	unsigned int saveBottom;
	bool different4 = false;

	for (int i = height - 1; i >= 0; i--)
	{
		if (different4)
		{
			break;
		}
		for (int j = i*(width); j < i*(width)+width; j++)
		{
			if (image[j] != 0xFFFFFFFF)
			{
				//newImage[j] = 0xFFF33FFF;
				saveBottom = i;
				different4 = true;
				break;
			}
		}
	}

	//cut from bottom
	for (int i = saveBottom + 1; i < height; i++)
	{
		for (int j = i*width; j < i * width + width; j++)
		{
			newImage[j] = false;
		}
	}

	/*
	std::cout << saveLeft << "\n" << saveRight << "\n" << saveTop << "\n" << saveBottom << "\n";

	saveLeft--;
	saveRight++;
	saveTop--;
	saveBottom++;
	*/


	unsigned int width2, height2;
	width2 = width - (width - saveRight) - (saveLeft - 1);
	height2 = height - (height - saveBottom) - (saveTop - 1);

//	std::cout << "Original: " << width << " and " << height << "\n";
//	std::cout << "New: " << width2 << " and " << height2 << "\n";


	unsigned int* finalImage = new unsigned int[width2 * height2];
	for (int i = 0, k = 0; i < width*height; i++)
	{
		if (newImage[i] != false)
		{
			//std::cout << "yes ";
			finalImage[k] = newImage[i];
			k++;
		}
	}


	/*
	// По-долу предполагаме, че резултата от обработката е записан отново в масива image
	// и че width и height са променени така, че да съдържат размера на изрязаното изображение
	int pixelsCount = width * height;
	for (int i = 0; i < pixelsCount; ++i)
	image[i] = 0xFFFFFFFF;
	*/


	rval = SaveBitmap("test_new.bmp", finalImage, width2, height2);
	if (rval != ALL_OK)
	{
		std::cerr << "Cannot save image data to test_new.bmp! Error code " << rval << "\n";
		return 2;
	}



	delete[] newImage;
	delete[] finalImage;

	return 0;
}
