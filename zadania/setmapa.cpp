#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int q;
    cin >> q;
    unordered_set<int> s;

    int a;
    for (int i = 0; i < q; i++) {
        cin >> a;

        s.insert(a);
        cout << s.size() << endl;
    }

    return 0;
}