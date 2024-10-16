// lab_7_3_it.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Matrix(int** a, int n);
void PrintMatrix(int** a, int n);
void FindEqualRowsAndCols(int** a, int n);
int SumRowsWithNegative(int** a, int n);

int main() {
    int n;

    cout << "matrix size (n): ";
    cin >> n;

    // Dynamic allocation of the matrix
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    // Input and print the matrix
    Matrix(a, n);
    cout << endl;
    PrintMatrix(a, n);
    cout << endl;
    // Find and print rows equal to columns
    FindEqualRowsAndCols(a, n);
    cout << endl;
    // Calculate and print the sum of rows with negative elements
    int sum = SumRowsWithNegative(a, n);
    cout << "Sum of rows containing at least one negative element: " << sum << endl;

    // Clean up the dynamic memory
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Matrix(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void PrintMatrix(int** a, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void FindEqualRowsAndCols(int** a, int n) {
    for (int k = 0; k < n; k++) {
        bool equal = true;
        for (int j = 0; j < n; j++) {
            if (a[k][j] != a[j][k]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            cout << "Row " << k << " is equal to Column " << k << endl;
        }
    }
}

int SumRowsWithNegative(int** a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool hasNegative = false;
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}
