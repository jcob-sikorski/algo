#include<bits/stdc++.h>

using namespace std;


// szukamy indeksu najbliższej wartości >= x
int aftereq(int x, vector<int> &arr) {
    int l = 0;
    int r = arr.size()-1;

    int index = 0;
    int min = INT32_MAX;

    while (l <= r) { 
        int m = l + (r - l) / 2; 
        int absolute = abs(arr[m] - x);

        if (absolute < min && arr[m] >= x) {
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


int main() {
    vector<int> arr = {1, 3, 5, 6, 9, 11, 15, 19};

    aftereq(13, arr);
}