using namespace std;

#include <iostream>
#include <chrono>
#include <random>
typedef chrono::high_resolution_clock Clock;

int * createArray(int size){
    int * array = new int[size];

    srand(time(NULL));

    int maxN = size * 2;
    int minN = 0;



    for (int i = 0; i < size; i++){
        
        //cout << "RANDOM: " << rand() << endl;

        array[i] = static_cast<int>(rand() * (maxN - minN));
        cout << array[i] << " ";
    }
    cout << endl;

    return array;
}

int main(){

    auto t1 = Clock::now();

    auto t2 = Clock::now();

    cout << "Delta t2-t1: " 
	        << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << endl;

    createArray(10);

    cout << "Hello World!" << endl;

    return 0;
}