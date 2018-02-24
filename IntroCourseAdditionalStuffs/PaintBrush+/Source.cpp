#include <iostream>
#include <iomanip>

bool paintbrush(char** pixels, int i, int j,char sign)
{
	if (pixels[i][j] == 'B')
	{
		return 	false;
	}
	else if (pixels[i][j] == sign)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void draw(char** pixels,int height,int width, int i, int j, char sign)
{
	if (paintbrush(pixels, i, j,sign))
	{
		pixels[i][j] = sign;
		if (((height > i - 1) && (0 <= i - 1)) && ((0 <= j) && (j < width)))
		{
			draw(pixels,height,width, i-1, j, sign);
		}
		if (((height > i + 1) && (0 <= i + 1)) && ((0 <= j) && (j < width)))
		{
			draw(pixels, height, width, i+1, j, sign);
		}
		if (((height > i) && (0 <= i)) && ((0 <= j - 1) && (j - 1 < width)))
		{
			draw(pixels, height, width, i, j-1, sign);
		}
		if (((height > i) && (0 <= i)) && ((0 <= j + 1) && (j + 1 < width)))
		{
			draw(pixels, height, width, i, j+1, sign);
		}
	}
	
}

void printPixels(char** pixels,int height,int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << pixels[i][j] << std::setw(3);
		}
		std::cout << "\n";
	}
}

void fillPixels(char** pixels, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cin >> pixels[i][j];
		}
	}
}

int main()
{
	int height, width;
	std::cout << "Enter sheet size: ";
	std::cin >> height >> width;

	char** pixels = new char*[height];
	for (int i = 0; i < height; i++)
	{
		pixels[i] = new char;
	}

	std::cout << "Start drawing a shape: \n";
	fillPixels(pixels, height, width);
	std::cout << "This is your masterpiece!: \n";
	printPixels(pixels, height, width);
	std::cout << "\n\n\t\t\t Enter a symbol or color to paint your masterpiece + pixels (i,j)!: ";
	char sign;
	int pixelI, pixelJ;
	std::cin >> sign >> pixelI >> pixelJ;

	draw(pixels, height, width, pixelI, pixelJ, sign);
	std::cout << "\n\n\t\t\t Finally : \n";
	printPixels(pixels, height, width);
	std::cout << "\n\n\n";

	return 0;
}