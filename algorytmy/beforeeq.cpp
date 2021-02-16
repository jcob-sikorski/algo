#include<bits/stdc++.h>

using namespace std;


// zwraca indeks najbliższej wartości <= x
int beforeeq(int x, vector<int> &arr) {
    int l = 0;
    int r = arr.size()-1;

    int index = 0;
    int min = INT32_MAX;

    while (l <= r) { 
        int m = l + (r - l) / 2; 
        int absolute = abs(arr[m] - x);

        if (absolute < min && arr[m] <= x) {
            min = absolute;
            index = m;
        }

        // If x greater, ignore left half 
        if (arr[m] <= x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    }

    return index;
}