using namespace std;

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include <iomanip>

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

void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

}

int main(){

    vector<vector<int>> arrays = generateArrays();

    vector<int> array = createArray(25);

    cout << "Running Analysis..." << endl;


    BubbleSort bubbleSort;
    InsertionSort insertionSort;
    MergeSort mergeSort;
    QuickSort quickSort;
    RadixSort radixSort;


    for(int s = -1; s < 5; s++){

        string sortString;


        if (s == -1){
            sortString = "";
        }
        if (s == 0){
            sortString = "Bubble Sort";
        }
        else if (s == 1){
            sortString = "Insertion Sort";
        }
        else if (s == 2){
            sortString = "Merge Sort";
        }
        else if (s == 3){
            sortString = "Quick Sort";
        }
        else if (s == 4) {
            sortString = "Radix Sort";
        }

        cout << setw(15) << left << sortString;

        for (int i = 0; i < arrays.size(); i++){

            vector<int> currentArray = arrays.at(i);

            if (s == -1){
                cout << setw(10) << left << currentArray.size();
                continue;
            }

            auto t1 = Clock::now();

            if (s == 0){
                currentArray = bubbleSort.sort(currentArray);
            }
            else if (s == 1){
                currentArray = insertionSort.sort(currentArray);
            }
            else if (s == 2){
                currentArray = mergeSort.sort(currentArray);
            }
            else if (s == 3){
                currentArray = quickSort.sort(currentArray);
            }
            else {
                currentArray = radixSort.sort(currentArray);
            }

            auto t2 = Clock::now();

            string msString = "";

            if (chrono::duration_cast<chrono::minutes>(t2 - t1).count() > 5){
                cout << setw(10) << "> 5 minutes";
                continue;
            }

            msString = to_string(chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000) + " ms";

            cout << setw(10) << left << msString;

        }
        cout << endl;
    }

    return 0;
}