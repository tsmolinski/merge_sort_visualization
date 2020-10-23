#include "Visualization.h"
#include <vector>

using namespace std;


int main()
{
	srand((time(0)));

	Visualization vis;

	//vector<int> array;

	//MergeSort sort;

	//for (int i = 0; i < 10; i++)
	//{
	//	blocks[i] = new Block(rand() % 50);
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

	//	//array.push_back(new int (num));
	//	array.push_back(num);
	//	cout << array[i] << ", ";
	//}

	//mergeSort(array, 0, 9);
	//cout << "\nPo: ";

	//for (int k = 0; k < 10; k++)
	//{
	//	cout << array[k] << ", ";
	//}

	return 0;
}
