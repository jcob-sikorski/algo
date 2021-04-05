#include<bits/stdc++.h>

using namespace std;


int main() {
    unsigned long long n;
    unsigned long long b;
    unsigned long long cb;

    cin >> n >> b;
    cb = b;

    unordered_set<string> rep;
    vector<string> v;

    string s = "";
    unsigned long long a;
    for (unsigned long long i = 0; i < n; i++) {
        cin >> a;
        s += to_string(a);
    }

    // cin >> a;
    // s += to_string(a);

    reverse(s.begin(), s.end());
    rep.insert(s);
    v.push_back(s);

    unsigned long long cnt = 1; // liczy elementy w cyklu
    while (cb > 0) {
        string prev = v[cnt-1];

        for (unsigned long long i = 0; i < n; i++) {
            // if 1
            // unsigned long long index = (i+1)%n;
            // unsigned long long valid = prev[(i+1)%n]-'0';
            
            if (prev[(i+1)%n]-'0') {
                // unsigned long long to_change = (prev[i]-'0') ^ 1;
                // char digit = ((prev[i]-'0') ^ 1)+'0';
                s[i] = ((prev[i]-'0') ^ 1)+'0';
            }
        }
        // DEBUG
        // cout << s << endl;
        if (rep.find(s) != rep.end()) {
            // DEBUG
            // cout << "cnt = " << cnt << " " << s << endl;
            break;
        }
        rep.insert(s);
        v.push_back(s);
        prev = s;
        cnt++;
        cb--;
    }
    unsigned long long start = cnt%n;
    unsigned long long index;

    // problem_______________
    if (b <= cnt) {
        s = v[b];
    }
    else {
        index = ((b-start) % cnt) + start;
        s = v[index];
    }

    reverse(s.begin(), s.end());

    cout << "_______" << endl;
    for (unsigned long long i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}