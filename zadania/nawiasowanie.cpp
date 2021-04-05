#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;

    cin >> n;
    // string n = ")(()()))(()";

    // string s = "";

    int o = 0;

    int counter = 0;
    for (int i = 0; i < n.size(); i++) {
        if ( n[i] == ')' ) {
            if (o) {
                // s += ")";
                o--;
            }
            else {
                counter++;
            }
        }
        else if ( n[i] == '(' ) {
            if (i+1 == n.size()) {
                counter++;
            }
            else {
                o++;
                // s += "(";
            }
        }
    }
    counter += o;

    cout << counter << endl;

    return 0;
}