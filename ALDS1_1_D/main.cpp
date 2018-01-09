#include <iostream>
#include <string>

using namespace std;
const int MAX = 200000;

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int R[MAX] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> R[i];
    }

    int minv = R[0];
    int maxv = -2000000000;
    for (int i = 1; i < n; i++)
    {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    cout << maxv << endl;

    return 0;
}
