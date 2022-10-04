#include "MergeSort.h"
#include <iostream>
#include <vector>
using namespace std;

using namespace std;

MergeSort::MergeSort(){

};

void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

}


// 3 4 2 1

// 3 4     2   1

// 3, 4    2 , 1

// 34   12
//   1234

vector<int> MergeSort::merge(vector<int> arr){


    if (arr.size() > 1){

        // Split array into two equal parts
        int half_size = arr.size()/2;

        vector<int> initLeftArray(arr.begin(), arr.begin() + half_size);
        vector<int> initRightArray(arr.begin() + half_size, arr.end());


        vector<int> leftArray = merge(initLeftArray);
        vector<int> rightArray = merge(initRightArray);

        int leftI = 0;
        int rightI = 0;
        int mainI = 0;


        vector<int> test;

        while (leftI < leftArray.size() && rightI < rightArray.size()){
            if (leftArray[leftI] <= rightArray[rightI]){
                test.push_back(leftArray[leftI]);
                ++leftI;
            }
            else {
                test.push_back(rightArray[rightI]);
                ++rightI;
            }
        }

        while (leftI < leftArray.size()){
            test.push_back(leftArray[leftI]);
            ++leftI;
        }

        while (rightI < rightArray.size()){
            test.push_back(rightArray[rightI]);
            ++rightI;
        }

        arr = test;


    }

    return arr;


}

vector<int> MergeSort::sort(vector<int> array){

    array = merge(array);

    return array;
}