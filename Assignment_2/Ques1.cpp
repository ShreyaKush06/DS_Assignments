#include <iostream>
using namespace std;

int main() {

    int arr[] = {2, 4, 6, 12, 14, 16, 22, 24, 26, 32, 34};
    int n = sizeof(arr) / sizeof(arr[0]); // number of elements

    int target = 16; // the number we want to search
    int low = 0;          // start index
    int high = n - 1;     // end index
    bool not_found = true;   // flag to track if element is found

    // Binary Search process
    while (low <= high) {
        int mid = (low + high) / 2;  
        int guess = arr[mid];      

        if (guess == target) {
            cout << "Found " << target << " at index " << mid << endl;
            not_found = false;
            break;
        }
        else if (guess < target) {
            // If target is greater, then ignore left half
            low = mid + 1;
        }
        else {
            // If target is smaller, then ignore right half
            high = mid - 1;
        }
    }

    if (not_found) {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
