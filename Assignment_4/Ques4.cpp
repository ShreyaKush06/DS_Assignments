#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter characters separated by space:\n";
    getline(cin, str);
    
    // Remove spaces
    string input = "";
    for (char c : str) {
        if (c != ' ')
            input += c;
    }

    firstNonRepeating(input);
    return 0;
}
