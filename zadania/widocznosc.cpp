#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    stack<pair<int, int>> p;
    int a;
    cin >> a;
    p.push(make_pair(a, 0));
    cout << -1 << endl;

    for (int i = 1; i < n; i++) {
        cin >> a;

        while (!p.empty() && a >= p.top().first) {
            p.pop();
        }
        if (!p.empty()) {
            cout << p.top().second+1 << endl;
        }
        else {
            cout << -1 << endl;
        }
        
        p.push(make_pair(a, i));
    }

    return 0;
}