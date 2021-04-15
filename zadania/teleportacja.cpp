#include<bits/stdc++.h>

using namespace std;


// zwraca indeks najbliższej wartości <= x
int beforeeq(long long int x, vector<long long int> &arr) {
    int l = 0;
    int r = arr.size()-1;

    int index = 0;
    long long int min = LLONG_MAX;

    while (l <= r) { 
        int m = l + (r - l) / 2; 
        long long int absolute = abs(arr[m] - x);

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int n; cin >> n;
    long long int sum = 0;
    long long int curr = 1;

    int wynik = 0;

    vector<long long int> added;

    while (sum + curr < n) {
        sum += curr;
        added.push_back(curr);

        curr *= 2;
        wynik++;
    }

    n -= sum;

    while (n > 0) {
        int index = beforeeq(n, added);
        n -= added[index];

        wynik++;
    }

    cout << wynik << endl;
    return 0;

    // cout << "Minimum value for int: " << numeric_limits<long long int>::min() << '\n';
    // cout << "Maximum value for int: " << numeric_limits<long long int>::max() << '\n';
    // return 0;
}