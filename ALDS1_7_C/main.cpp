#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    int parent;
    int left;
    int right;
} Node;

const int MAX = 25;
const int NIL = -1;
Node nodes[MAX];

void preParse(int u)
{
    if (u == NIL) return;
    cout << " " << u;
    preParse(nodes[u].left);
    preParse(nodes[u].right);
}
void inParse(int u)
{
    if (u == NIL) return;
    inParse(nodes[u].left);
    cout << " " << u;
    inParse(nodes[u].right);
}
void postParse(int u)
{
    if (u == NIL) return;
    postParse(nodes[u].left);
    postParse(nodes[u].right);
    cout << " " << u;
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++)
    {
        nodes[i].parent = nodes[i].left = nodes[i].right = NIL;
    }

    // 入力データの登録
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // nodesの添え字がそのノードのidとなっている
        int id, left, right;
        cin >> id >> left >> right;
        nodes[id].left = left;
        if (left != NIL) nodes[left].parent = id;

        nodes[id].right = right;
        if (right != NIL) nodes[right].parent = id;
    }

    // ルート
    int root;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == NIL)
        {
            root = i;
            break;
        }
    }

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;

    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;

    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;


    return 0;
}
