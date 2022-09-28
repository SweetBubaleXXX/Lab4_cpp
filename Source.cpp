#include <iostream>
#include <cmath>

using namespace std;

void enterSize(int*);

int findMax(int[], int);

int main() {
    int arraySize;

    enterSize(&arraySize);
    int* userArray = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        printf("[%u]: ", i);
        cin >> userArray[i];
    }

    int maxIndex = findMax(userArray, arraySize);
    
    copy(userArray + maxIndex, userArray + arraySize, userArray);

    cout << "New array:" << endl;
    for (int i = 0; i < arraySize - maxIndex; i++) {
        cout << "[" << i << "]: " << userArray[i] << endl;
    }

    delete[] userArray;

    return 0;
}

void enterSize(int* sizeP) {
    cout << "Enter size: ";
    cin >> *sizeP;
}

int findMax(int arr[], int size) {
    int curMaxIndex = 0;
    for (int n = 1; n < size; n++) {
        if (arr[n] > arr[curMaxIndex]) {
            curMaxIndex = n;
        }
    }
    return curMaxIndex;
}
