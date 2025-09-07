#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinct = 0;

    for (int i = 0; i < n; i++) {
        int j;
        // check if this element appeared before
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;  // duplicate mil gaya
            }
        }
        if (j == i) {
            distinct++;
        }
    }

    cout << "Total distinct elements: " << distinct << endl;
    return 0;
}
