#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string front = q.front();
        q.pop();

        cout << front;
        if (i != n) cout << ", ";

        q.push(front + "0");
        q.push(front + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinary(n);

    return 0;
}
