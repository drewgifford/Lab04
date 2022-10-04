#include <vector>
using namespace std;

class QuickSort {
    public:

        QuickSort();

        int partition(int arr[], int from, int to, int pivot);
        vector<int> sort(vector<int> array);
        void sort(int arr[], int from, int to);
};