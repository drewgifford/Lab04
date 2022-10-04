#include "InsertionSort.h"
#include <vector>

using namespace std;

InsertionSort::InsertionSort(){

};

int * InsertionSort::sort(int * array){

    int arraySize = sizeof(array);


    for (int i = 0; i < arraySize-1; i++){

        for(int reverseI = i; reverseI >= 0; reverseI--){
            
            int currValue = array[reverseI];
            int nextValue = array[reverseI+1];

            if (currValue > nextValue){
                array[reverseI] = nextValue;
                array[reverseI+1] = currValue;
            } else {
                break;
            }
        }


    }


    return array;
}