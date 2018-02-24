#include <iostream>

void fillBuffer(int buffer[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> buffer[i];
	}
	buffer[size] = '\0';
}

void printBuffer(int buffer[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		std::cout << buffer[i]<<" , ";
	}
	std::cout<<buffer[size-1] << "\n";
}

void swapElement(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int sectio(int buffer[], int left, int right)
{
	int aim = buffer[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++)
	{
		if (buffer[j] <= aim)
		{
			i++;
			swapElement(buffer[i], buffer[j]);
		}
	}
	swapElement(buffer[i + 1], buffer[right]);
	return (i + 1);
}



void quickSort(int buffer[], int left, int right)
{
	if (left < right)
	{
		int part = sectio(buffer, left, right);
		quickSort(buffer, left, part - 1);
		quickSort(buffer, part + 1, right);
	}
}

void unite(int buffer[], int left, int mid, int right)
{
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	int* leftpart = new int[leftSize];
	int* rightpart = new int[rightSize];

	for (int i = 0; i < leftSize; i++)
	{
		leftpart[i] = buffer[left + i];
	}
	for (int j = 0; j < rightSize; j++)
	{
		rightpart[j] = buffer[mid + j + 1];
	}

	int l = 0;
	int r = 0;
	int k = left;
	while (l < leftSize && r < rightSize)
	{
		if (leftpart[l] <= rightpart[r])
		{
			buffer[k] = leftpart[l];
			l++;
		}
		else
		{
			buffer[k] = rightpart[r];
			r++;
		}
		k++;
	}

	while (l < leftSize)
	{
		buffer[k] = leftpart[l];
		l++;
		k++;
	}

	while (r < rightSize)
	{
		buffer[k] = rightpart[r];
		r++;
		k++;
	}

	delete[] leftpart;
	delete[] rightpart;
}

void mergeSort(int buffer[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(buffer, left, mid);
		mergeSort(buffer, mid + 1, right);

		unite(buffer,left,mid,right);
	}
}

int main()
{
	int buffer[10000];
	int size;
	std::cout << "Enter the number of characters and the sequence of them here: ";
	std::cin >> size;
	fillBuffer(buffer, size);
	std::cout << "\nHere is the sequence: ";
	printBuffer(buffer, size);

	std::cout << "-------sequence has been sorted!\n";
	//quickSort(buffer, 0, size-1);
	mergeSort(buffer, 0, size - 1);
	printBuffer(buffer, size);

	return 0;
}

/*

void merge(int arr[], int left, int mid, int right)
{

int n1 = mid - left + 1;		//size of left part
int n2 = right - mid;			//size of right part

	//temp arrays creation
int* L = new int[n1];			//left arr
int* R = new int[n2];			//right arr

								// Copy data to temp arrays L[] and R[]
for (int i = 0; i < n1; i++)			//till size of arr
	L[i] = arr[left + i];				//beginning of arr will be left+i
for (int j = 0; j < n2; j++)
	R[j] = arr[mid + 1 + j];			//beginning of arr will be mid+1+j

										// Merge the temp arrays back into arr[l..r]
int i = 0; // Initial index of first subarray
int j = 0; // Initial index of second subarray
int k = left; // Initial index of merged subarray
while (i < n1 && j < n2)
{
	if (L[i] <= R[j])
	{
		arr[k] = L[i];
		i++;
	}
	else
	{
		arr[k] = R[j];
		j++;
	}
	k++;
}

// Copy the remaining elements of L[], if there
are any 
while (i < n1)
{
	arr[k] = L[i];
	i++;
	k++;
}

// Copy the remaining elements of R[], if there
are any 
while (j < n2)
{
	arr[k] = R[j];
	j++;
	k++;
}
delete[] R;
delete[] L;
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted 
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

*/