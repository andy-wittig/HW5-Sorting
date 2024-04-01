#ifndef VECTOR_INSERTION_SORT
#define VECTOR_INSERTION_SORT

#include "Sort.h"
#include <vector>
#include <ctime>

template<class ItemType>
class vectorInsertionSort : public SortInterface<ItemType>
{
private:
	double number_of_comparisons;
	double number_of_swaps;
	double run_time;
public:
	vectorInsertionSort() //init variables in constructor
	{
		number_of_comparisons = 0;
		number_of_swaps = 0;
		run_time = 0;
	}

	void sort(vector<ItemType>& data)
	{
		clock_t start_time = clock();
		for (int i = 1; i < data.size(); i++)
		{
			int j = i - 1;
			ItemType key = data[i];

			while (j >= 0 && data[j] > key)
			{
				ItemType temp_val = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp_val;
				j--;
				number_of_swaps++;
				number_of_comparisons++;
			}
		}
		clock_t end_time = clock();
		run_time = double(end_time - start_time);
	}

	int getComparisons() { return number_of_comparisons; }

	int getSwaps() { return number_of_swaps; }

	double getRuntime() { return run_time; }

	void resetInformation()
	{
		number_of_comparisons = 0;
		number_of_swaps = 0;
		run_time = 0;
	}

	~vectorInsertionSort() { }
};

#endif