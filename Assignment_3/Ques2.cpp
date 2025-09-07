#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    // Push all characters to the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters and form reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;
    return 0;
}
