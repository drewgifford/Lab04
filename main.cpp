using namespace std;

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "BubbleSort.h"
#include "InsertionSort.h"

typedef chrono::high_resolution_clock Clock;

int * createArray(int size){
    int * array = new int[size];
    int maxN = size * 2;
    int minN = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(minN, maxN);

    for (int i = 0; i < size; i++){
        int generated = distr(gen);
        array[i] = generated;
    }

    return array;
}

int millisBetween(chrono::_V2::system_clock::time_point t1, chrono::_V2::system_clock::time_point t2){
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

vector<int*> generateArrays(){
    cout << "Generating Arrays... ";

    auto t1 = Clock::now();

    vector<int*> arrays;

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

    vector<int*> arrays = generateArrays();

    cout << "Running Analysis..." << endl;


    BubbleSort bubbleSort;
    InsertionSort insertionSort;


    int * sortedArray = bubbleSort.sort(arrays[4]);

    for(int i = 0; i < sizeof(sortedArray); i++){
        cout << sortedArray[i] << " ";
    }
    cout << endl;


    int * newSortedArray = insertionSort.sort(arrays[4]);

    for(int i = 0; i < sizeof(newSortedArray); i++){
        cout << newSortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}