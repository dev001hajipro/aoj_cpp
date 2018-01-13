#include <iostream>
#include <string>

using namespace std;

// 階乗 n!
int factorial(int n)
{
    return (n == 0) ? 1 : n * factorial(n - 1);
}

// 順列(sequence without repetition)
// nPk = n! / (n - k)!
int P(int n, int k)
{
    return factorial(n) / factorial(n - k);
}

// 組み合わせ
// カードからn枚取る。ロトくじなど
//
// 公式
// nCk, C(n, k)
// nCk = n! / { k! * (n-k)! }
int C(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n-k));
}
int C_(int n, int k)
{
    return P(n, k) / factorial(k);
}
int Cx(int n, int k)
{
//    if (n == k) return 1;
    if (k == 0) return 1;
    if (k == 1) return n;

    return Cx(n-1, k-1) + Cx(n-1, k);
}
 

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << "120=" << factorial(5) << endl;
    cout << "5P2=" << P(5, 2) << endl;
    cout << "fact(5)=" << factorial(5) << endl;
    cout << "fact(2)=" << factorial(2) << endl;
    cout << "fact(3)=" << factorial(3) << endl;
    cout << "5C2(5個から2つ選ぶ組み合わせは?(10)=" << C(5, 2) << endl;
    cout << "5C2(5個から2つ選ぶ組み合わせは?(10)=" << C_(5, 2) << endl;
    cout << "5C2(5個から2つ選ぶ組み合わせは?(10)=" << Cx(5, 2) << endl;
    return 0;
}
