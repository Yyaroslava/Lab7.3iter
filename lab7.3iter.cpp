// Мороз Ярослава 
// Лабораторна робота № 7.3iter
// Варіант 10 
// Ітераційний спосіб

#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Fill(int** M, const int Count);
void Print(int** M, const int Count);
void GetElementsCount(int** M, const int Count, int& result);
int GetAbsSum(int** M, const int Count);

int main() {
    srand((unsigned)time(NULL));

    int Count = 4;
    
    int** M = new int* [Count];
    for (int row = 0; row < Count; row++) M[row] = new int[Count];

    Fill(M, Count);
    Print(M, Count);

    int elementsCount;
    GetElementsCount(M, Count, elementsCount);
    cout << "number of local minimums = " << elementsCount << endl;

    int absSum = GetAbsSum(M, Count);
    cout << "sum of absolute values = " << absSum << endl;
    
    
    for (int row = 0; row < Count; row++) delete[] M[row];
    delete[] M;

    return 0;
}

void Fill(int** M, const int Count) {
    for (int row = 0; row < Count; row++)
        for (int col = 0; col < Count; col++) {
            cout << "M[" << row << "][" << col << "] = ";
            cin >> M[row][col];
        }
}

void Print(int** M, const int Count) {
    cout << endl;
    for (int row = 0; row < Count; row++) {
        for (int col = 0; col < Count; col++) cout << setw(4) << M[row][col];
        cout << endl;
    }
    cout << endl;
}

void GetElementsCount(int** M, const int Count, int& result) {
    result = 0;
    for (int col = 0; col < Count; col++) {
        for (int row = 0; row < Count; row++) {
            int localMin = M[row][col];
            for (int nbRow = row - 1; nbRow <= row + 1; nbRow++) {
                for (int nbCol = col - 1; nbCol <= col + 1; nbCol++) {
                    if (nbRow>=0 && nbRow<Count && nbCol >= 0 && nbCol < Count) {
                        if (M[nbRow][nbCol] < localMin) localMin = M[nbRow][nbCol];
                    }
                }
            }
            if (localMin == M[row][col]) {
                result++;
            }
        }
    }
    return;
}

int GetAbsSum(int** M, const int Count) {
    int result = 0;
    for (int col = 0; col < Count; col++) {
        for (int row = 0; row < Count; row++) {
            if (col > row) {
                result += abs(M[row][col]);
            }
        }
    }
    return result;
}

