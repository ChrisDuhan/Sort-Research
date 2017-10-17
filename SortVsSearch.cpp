#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void linearSearch(vector <int>, int, int&);
void binarySearch(vector <int>, int, int&);

const int DATA_SET_SIZE = 1000;
const int TESTS_ON_DATA = 1000;
const int NUM_ITEMS_SEARCHED_FOR = 1;

int main() // args[datasetsize, testsondata, numitemssearchedfor]
{
	ofstream out("data.dat");

	out << "DATA_SET_SIZE            " << DATA_SET_SIZE << endl;
	out << "TESTS_ON_DATA            " << TESTS_ON_DATA << endl;
	out << "NUM_ITEMS_SEARCHED_FOR    " << NUM_ITEMS_SEARCHED_FOR << endl << endl;

	for (int i = 0; i < TESTS_ON_DATA; ++i) // for this sample size
	{
		int avgComps = 0, comparisons = 0;
		vector <int> data; // create array
		for (int i = 0; i < DATA_SET_SIZE; ++i) // populate array
			data.push_back(rand() % 1000);

		for (int i = 0; i < NUM_ITEMS_SEARCHED_FOR; ++i) // search this many times
			linearSearch(data, (rand() % 1000), comparisons);

		avgComps = comparisons / NUM_ITEMS_SEARCHED_FOR;
		out << avgComps << endl;
	}

	return 0;
}

void linearSearch(vector <int> data, int val, int & comparisons)
{
	for (int i = 0; i <= data.size(); ++i)
	{
		if (++comparisons && val == data[i])
			return;
	}
	return;
}

void binarySearch(vector <int> data, int val, int & comparisons)
{
	int low = 0;
	int high = data.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (++comparisons && val < data[mid])
			high = mid - 1;
		else if (++comparisons && val > data[mid])
			low = mid + 1;
		else
			return;// data[mid];
	}
}
