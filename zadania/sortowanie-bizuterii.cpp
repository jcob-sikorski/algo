#include <bits/stdc++.h>

using namespace std;


struct less_than_key
{
    inline bool operator() (const string &s1, const string &s2)
    {
        if (s1.size() == s2.size()) {
            return s1 < s2;
        }
        return s1.size() < s2.size();
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    vector<string> v;
    v.reserve(n);

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), less_than_key());

    for (string i : v) {
        cout << i << endl;
    }

    return 0;
}