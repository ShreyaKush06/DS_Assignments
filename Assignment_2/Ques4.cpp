#include<iostream>
using namespace std;

void Concatenate(string str1, string str2) {
    string combine = str1 + str2;
    cout << "Concatenated string: " << combine << endl; 
};

void reverseString(string &str) {
    int n = str.length();
    string rev;
    for (int i = n - 1; i >= 0; i--) {
        rev += str[i];
    }
    cout << "Reverse of string " << str <<" is "<< rev << endl;
};

void DeleteVowels(string &str) {
    string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    cout << "String "<<str<<" after deleting vowels: " << result << endl;
};

void AlphabeticalOrder(string str1, string str2) {
    if (str1 < str2) {
        cout << "Strings in alphabetical order: " << str1 << ", " << str2 << endl;
    } else {
        cout << "Strings in alphabetical order: " << str2 << ", " << str1 << endl;
    }
};

void Lowercase(string &str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c += 32; 
        }
    }
    cout << "String 1 in lowercase: " << str << endl;
};

int main(){
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    Concatenate(str1, str2);
    reverseString(str1);
    DeleteVowels(str1);
    AlphabeticalOrder(str1, str2);
    Lowercase(str1);
    return 0;
}