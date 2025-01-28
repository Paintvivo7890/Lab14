#include <iostream>
using namespace std;

template <typename T>
void insertionSort(T d[], int N) {
    for (int i = 1; i < N; i++) {
        T key = d[i];
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && d[j] < key) {  // Sorting in descending order
            d[j + 1] = d[j];
            j--;
        }
        d[j + 1] = key;

        // Display the array after each pass
        cout << "Pass " << i << ":";
        for (int k = 0; k < N; k++) {
            cout << d[k] << " ";
        }
        cout << endl;
    }
}