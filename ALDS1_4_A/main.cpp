#include <iostream>
#include <string>

using namespace std;

const int MAX = 10000;

// 線形探索

int linearSearch(int *S, int n, int *T, int q)
{
    int sameCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (S[i] == T[j])
                sameCount++;
        }
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

    cout << linearSearch(S,n,T,q) << endl;

    return 0;
}
