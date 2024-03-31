#ifndef VECTOR_BUBBLE_SORT
#define VECTOR_BUBBLE_SORT

#include "Sort.h"
#include <vector>
#include <ctime>

template<class ItemType>
class vectorBubbleSort : public SortInterface<ItemType>
{
private:
	int number_of_comparisons;
	int number_of_swaps;
	double run_time;
public:
	vectorBubbleSort() //init variables in constructor
	{
		number_of_comparisons = 0;
		number_of_swaps = 0;
		run_time = 0;
	}

	void sort(vector<ItemType>& data)
	{
		clock_t start_time = clock();
		for (int i = 0; i < data.size() - 1; i++)
		{
			for (int j = 0; j < data.size() - 1; j++) //this one pass-through will bring the largest value to the top
			{
				if (data[j] > data[j + 1]) //swap elements
				{
					ItemType temp_val = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp_val;
					number_of_swaps++;
				}
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

	~vectorBubbleSort() { }
};

#endif