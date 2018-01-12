#include <iostream>
#include <string>

using namespace std;

const int MAX = 10000;

// 線形探索
bool linearSearch(int *A, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
            return true;
    }
    return false;
}

int search(int *S, int n, int *T, int q)
{
    int sameCount = 0;
    for (int i = 0; i < q; i++)
    {
        if (linearSearch(S, n, T[i]))
            sameCount++;
    }
    return sameCount;
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int S[MAX] = { 0 };
    for (int i = 0; i < n; i++)
        cin >> S[i];

    int q;
    cin >> q;
    int T[MAX] = { 0 };
    for (int i = 0; i < q; i++)
        cin >> T[i];

    cout << search(S,n,T,q) << endl;

    return 0;
}
