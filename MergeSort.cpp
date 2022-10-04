#include "MergeSort.h"
#include <vector>

using namespace std;

MergeSort::MergeSort(){

};

int * MergeSort::sort(int * array){

    int arraySize = sizeof(array);


    for (int i = 0; i < arraySize-1; i++){

        
        int nextI = i+1;

        for(int reverseI = i; reverseI >= 0; reverseI++){
            
            int currValue = array[reverseI];
            int nextValue = array[reverseI+1];

            if (currValue > nextValue){
                array[reverseI] = nextValue;
                array[nextValue] = currValue;
            } else {
                break;
            }
        }


    }


    return array;
}