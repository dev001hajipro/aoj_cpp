#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MAX = 1050000;
string T[MAX];

// ハッシュ Directory
// オープンアドレス法は、ハッシュが衝突したらハッシュを再計算。

int h(int key)
{
    return key % MAX;
}
int g(int key)
{
    return 1 + (key % (MAX - 1));
}

int hash(int key, int i)
{
    return (h(key) + i * g(key)) % MAX;
}

int getChar(char ch)
{
    if ( ch == 'A') return 1;
    else if ( ch == 'C') return 2;
    else if ( ch == 'G') return 3;
    else if ( ch == 'T') return 4;
    return 0;
}

long long getKey(const char str[])
{
    long long sum = 0, p = 1, i;
    for ( i = 0; i < strlen(str); i++ )
    {
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}
int getKey_(string value)
{
    int sum = 0;
    int p = 1;
    for (string::size_type i = 0; i < value.size(); i++)
    {
        sum += p * (getChar(value[i]));
        p *= 5;
    }
    return sum;
}

bool search(string value)
{
    //int key = getKey(value.c_str());
    int key = getKey_(value);

    for (int i = 0; ; i++)
    {
        int j = hash(key, i);
        if (T[j].compare(value) == 0) return true;
        else if (T[j].empty())
        {
            return false;
        }
    }
    return false;
}

int insert(string value)
{
    //int key = getKey(value.c_str());
    int key = getKey_(value);

    for (int i = 0; ; i++)
    {
        int j = hash(key, i);
        if (value.compare(T[j]) == 0)
        {
            // データが一致したら挿入しない。
            return 1;
        }
        else if (T[j].empty())
        {

            T[j] = value;
            return 0;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string cmd, str;
        cin >> cmd >> str;
        if (cmd.find("insert") == string::npos)
        {
            string msg = search(str) ? "yes" : "no";
            cout << msg << endl;
        }
        else
        {
            insert(str);
        }
    }

    return 0;
}
