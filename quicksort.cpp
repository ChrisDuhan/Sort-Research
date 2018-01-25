#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(vector <int> data, int low, int high)
{
  int temp;
  temp = data[low];
  data[low] = data[high];
  data[high] = temp;
}

int partition(vector <int> data, int low, int high, int & comparisons)
{
	int pivot;    // pivot
	int smallIndex;
	swap(data, low, (low + high) / 2);
	pivot = data[low];
	smallIndex = low;

	for (int i = low + 1; i <= high - 1; ++i)
	{
		// If current element is smaller than or
		// equal to pivot
		if (++comparisons && data[i] < pivot)
		{
			++smallIndex;    // increment index of smaller element
			swap(data, smallIndex, i);
		}
	}
	swap(data, low, smallIndex);
	return smallIndex;
}

void quickSort(vector <int> data, int low, int high, int & comparisons)
{
	if (++comparisons && low < high)
	{
		int pi = partition(data, low, high, comparisons);

		quickSort(data, low, pi - 1, comparisons);
		quickSort(data, pi + 1, high, comparisons);
	}
}


int main() {
  vector <int>v;
  int c = 0;
  for(int i = 0; i < 50; ++i)
  {
    v.push_back(rand() + time(0) % 17);
  }
  for(int i = 0; i < 50; ++i)
  {
    cout << v[i] << " ";
  }
  cout << endl << endl;
  quickSort(v, 0, v.size() - 1,c);
  for(int i = 0; i < 50; ++i)
  {
    cout << v[i] << " ";
  }
  return 0;
}
