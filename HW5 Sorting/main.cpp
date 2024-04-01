#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

#include "vectorBubbleSort.h"
#include "vectorMergeSort.h"
#include "vectorInsertionSort.h"

void generateRandVect(vector<int>& vect, int size);
void sortVector(SortInterface<int>&, vector<int>& vect, int size, int times_sorted);
void displayVector(vector<int>& vect);

int getMenuChoice();

int main()
{
	srand(time(NULL)); //initalize random numbers using local time as seed

	vectorBubbleSort<int> bubble_sorter;
	vectorMergeSort<int> merge_sorter;
	vectorInsertionSort<int> insert_sorter;

	vector<int> rand_vect;

	cout << "Welcome to the vector sorter!" << endl;

    int menuChoice; //menu logic
    do
    {
        menuChoice = getMenuChoice();

        switch (menuChoice) {
        case 1:
			cout << "\nBubble sort of size 1000:" << endl;
            sortVector(bubble_sorter, rand_vect, 1000, 10);
			cout << "\nBubble sort of size 10000:" << endl;
			sortVector(bubble_sorter, rand_vect, 10000, 10);
			cout << "\nBubble sort of size 100000:" << endl;
			sortVector(bubble_sorter, rand_vect, 100000, 10);
            break;
		case 2:
			cout << "\nMerge sort of size 1000:" << endl;
			sortVector(merge_sorter, rand_vect, 1000, 10);
			cout << "\nMerge sort of size 10000:" << endl;
			sortVector(merge_sorter, rand_vect, 10000, 10);
			cout << "\nMerge sort of size 100000:" << endl;
			sortVector(merge_sorter, rand_vect, 100000, 10);
			break;
		case 3:
			cout << "\nInsertion sort of size 1000:" << endl;
			sortVector(insert_sorter, rand_vect, 1000, 10);
			cout << "\nInsertion sort of size 10000:" << endl;
			sortVector(insert_sorter, rand_vect, 10000, 10);
			cout << "\nInsertion sort of size 100000:" << endl;
			sortVector(insert_sorter, rand_vect, 100000, 10);
			break;
        case 0:
            break;
        default:
            cout << endl << "Invalid option!" << endl;
            break;
        }
    } while (menuChoice != 0);

    return 0;
}

int getMenuChoice() {
    int userChoice;

    cout << "\n0. Exit." << endl;
    cout << "1. Bubble sort data." << endl;
	cout << "2. Merge sort data." << endl;
	cout << "3. Insertion sort data." << endl;

    cin >> userChoice;
    return userChoice;
}

void sortVector(SortInterface<int>& sorter_type, vector<int>& vect, int size, int times_sorted)
{
	double avg_comps = 0.0;
	double avg_swaps = 0.0;
	double avg_runtime = 0.0;

	cout << "Runtime, Comparisons, Swaps:" << endl;

	for (int i = 0; i < times_sorted; i++) 
	{
		generateRandVect(vect, size);
		sorter_type.resetInformation();
		sorter_type.sort(vect); 

		avg_comps += sorter_type.getComparisons();
		avg_swaps += sorter_type.getSwaps();
		avg_runtime += sorter_type.getRuntime();
		
		cout << sorter_type.getRuntime() << " ";
		cout << sorter_type.getComparisons() << " ";
		cout << sorter_type.getSwaps() << endl;
		
	}

	avg_comps = avg_comps / times_sorted;
	avg_swaps = avg_swaps / times_sorted;
	avg_runtime = avg_runtime / times_sorted;

	cout << "Average comparisons: " << avg_comps << endl;
	cout << "Average swaps: " << avg_swaps << endl;
	cout << "Average runtime: " << avg_runtime << endl;

	sorter_type.resetInformation();
}

void displayVector(vector<int>& vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
}

void generateRandVect(vector<int>& vect, int size)
{
	vect.clear();
	for (int i = 0; i < size; i++)
	{
		int rand_num = rand() % 1000000 + 1;
		vect.push_back(rand_num);
	}
}
