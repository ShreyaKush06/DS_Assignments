#include<iostream>
using namespace std;
int LinearSearch(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        if (arr[i] != i + 1) {
            return i + 1; // Returning the missing element
        }
    }
    return n; // If all elements are present, return n
}
int BinarySearch(int arr[], int n) {
    int low = 0;
    int high = n - 2; 
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != mid + 1) {
            // If the mid element is not equal to its index + 1, then missing element is on the left side
            high = mid - 1;
        } else {
            // If the mid element is equal to its index + 1, the missing element is on the right side
            low = mid + 1;
        }
    }
    return low + 1; // The missing element will be at index low
}
int main() {
    int n;
    cout<< "Enter the number upto which elements are to be added: ";
    cin >> n; // Read the number of elements in the array      
    int arr[n - 1];
    cout << "Enter " << n - 1<< " elements from 1 to " << n << "with one missing element: ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    cout<<"Missing element (using linear search): "<<LinearSearch(arr, n) << endl;
    cout<<"Missing element (using binary search): "<<BinarySearch(arr, n) << endl;

    

    return 0;
}