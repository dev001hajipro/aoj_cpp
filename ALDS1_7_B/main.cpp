#include <iostream>
#include <string>

using namespace std;

const int MAX = 25;
const int NIL = -1;

typedef struct {
    int parent;
    int left;
    int right;
    int depth;
    int height;
} Node;
Node nodes[MAX];

int degree(int u)
{
    int count = 0;
    if (nodes[u].left != NIL) count++;
    if (nodes[u].right != NIL) count++;
    return count;
}

void setDepth(int u, int depth)
{
    if (u == NIL) return;

    nodes[u].depth = depth;
    setDepth(nodes[u].left, depth + 1);
    setDepth(nodes[u].right, depth + 1);
}
// 兄弟ノードを求める
int getSibling(int u)
{
    if (nodes[u].parent == NIL) return NIL;
    int parent = nodes[u].parent;
    // ノードuが親から見て右の子ノードの場合、左子ノードを返す。
    if (nodes[parent].left != u && nodes[parent].left != NIL)
        return nodes[parent].left;
    if (nodes[parent].right != u && nodes[parent].right != NIL)
        return nodes[parent].right;
    return NIL;

        return nodes[parent].left;
}

inline int max(int a, int b)
{
    return (a < b) ? b : a;
}

int setHeight(int u)
{
    int h1 = 0;
    int h2 = 0;
    h1 = (nodes[u].right == NIL) ? 0 : setHeight(nodes[u].right) + 1;
    h2 = (nodes[u].left == NIL) ? 0 : setHeight(nodes[u].left) + 1;

    nodes[u].height = max(h1, h2);
    return nodes[u].height;
}

void printNode(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << nodes[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    cout << "degree = " << degree(u) << ", ";
    cout << "depth = " << nodes[u].depth << ", ";
    cout << "height = " << nodes[u].height << ", ";
    if (nodes[u].parent == NIL)
        cout << "root";
    else if (nodes[u].left == NIL && nodes[u].right == NIL)
        cout << "leaf";
    else 
        cout << "internal node";
    cout << endl;
}


int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++)
    {
        nodes[i].parent = NIL;
        nodes[i].left = NIL;
        nodes[i].right = NIL;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
       int id, left, right;
       cin >> id >> left >> right;
        nodes[id].left = left;
        if (left != NIL)
            nodes[left].parent = id;

        nodes[id].right = right;
        if (right != NIL)
            nodes[right].parent = id;
    }

    int root;
    // find root
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == NIL)
        {
            root = i;
            break;
        }
    }

    setDepth(root, 0);
    setHeight(root);

    for (int i = 0; i < n; i++)
        printNode(i);


    return 0;
}
