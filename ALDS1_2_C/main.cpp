#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int N_MAX = 36;

typedef struct Card
{
    char suit;
    int value;
} Card;

void printArray(Card *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << A[i].suit << A[i].value;
        if (i != len -1)
            cout << " ";
    }
    cout << endl;
}

void swap(Card *C, int a, int b)
{
    Card tmp = C[a];
    C[a] = C[b];
    C[b] = tmp;
}

// バブルソートは安定ソート
void bubbleSort(Card C[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N-1; j > i; j--)
        {
            if (C[j].value < C[j-1].value)
                swap(C, j, j-1);
        }
    }
}

void selectionSort(Card *C, int N)
{
    for (int i = 0; i < N; i++)
    {
       int minj = i;
       for (int j = i; j < N; j++)
       {
            if (C[j].value < C[minj].value)
                minj = j;
       }
       swap(C, i, minj);
    }
}

bool isStable(Card *card1, Card *card2, int len)
{
    for (int i = 0; i < len; i++)
        if (card1[i].suit != card2[i].suit)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore(); // skip CR
    Card A1[N_MAX];
    Card A2[N_MAX];

    for (int i = 0; i < n; i++)
    {
        string buff;
        cin >> buff;
        A1[i].suit = buff[0];
        A1[i].value = buff[1] - '0'; // char to int
        A2[i].suit = buff[0];
        A2[i].value = buff[1] - '0';
    }

    bubbleSort(A1, n);
    printArray(A1, n);
    cout << "Stable" << endl;

    selectionSort(A2, n);
    printArray(A2, n);
    string ans = (isStable(A1, A2, n)) ? "Stable" : "Not stable";
    cout << ans << endl;
    return 0;
}
