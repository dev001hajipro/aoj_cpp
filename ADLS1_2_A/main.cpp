#include <iostream>
#include <string>

using namespace std;

const int MAX_EL = 100;

void printArray(int *A, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
            cout << A[i];
        else
            cout << A[i] << " ";
    }
    cout << endl;
}

// バブルソート
int bubbleSort(int *A, int N)
{
    int count = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j >= 1; j--)
        {
            if (A[j] < A[j - 1])
            {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = true;
                count++;
            }
        }
    }
    return count;
}

// cl /EHsc /source-charset:utf-8 main.cpp
// .\main.exe < in1.txt
int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    // read elements
    int A[MAX_EL] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int swapCount = bubbleSort(A, N);

    printArray(A, N);
    cout << swapCount << endl;

    return 0;
}
