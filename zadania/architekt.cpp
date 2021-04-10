#include <bits/stdc++.h>

using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, q;
    cin >> n >> q;

    vector<int> v(n+1, INT32_MAX);

    int i, j, w;
    for (int x = 0; x < q; x++) {
        cin >> i >> j >> w;

        if (v[i] == INT32_MAX && v[j] != INT32_MAX) {
            v[i] = v[j] + w;
            cout << "TAK" << endl;
        }
        else if (v[i] != INT32_MAX && v[j] == INT32_MAX) {
            v[j] = v[i] - w;
            cout << "TAK" << endl;
        }
        else if (v[i] != INT32_MAX && v[j] != INT32_MAX) {
            if (v[i] == v[j]+w) {
                cout << "TAK" << endl;
            }
            else {
                cout << "NIE" << endl;
            }
        }
        else {
            v[i] = 0;
            v[j] = -w;
            cout << "TAK" << endl;
        }
        // for (int k = 0; k <= n; k++) {
        //     cout << k << ": " << v[k] << " ";
        // } cout << endl;
    }


    return 0;
}