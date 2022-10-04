#include "QuickSort.h"
#include <iostream>
using namespace std;

QuickSort::QuickSort(){

};

void swapElements(int arr[], int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int QuickSort::partition (int arr[], int fromIndex, int toIndex, int pivot){

    int i = fromIndex;
    int j = fromIndex;

    while (i <= toIndex){
        if (arr[i] > pivot){
            i++;
        }
        else {
            swapElements(arr, i, j);
            i++;
            j++;
        }
    }
    return j-1;

}

vector<int> QuickSort::sort(vector<int> arr){

    int * newArr = &arr[0];

    sort(newArr, 0, arr.size()-1);

    vector<int> a;
    for(int i = 0; i < arr.size(); i++){
        a.push_back(newArr[i]);
    }
    return a;
}

void QuickSort::sort(int arr[], int fromIndex, int toIndex){ //WIP STILL NOT FINISHED


    if (fromIndex < toIndex){

        int pivot = arr[toIndex];
        int pos = partition(arr, fromIndex, toIndex, pivot);

        sort(arr, fromIndex, pos-1);
        sort(arr, pos+1, toIndex);


    }

}