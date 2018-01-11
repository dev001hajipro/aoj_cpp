#include <iostream>
#include <string>

using namespace std;

// 選択ソート
// ソート済みと未ソート部分列を分けて、最小値をソート済みに設定していく

const int ARRAY_MAX = 100;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if (i != n-1)
            cout << " ";
    }
    cout << endl;
}

void swap(int *A, int a, int b)
{
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

// 交換回数を返す。
int selectionSort(int *A, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int minj = i; // 未ソートで一番小さい要素のインデックス
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minj])
                minj = j;
        }
        if (i != minj)
        {
            swap(A, i, minj);
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A[ARRAY_MAX] = { 0 };

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int count = selectionSort(A, n);
    printArray(A, n);
    cout << count << endl;

    return 0;
}
