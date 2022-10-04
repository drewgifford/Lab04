#include "MergeSort.h"
#include <iostream>
#include <vector>
using namespace std;

using namespace std;

MergeSort::MergeSort(){

};

vector<int> MergeSort::merge(vector<int> arr){

    if (arr.size() > 1){

        // Split array into two equal parts
        int half_size = arr.size()/2;
        
        cout << half_size << endl;

        vector<int> leftArray(arr.begin(), arr.begin() + half_size);
        vector<int> rightArray(arr.begin() + half_size, arr.end());

        leftArray = merge(leftArray);
        rightArray = merge(rightArray);

        int i,j,k = 0;

        while (i < leftArray.size() && j < rightArray.size()){
            if (leftArray[i] <= rightArray[j]){
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }
        

    }

    return arr;


}

vector<int> MergeSort::sort(vector<int> array){

    array = merge(array);

    return array;
}