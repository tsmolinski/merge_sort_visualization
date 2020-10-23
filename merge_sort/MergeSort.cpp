#include "MergeSort.h"

// cons/dest
MergeSort::MergeSort()
{
}

MergeSort::~MergeSort()
{
}

// public functions
void MergeSort::mergeSort(std::vector<Block>& arr, int leftIndex, int rightIndex)
{

	if (leftIndex < rightIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;

		mergeSort(arr, leftIndex, middleIndex);
		mergeSort(arr, middleIndex + 1, rightIndex);

		merge(arr, leftIndex, middleIndex, rightIndex);
	}

}

void MergeSort::merge(std::vector<Block>& arr, int leftIndex, int middleIndex, int rightIndex)
{
	vector<Block> tmp;

	// just copy arr to tmp
	for (int i = leftIndex; i <= rightIndex; ++i)
	{
		tmp.push_back(arr[i]);
	}



	int i = leftIndex;
	int j = middleIndex + 1;
	int n = 0;  // = leftIndex

	// merge L and R
	while (i <= middleIndex && j <= rightIndex)
	{
		// zamienic na <, "stable sort", powinno sie zachowac kolejnosc
		//if (arr[i] < arr[j])
		if (compare(arr[i], arr[j]) <= 0)
		{
			tmp[n] = arr[i];
			i++;
		}
		else
		{
			tmp[n] = arr[j];
			j++;
		}
		++n;
	}

	// merge rest L or R (if is any) and arr[]
	while (i <= middleIndex)
	{
		tmp[n] = arr[i]; //TU  dodac???
		i++;
		n++;
	}
	while (j <= rightIndex)
	{
		tmp[n] = arr[j];
		j++;
		n++;
	}

	for (int i = leftIndex; i <= rightIndex; ++i)
	{
		arr[i] = tmp[i - leftIndex];
	}
}

void MergeSort::sort(std::vector<Block>& arr)
{
	mergeSort(arr, 0, arr.size() - 1);
}

int MergeSort::compare(Block& a, Block& b)
{
	return (a < b ? -1 : (a > b ? 1 : 0));
}
