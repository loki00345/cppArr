#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void printArray(int arr[][6], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void fillArray(int arr[][6], int size, int initialValue, bool task1) {
    for (int i = 0; i < size; ++i) {
        arr[i][0] = initialValue + i * (task1 ? i : i + 1);
        for (int j = 1; j < 6; ++j) {
            arr[i][j] = arr[i][j - 1] + (task1 ? arr[i][j - 1] : 1);
        }
    }
}

void shiftArray(int arr[][6], int size, int shiftCount, bool rightShift) {
    int temp[2][6]; 

    if (rightShift) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < 6; ++j) {
                temp[i][(j + shiftCount) % 6] = arr[i][j];
            }
        }
    }
    else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < 6; ++j) {
                temp[i][(j - shiftCount + 6) % 6] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 6; ++j) {
            arr[i][j] = temp[i][j];
        }
    }
}



int main() {
    const int size = 2; 
    int arr[size][6]; 

    srand(time(NULL)); 

    
    int initialValue;
    cout << "Enter the initial value: ";
    cin >> initialValue;

    fillArray(arr, size, initialValue, true);
    cout << "Array filled according to task 1:" << endl;
    printArray(arr, size);

    fillArray(arr, size, initialValue, false);
    cout << endl << "Array filled according to task 2:" << endl;
    printArray(arr, size);

    int shiftCount;
    char direction;
    cout << "Enter the shift count: ";
    cin >> shiftCount;
    cout << "Enter the direction of shift (R for right, L for left): ";
    cin >> direction;

    switch (direction) {
    case 'R':
    case 'r':
        shiftArray(arr, size, shiftCount, true);
        cout << endl << "Array shifted " << shiftCount << " positions to the right:" << endl;
        printArray(arr, size);
        break;
    case 'L':
    case 'l':
        shiftArray(arr, size, shiftCount, false);
        cout << endl << "Array shifted " << shiftCount << " positions to the left:" << endl;
        printArray(arr, size);
        break;
    default:
        cout << "Invalid direction entered!" << endl;
        break;
    }

    return 0;
}
