#include <bits/stdc++.h>

using namespace std;


int main() {
    unsigned long long int b = 0;

    vector<bool> v = {1,0,1};
    reverse(v.begin(), v.end());

    unordered_map<string, int> s;

    while (b < 9000) {
        b++;
        string arr = "";
        for (int i = 0; i < v.size(); i++) {
            if (v[(i+1) % v.size()]) {
                v[i] ^= 1;
            }
            cout << v[i] << " ";
            arr += to_string(v[i]);
        } cout << endl;

        if (s.find(arr) != s.end()) {
            cout << "-------------------------------- diff of indexes = " << b - s[arr] << endl;
        }
        s[arr] = b;
    }
    return 0;
}