using namespace std;

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

typedef chrono::high_resolution_clock Clock;

vector<int> createArray(int size){
    vector<int> array;
    int maxN = size * 2;
    int minN = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(minN, maxN);

    cout << "Creating array of size " << size << endl;

    for (int i = 0; i < size; i++){

        int generated = distr(gen);
        array.push_back(generated);
    }

    return array;
}

int millisBetween(chrono::_V2::system_clock::time_point t1, chrono::_V2::system_clock::time_point t2){
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

vector<vector<int>> generateArrays(){
    cout << "Generating Arrays... ";

    auto t1 = Clock::now();

    vector<vector<int>> arrays;

    arrays.push_back(createArray(10));
    arrays.push_back(createArray(100));
    arrays.push_back(createArray(500));
    arrays.push_back(createArray(5000));
    arrays.push_back(createArray(25000));

    auto t2 = Clock::now();
    cout << "Done! (" << millisBetween(t1, t2) << "ms)" << endl;

    return arrays;
}

int main(){

    vector<vector<int>> arrays = generateArrays();

    vector<int> array = createArray(25);

    cout << "Running Analysis..." << endl;


    BubbleSort bubbleSort;
    InsertionSort insertionSort;
    MergeSort mergeSort;


    cout << sizeof(array) << endl;

    vector<int> new2SortedArray = mergeSort.sort(array);

    for(int i = 0; i < sizeof(new2SortedArray); i++){
        cout << new2SortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}