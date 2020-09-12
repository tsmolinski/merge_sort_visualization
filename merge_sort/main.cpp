#include "Visualization.h"
#include <vector>

using namespace std;

void merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
//void merge(vector<int> vec, int leftIndex, int middleIndex, int rightIndex)
{
	int* L = new int[(middleIndex - leftIndex + 1)];
	int* R = new int[(rightIndex - middleIndex)];
	//vector<int> L;
	//vector<int> R;

	// copy subarrays, Left and Right
	for (int i = 0; i < (middleIndex - leftIndex + 1); i++)
	{
		L[i] = arr[leftIndex + i];
		//L.push_back(vec[leftIndex + i]);
	}

	for (int j = 0; j < (rightIndex - middleIndex); j++)
	{
		R[j] = arr[(middleIndex + 1 + j)];
		//R.push_back(vec[middleIndex + 1 + j]);
	}


	int i = 0;
	int j = 0;
	int n = leftIndex;

	// merge L and R
	while (i < (middleIndex - leftIndex + 1) && j < (rightIndex - middleIndex))
	{
		if (L[i] <= R[j])
		{
			arr[n] = L[i];
			//vec[n] = L[i];
			i++;
		}
		else
		{
			arr[n] = R[j];
			//vec[n] = R[j];
			j++;
		}
		n++;
	}

	// merge rest L or R (if is any) and arr[]
	while (i < (middleIndex - leftIndex + 1))
	{
		arr[n] = L[i];
		//vec[n] = L[i];
		i++;
		n++;
	}
	while (j < (rightIndex - middleIndex))
	{
		arr[n] = R[j];
		//vec[n] = R[j];
		j++;
		n++;
	}

	delete[] L;
	delete[] R;

}

void sort(int arr[], int leftIndex, int rightIndex)
//void sort(vector<int> vec, int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;

		sort(arr, leftIndex, middleIndex);
		sort(arr, middleIndex + 1, rightIndex);
		//sort(vec, leftIndex, middleIndex);
		//sort(vec, middleIndex + 1, rightIndex);

		merge(arr, leftIndex, middleIndex, rightIndex);
		//merge(vec, leftIndex, middleIndex, rightIndex);
	}
}

int main()
{
	srand((time(0)));

	Visualization vis;
	//Block* blocks[10];

	//int array[10];

	//for (int i = 0; i < 10; i++)
	//{
	//	blocks[i] = new Block(20.f, (rand() % 50) + 1, i * 20.f + 10.f, 20.f);
	//}

	while (vis.running())
	{
		vis.update();
		vis.render();
	}

	//cout << "Przed: ";
	//for (int i = 0; i < 10; i++)
	//{
	//	int num = (rand() % 50) + 1;

	//	array[i] = num;
	//	cout << array[i] << ", ";
	//	//v1.push_back(num);
	//	//cout << v1[i] << ", ";
	//}

	//sort(array, 0, 9);
	////sort(v1, 0, 9);
	//cout << "\n" << "Po: ";

	//for (int k = 0; k < 10; k++)
	//{
	//	cout << array[k] << ", ";
	//	//cout << v1[k] << ", ";
	//}

	return 0;
}
