#include "Visualization.h"
#include <vector>

using namespace std;

void merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
	int* L = new int[(middleIndex - leftIndex + 1)];
	int* R = new int[(rightIndex - middleIndex)];

	//int L[(middleIndex - leftIndex + 1)];
	//int R[(rightIndex - middleIndex)];

	// copy subarrays, Left and Right
	for (int i = 0; i < (middleIndex - leftIndex + 1); i++)
	{
		L[i] = arr[leftIndex + i];
	}

	for (int j = 0; j < (rightIndex - middleIndex); j++)
	{
		R[j] = arr[(middleIndex + 1 + j)];
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
			i++;
		}
		else
		{
			arr[n] = R[j];
			j++;
		}
		n++;
	}

	// merge rest L or R (if is any) and arr[]
	while (i < (middleIndex - leftIndex + 1))
	{
		arr[n] = L[i];
		i++;
		n++;
	}
	while (j < (rightIndex - middleIndex))
	{
		arr[n] = R[j];
		j++;
		n++;
	}

	delete[] L;
	delete[] R;

}

void sort(int arr[], int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;

		sort(arr, leftIndex, middleIndex);
		sort(arr, middleIndex + 1, rightIndex);

		merge(arr, leftIndex, middleIndex, rightIndex);
	}
}

int main()
{
	srand((time(0)));

	Visualization vis;
	//vector<Block*> blocks;
	//Block blocks(20.f, 100.f, 50.f, 150.f);

	int array[10];

	//for (int i = 0; i < )

	//while (vis.running())
	//{
	//	vis.update();
	//	vis.render();
	//}

	cout << "Przed: ";
	for (int i = 0; i < 10; i++)
	{
		int num = (rand() % 50) + 1;

		array[i] = num;
		cout << array[i] << ", ";
	}

	sort(array, 0, 9);
	cout << "\n" << "Po: ";

	for (int k = 0; k < 10; k++)
	{
		cout << array[k] << ", ";
	}

	return 0;
}
