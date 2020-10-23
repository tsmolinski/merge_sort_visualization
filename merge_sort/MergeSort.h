#pragma once

#include "Block.h"

#include <vector>

using namespace std;

class MergeSort
{

public:
	// cons/dest
	MergeSort();
	~MergeSort();

	//public functions
	void mergeSort(std::vector<Block>& arr, int leftIndex, int rightIndex);
	void merge(std::vector<Block>& arr, int leftIndex, int middleIndex, int rightIndex);
	void sort(std::vector<Block>& arr);

	int compare(Block& a, Block& b);
};

