#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter number of non-zero elements in Matrix 1: ";
    cin >> n1;
    int mat1[n1][3];
    cout << "Enter row col value for Matrix 1:\n";
    for (int i = 0; i < n1; i++) cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];

    cout << "Enter number of non-zero elements in Matrix 2: ";
    cin >> n2;
    int mat2[n2][3];
    cout << "Enter row col value for Matrix 2:\n";
    for (int i = 0; i < n2; i++) cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];

    cout << "\nMultiplication Result (row col value):\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (mat1[i][1] == mat2[j][0]) { // col of mat1 = row of mat2
                cout << mat1[i][0] << " " << mat2[j][1] << " " << mat1[i][2] * mat2[j][2] << endl;
            }
        }
    }

    return 0;
}
