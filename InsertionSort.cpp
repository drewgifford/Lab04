#include "InsertionSort.h"
#include <vector>
using namespace std;

using namespace std;

InsertionSort::InsertionSort(){

};

vector<int> InsertionSort::sort(vector<int> array){

    int arraySize = array.size();


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