#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    string arr;
    cin >> arr;

    vector<unsigned long long> nas; nas.resize(n);
    vector<unsigned long long> rub; rub.resize(n);
    vector<unsigned long long> pref; pref.resize(n);

    if (arr[0] == 'R') {
        rub[0] = 1ULL;
    }
    else {
        nas[0] = 1ULL;
    }
    pref[0] = 0ULL;

    for (int i = 1; i < n; i++) {
        if (arr[i] == 'R') {
            rub[i] = rub[i-1] + 1ULL;
            nas[i] = nas[i-1];
        }
        else {
            nas[i] = nas[i-1] + 1ULL;
            rub[i] = rub[i-1];
        }

        if (nas[i] > nas[i-1] && rub[i] > 0ULL) {
            pref[i] = pref[i-1] + rub[i];
        }
        else {
            pref[i] = pref[i-1];
        }
    }

    int t, a, b;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        unsigned long long wynik;
        if (a >= 2) {
            wynik = pref[b-1] - pref[a-2] - rub[a-2] * (nas[b-1] - nas[a-2]);
        }
        else {
            wynik = pref[b-1];
        }
        cout << wynik << endl;
    }

    return 0;
}