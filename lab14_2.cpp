#include <iostream>
using namespace std;

const int N = 5;

void inputMatrix(double A[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

void findLocalMax(double A[N][N], bool B[N][N]) {
    // กำหนดค่าเริ่มต้นของ Matrix B เป็น false ทั้งหมด
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = false;
        }
    }

    // ตรวจสอบค่าที่เป็น Local Maximum
    for (int i = 1; i < N - 1; i++) { // ละขอบ Matrix (row 0, N-1)
        for (int j = 1; j < N - 1; j++) { // ละขอบ Matrix (column 0, N-1)
            if (A[i][j] >= A[i - 1][j] && // บน
                A[i][j] >= A[i + 1][j] && // ล่าง
                A[i][j] >= A[i][j - 1] && // ซ้าย
                A[i][j] >= A[i][j + 1]) { // ขวา
                B[i][j] = true; // กำหนดตำแหน่งนี้เป็น Local Maximum
            }
        }
    }
}

void showMatrix(const bool B[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double A[N][N];
    bool B[N][N];

    cout << "Input the matrix.....\n";
    inputMatrix(A);

    findLocalMax(A, B);

    cout << "Result is \n";
    showMatrix(B);

    return 0;
}
//Do not modify source code above this line 
