#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;

    for (int j = 0; j < t; j++) {
        int n, q;
        cin >> n >> q;

        vector<int> v;
        v.reserve(n);

        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }

        if (v.size() == 1) {
            cout << v[0] << endl;
            continue;
        }

        unsigned long long int res = 0;
        int minimum = 0;
        int maximum = v[0];

        int max_elem = 0;
        for (int i = 1; i < n; i++) {
            max_elem = max(max_elem, v[i]);
            // if previous element is greater than current mark current as minimum
            if (v[i-1] > v[i]) {
                minimum = v[i];
            }

            // if previous element is less than current mark current as max
            if (v[i-1] < v[i]) {
                if (minimum > 0) {
                    res += maximum - minimum; // this works unless we have got defined two peaks
                }
                maximum = v[i];
                minimum = 0;
            }
        }
        // we have to do it again because there is a possibility that such case happened
        // but haven't got next cycle to do this operation
        res += maximum;

        cout << max(res, static_cast<unsigned long long int>(max_elem)) << endl;
    }
    return 0;
}