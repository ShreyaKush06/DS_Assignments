#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int sym[n*(n+1)/2];
    cout << "Enter elements row-wise (only lower triangle including diagonal):\n";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> sym[i];

    cout << "\nSymmetric Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) cout << sym[k++] << " ";
            else cout << sym[(j*(j+1))/2 + i] << " "; // fetch from stored lower part
        }
        cout << endl;
    }
    return 0;
}
