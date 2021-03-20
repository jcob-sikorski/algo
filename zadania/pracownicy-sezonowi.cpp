#include <bits/stdc++.h>

using namespace std;


long double pra(int n, long double k, long double lo, long double hi, vector<long double> v) {
    long double mid;
    for (int i = 0; i < 60; i++) {
        mid = lo + (hi-lo)/2;

        unsigned long long int pracownicy = 0;
         for (int i = 0; i < n; i++) {
            pracownicy += ceil(v[i]/mid);
        }

        if (pracownicy <= k) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }

    return mid;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    long double k;
    cin >> k;

    vector<long double> v;

    long double a;
    long double lo = 0;
    long double hi = DBL_MIN;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);

        hi = max(hi, a);
    }

    cout << fixed << showpoint;
    cout << setprecision(9);

    cout <<  pra(n, k, lo, hi, v) << endl;

    return 0;
}