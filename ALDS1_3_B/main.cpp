#include <iostream>
#include <string>

using namespace std;

// Queue キューの実装
// 配列を%剰余でリングバッファーとして使う。
// enqueue,dequeueともにO(1)で処理できる。

const int MAX = 100000;

typedef struct Process {
    string name;
    int time;
} Process;

class Queue
{
public:
    Queue() : head(0), tail(0), Q()
    {
    }
    void enqueue(Process x)
    {
        if (isFull())
        {
            cerr << "overflow" << endl;
            return;
        }
        Q[tail] = x;
        // MAXが100の場合、
        // tail=99なら、Q[99]で最後の要素を指している。そのためQ[99+1]は、エラーとなる。
        // エラーにしないため、99+1がMAXなら、tailを0にする。
        if (tail + 1 == MAX)
            tail = 0;
        else
            tail++;
    }
    // 先頭からデータを取り出す。
    Process dequeue()
    {
        if (isEmpty())
        {
            cerr << "underflow" << endl;
            Process x;
            return x;
        }
        Process x = Q[head];
        if (head + 1 == MAX)
            head = 0;
        else
            head++;
        return x;
    }
    bool isEmpty()
    {
        return head == tail;
    }
    bool isFull()
    {
        return head == (tail + 1) % MAX;
    }


private:
    Process Q[MAX];
    int head;
    // 最後の要素の１つ後ろを指す。新しい要素が追加される場所
    int tail;
};


int main(int argc, char *argv[])
{
    /* test
    Queue queue;
    Process p1;
    p1.name = "hello1";
    p1.time = 10;
    queue.enqueue(p1);
    Process p2;
    p2.name = "hello2";
    p2.time = 22;
    queue.enqueue(p2);
    cout << queue.dequeue().name << endl;
    cout << queue.dequeue().name << endl;
    */

    Queue queue;
    // 行数、クオンタム
    int n, q;
    cin >> n;
    cin >> q;
    // データ読み込み
    string name;
    int time;
    while (cin >> name >> time) {
        Process x = { name, time };
        queue.enqueue(x);
    }

    int t1 = 0;
    while (!queue.isEmpty()) {
        Process x = queue.dequeue();
        //t1 += q;
        //x.time -= q;

        int m = std::min(x.time, q);
        t1 += m;
        x.time -= m;

        if (x.time > 0) 
            queue.enqueue(x);
        else
            cout << x.name << " " << t1 << endl;
    }

    return 0;
}
