#include "BubbleSort.h"
#include <vector>

using namespace std;

BubbleSort::BubbleSort(){

};

vector<int> BubbleSort::sort(vector<int> array){

    int arraySize = array.size();

    int swaps;
    do {

        swaps = 0;

        for (int i = 0; i < arraySize-1; i++){

            int nextI = i+1;

            int currValue = array[i];
            int nextValue = array[nextI];

            if (currValue > nextValue){
                array[nextI] = currValue;
                array[i] = nextValue;
                swaps++;
            }
        }


    } while (swaps != 0);


    return array;
}