#include <iostream>
#include <string>

using namespace std;

const int N_MAX = 100;

// グラフ
// 隣接リスト表現の有効グラフGの隣接行列を出力

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int G[100][100] = { 0 };

    for (int i = 0; i< n; i++)
    {
        int u, k;
        cin >> u; // 頂点番号
        cin >> k; // 出次数
        for (int i = 0; i < k; i++)
        {
            int v;
            cin >> v;
            G[u-1][v-1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
