#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    int d, w;

    stack<int> stos;

    int counter = 0;
    for (int i = 0; i < n; i++) {
        cin >> d >> w;

        while (!stos.empty() && stos.top() > w) {
            stos.pop();
        }

        if (stos.empty() || stos.top() < w) {
            stos.push(w);
            counter++;
        }
    }

    cout << counter << endl;
}