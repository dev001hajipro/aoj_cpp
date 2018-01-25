#include <iostream>
#include <string>
#include <cstdlib>

// 二分探索木のノード削除はちょっと癖のあるアルゴリズム

// 次節点：中間順巡回(inorder)で、次に訪れるノード
// 以下のコードから分かるように、次節点は、ノードuの子というわけではない。
// 深くたどっていく場合もある。
/*
void inorder(Node *u)
{
    if (u == NULL) return;
    inorder(u->left);
    cout << " " << (u->key);
    inorder(u->right);
}
*/

using namespace std;

struct Node
{
    Node *parent;
    Node *left;
    Node *right;
    int key;
};

void insert(Node **u, int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->key = num;

    // find parent target
    Node *parentTarget;
    for (Node *n = *u; n != NULL; )
    {
        parentTarget = n;
        if (n->key < num)
            n = n->right;
        else if (n->key > num)
            n = n->left;
    }
    newNode->parent = parentTarget;

    if (*u == NULL)
        *u = newNode;
    else if (parentTarget->key < num)
        parentTarget->right = newNode;
    else if (parentTarget->key > num)
        parentTarget->left = newNode;
}

Node *find(Node *u, int num)
{
    if (u == NULL) return NULL;
    if (u->key == num)
        return u;
    else if (u->key < num)
        return find(u->right, num);
    else if (u->key > num)
        return find(u->left, num);
    return NULL;
}

// 次節点の探索、最小値
Node *getMinimum(Node *u)
{
    return (u->left == NULL) ? u : getMinimum(u->left);
}
// xノードの次節点を求める
Node *getSuccesor(Node *x)
{
    // 右の子がある場合、その子の一番小さな値。
    if (x->right != NULL) return getMinimum(x->right);

    // TODO:ここの意味
    Node *p = x->parent;
    while (p != NULL && x == p->right)
    {
        x = p;
        p = p->parent;
    }
    return p;
}

void deleteNode(Node **u, Node *d)
{
    // 削除ノードを求める
    Node *deleteTarget;
    Node *x; // 削除対象の子
    if (d->left == NULL || d->right == NULL) deleteTarget = d;
    else deleteTarget = getSuccesor(d);

    if (deleteTarget->left != NULL)
        x = deleteTarget->left;
    else
        x = deleteTarget->right;

    // 親の付け替え
    if (x != NULL)
        x->parent = deleteTarget->parent;

    // 削除ノードの親とxを繋げる
    if (deleteTarget->parent == NULL)
    {
        *u = x;
    }
    else
    {
        // 左についていた場合
        if (deleteTarget == deleteTarget->parent->left)
            deleteTarget->parent->left = x;
        else
            deleteTarget->parent->right = x;
    }

    // キーを入れ替える
    if (deleteTarget != d)
        d->key = deleteTarget->key;

    free(deleteTarget);
}

void preorder(Node *u)
{
    if (u == NULL) return;
    cout << " " << (u->key);
    preorder(u->left);
    preorder(u->right);
}
void inorder(Node *u)
{
    if (u == NULL) return;
    inorder(u->left);
    cout << " " << (u->key);
    inorder(u->right);
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // ポインタ変数はNULLで明示しないと不定値になる。
    Node *root = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command.find("insert") == 0)
        {
            int num;
            cin >> num;
            insert(&root, num);
        }
        else if (command.find("find") == 0)
        {
            int num;
            cin >> num;
            Node *n = find(root, num);
            cout << ((n == NULL) ? "no" : "yes") << endl;
        }
        else if (command.find("print") == 0)
        {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
        else if (command.find("delete") == 0)
        {
            int num;
            cin >> num;
            deleteNode(&root, find(root, num));
        }
    }
    return 0;
}
