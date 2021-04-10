#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    unordered_map<int, pair<int, int>> m;
    vector<int> v;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;

        if (m.find(a) == m.end()) {
            m[a].first = i;
            m[a].second = i;
        }
        else {
            m[a].second = i;
        }
        v.push_back(a);
    }

    int counter = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
        pair<int, int> p = m[v[i]];
        if (m[v[i]].second == i && p.first > start) {
            start = i;
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}