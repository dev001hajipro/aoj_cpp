#include <iostream>
#include <string>

using namespace std;

// 二分探索　バイナリーサーチ
// バイナリーサーチは、データがソートされている必要がある。しかしO(n)で検索できる。

const int N_MAX = 100000;
const int Q_MAX = 50000;


// 見つかったらtrue
bool binarySearch(int *A, int N, int key)
{
    int left = 0;
    int right = N; // rightは末尾の次を指す。
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (key == A[mid])
//            return A[mid];
            return true;
        else if (key < A[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return false;
}

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int n;
    int S[N_MAX] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> S[i];

    int q;
    cin >> q;
    int T[Q_MAX] = { 0 };
    for (int i = 0; i < q; i++)
        cin >> T[i];

    int inCount = 0;
    for (int i = 0; i < q; i++)
    {
        if (binarySearch(S, n, T[i]))
            inCount++;
    }
    
    cout << inCount << endl;

    return 0;
}
