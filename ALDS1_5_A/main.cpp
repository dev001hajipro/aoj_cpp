#include <iostream>
#include <string>

using namespace std;

const int N_MAX = 20;
const int Q_MAX = 200;

void printArray(int *S, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << S[i];
        if (i != n-1) 
            cout << " ";
    }
    cout << endl;
}
// 組み合わせを列挙
void rec(int i, int *S, int n)
{
    if (i == n)
    {
        printArray(S, n);
        return;
    }
    S[i] = 0;
    rec(i+1, S, n);

    S[i] = 1;
    rec(i+1, S, n);
}
void makeCombination(int *S, int n)
{
    rec(0, S, n);
}

// i番目以降の要素を使って、mが作れる場合trueを返す。
bool solve(int *A, int n, int i, int m)
{
    if (m == 0)
        return true;
    if (i >= n)
        return false;
    return (solve(A, n, i + 1, m) || solve(A, n, i + 1, m - A[i]));
}

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    /* 再帰と組み合わせのサンプル
    int S[3] = { 0 };
    makeCombination(S, 3);
    */

    int n;
    cin >> n;
    int A[N_MAX] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int q;
    cin >> q;
    int M[Q_MAX] = { 0 };
    for (int i = 0; i < q; i++)
    {
        cin >> M[i];
    }

    for (int i = 0; i < q; i++)
    {
        cout << (solve(A, n, 0, M[i]) ? "yes" : "no") << endl;
    }

    return 0;
}
