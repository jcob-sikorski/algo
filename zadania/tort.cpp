#include<bits/stdc++.h>

using namespace std;

int cnt(long long s, vector<long long> &y, vector<long long> &x) {
    int res = 0;

    int n = x.size();

    int j = -1;
    for (int i = n-1; i >= 0; i--) {
        while (j < n-1 && x[j+1]*y[i] < s) {
            j++;
        }
        res += n - j;
    }
    return res;
}


int bin(long long K, vector<long long> &y, vector<long long> &x) {
    long long p, k, s;

    p = x[0]*y[0];
    k = x[x.size()-1]*y[y.size()-1];

    while (p < k) {
        s = p + (k-p)/2;

        if (cnt(s, y, x) < K) k = s-1;
        else p = s;
    }
    return s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    long long int a, b, n, K;
    cin >> a >> b >> n >> K;

    vector<long long int> x;
    x.reserve(n+1);

    long long int prev = 0;
    long long int temp;
    for (long long int i = 0; i < n; i++) {
        cin >> temp;
        x.push_back(temp-prev);
        prev = temp;
    }
    x.push_back(a-prev);
    sort(x.begin(), x.end());

    vector<long long int> y;
    y.reserve(n+1);

    prev = 0;
    for (long long int i = 0; i < n; i++) {
        cin >> temp;
        y.push_back(temp-prev);
        prev = temp;
    }
    y.push_back(b-prev);
    sort(y.begin(), y.end());

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << y[i]*x[j] << " ";
        } cout << endl;
    }

    cout << bin(K, y, x);
    return 0;
}