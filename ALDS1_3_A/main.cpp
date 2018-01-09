#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX = 200;

// stack
class Stack
{
public:
    Stack() : top(0), S()
    {
    }
    void push(int x)
    {
        if (isFull())
        {
            cerr << "overflow" << endl;
        }
        S[++top] = x;
    }
    int pop()
    {
        if (isEmpty())
        {
            cerr << "underflow" << endl;
            return -1;
        }
        return S[top--];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    bool isFull()
    {
        return top >= MAX - 1;
    }

private:
    // トップの値はスタックの要素数と等しい
    int top;
    int S[100];
};

// スタックの実装
int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    Stack stack;
    string s;
    int a, b;

    while (cin >> s)
    {
        switch (s[0])
        {
        case '+':
            a = stack.pop();
            b = stack.pop();
            stack.push(a + b);
            break;
        case '-':
            b = stack.pop();
            a = stack.pop();
            stack.push(a - b);
            break;
        case '*':
            a = stack.pop();
            b = stack.pop();
            stack.push(a * b);
            break;
        default:
            stack.push(atoi(s.c_str()));
        }
    }
    cout << stack.pop() << endl;

    return 0;
}
