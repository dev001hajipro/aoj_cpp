#include <iostream>
#include <string>

using namespace std;

// Rooted Trees
// 左手右兄弟表現
// 二重連鎖木(Double chained tree)
// 
//  

static const int N = 100000;
static const int NIL = -1;

// 二分木のノード
struct Node
{
    int parent;
    int left;
    int right;
};
struct Node T[N];
int D[N];

// ノードの深さを求める
// 頂点uの深さをD[u]で保持する。つまり、D[頂点]配列を見ると、
// 自分の深さが分かり、最大値を調べると最も深い部分もわかる。
void setDepth(int u, int parent)
{
   D[u] = parent;
   if (T[u].right != NIL) setDepth(T[u].right, parent);
   if (T[u].left != NIL) setDepth(T[u].left, parent + 1);
}

void printNode(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if (T[u].parent == NIL) cout << "root, ";
    else if (T[u].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    for (int i = 0, child = T[u].left; child != NIL; i++, child = T[child].right)
    {
        if (i) cout << ", ";
        cout << child;
    }
            
    cout << "]" << endl;
}


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);


  
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        T[i].left = NIL;
        T[i].right = NIL;
        T[i].parent = NIL;
    }

    // 多分木を二分木(二重連鎖木(Double chained tree))で、データ保持する
    for (int i = 0; i < n; i++)
    {
        int nodeId, k;
        int prevChild;
        cin >> nodeId >> k;
        for (int j = 0; j < k; j++)
        {
            int child;
            cin >> child;
            // 左子右兄弟表現.もっとも左が子で、そこに兄弟を繋げる。
            if (j == 0) T[nodeId].left = child;
            else T[prevChild].right = child;

            T[child].parent = nodeId;

            prevChild = child;
        }
    }

    int rootNode;
    for (int i = 0; i < n; i++)
    {
        if (T[i].parent == NIL)
        {
            rootNode = i;
            break;
        }
    }

    setDepth(rootNode, 0);
    
    for (int i = 0; i < n; i++)
        printNode(i);

    return 0;
}
