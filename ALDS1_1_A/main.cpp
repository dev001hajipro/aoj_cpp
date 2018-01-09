#include <iostream>
#include <string>

// 挿入ソート(Insert Sort)

using namespace std;

const int MAX_EL = 1000;

void printArray(int *A, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i == N -1)
            cout << A[i];
        else
            cout << A[i] << " ";
    }
    cout << endl;
}
void insertSort(int *A, int N)
{
    for (int i = 1; i <= N -1; i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(A, N);
    }
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    // read elements
    int A[MAX_EL] = { 0 };
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    printArray(A, N);
    insertSort(A, N);

    return 0;
}
