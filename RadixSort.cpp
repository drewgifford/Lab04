#include "RadixSort.h"

RadixSort::RadixSort(){

    
};


vector<int> RadixSort::countSort(vector<int> array, int exp){

    int n = array.size();
    int output[n]; // output array
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++){
        count[(array[i] / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
 
    // Copy the output array to array, so that array now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++){
        array[i] = output[i];
    }
    return array;
}

vector<int> RadixSort::sort(vector<int> array){

    for (int exp = 1; array.size() / exp > 0; exp *= 10){
        array = countSort(array, exp);
    }
    return array;

}



