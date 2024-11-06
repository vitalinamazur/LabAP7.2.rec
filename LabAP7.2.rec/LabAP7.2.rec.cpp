#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int n, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int n);
void PlaceMaxOnDiagonal(int** a, const int n, int i = 0);
bool SearchMinEvenOnAntiDiagonal(int** a, const int n, int& minEven, int i = 0, bool found = false);

int main() {
    srand((unsigned)time(NULL));
    int n;
    int Low = -10;
    int High = 50;

    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, n);

    PlaceMaxOnDiagonal(a, n);
    cout << "Modified matrix with max elements on the main diagonal:" << endl;
    Print(a, n);

    int minEven;
    if (SearchMinEvenOnAntiDiagonal(a, n, minEven))
        cout << "The smallest even element on the anti-diagonal is: " << minEven << endl;
    else
        cout << "There are no even elements on the anti-diagonal." << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High, int i, int j) {
    if (i == n) return; // вихід з рекурсії
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j == n - 1)
        Create(a, n, Low, High, i + 1, 0);
    else
        Create(a, n, Low, High, i, j + 1);
}

void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void PlaceMaxOnDiagonal(int** a, const int n, int i) {
    if (i == n) return; // вихід з рекурсії
    int maxIndex = i;
    for (int j = 0; j < n; j++) {
        if (a[i][j] > a[i][maxIndex])
            maxIndex = j;
    }
    swap(a[i][i], a[i][maxIndex]);
    PlaceMaxOnDiagonal(a, n, i + 1);
}

bool SearchMinEvenOnAntiDiagonal(int** a, const int n, int& minEven, int i, bool found) {
    if (i == n) return found; // вихід з рекурсії
    int j = n - 1 - i;
    if (a[i][j] % 2 == 0) {
        if (!found || a[i][j] < minEven) {
            minEven = a[i][j];
            found = true;
        }
    }
    return SearchMinEvenOnAntiDiagonal(a, n, minEven, i + 1, found);
}
