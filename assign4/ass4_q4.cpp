#include <iostream>
#include<string>
#include <queue>
using namespace std;
int main() {
    string str;
    cout << "Enter characters : ";
    cin >> str;
    queue<char> q;
    int freq[26] = {0};
    cout << "Output: ";
    for (char ch : str) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
    return 0;
}
