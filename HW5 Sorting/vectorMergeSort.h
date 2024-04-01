#ifndef VECTOR_MERGE_SORT
#define VECTOR_MERGE_SORT

#include "Sort.h"
#include <vector>
#include <ctime>

template<class ItemType>
class vectorMergeSort : public SortInterface<ItemType>
{
private:
	double number_of_comparisons;
	double number_of_swaps;
	double run_time;
public:
	vectorMergeSort() //init variables in constructor
	{
		number_of_comparisons = 0;
		number_of_swaps = 0;
		run_time = 0;
	}

	void sort(vector<ItemType>& data)
	{
		clock_t start_time = clock();
		if (data.size() > 1)
		{
			int mid_pos = data.size() / 2;
			vector<int> left_vector;
			vector<int> right_vector;

			//left array
			for (auto i = data.begin(); i != data.begin() + mid_pos; i++)
			{
				left_vector.push_back(*i);
			}

			//right array
			for (auto i = data.begin() + mid_pos; i != data.end(); i++)
			{
				right_vector.push_back(*i);
			}

			//recursion
			sort(left_vector);
			sort(right_vector);

			int i = 0, j = 0, k = 0;
			while (i < left_vector.size() && j < right_vector.size())
			{
				if (left_vector[i] < right_vector[j])
				{
					data[k] = left_vector[i];
					i++;
					number_of_comparisons++;
				}
				else
				{
					data[k] = right_vector[j];
					j++;
					number_of_comparisons++;
				}
				k++;
			}

			while (i < left_vector.size())
			{
				data[k] = left_vector[i];
				i++;
				k++;
				number_of_comparisons++;
			}

			while (j < right_vector.size())
			{
				data[k] = right_vector[j];
				j++;
				k++;
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

	~vectorMergeSort() { }
};

#endif