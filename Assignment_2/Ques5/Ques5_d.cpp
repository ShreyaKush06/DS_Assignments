#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int upper[n*(n+1)/2];
    cout << "Enter elements row-wise (only upper triangle including diagonal):\n";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> upper[i];

    cout << "\nUpper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) cout << upper[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
