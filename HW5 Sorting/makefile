sorting_algorithms: main.o 
	g++ main.o -o sorting_algorithms

main.o: main.cpp vectorBubbleSort.h vectorInsertionSort.h vectorMergeSort.h
	g++ -c main.cpp

clean:
	rm *.o sorting_algorithms