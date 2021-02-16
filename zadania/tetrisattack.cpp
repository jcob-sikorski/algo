#include <bits/stdc++.h>

using namespace std;

void tet(stack<int> &sta, stack<int> &cop, vector<bool> &visited, int &wynik, vector<int> &opis) {
    while (!sta.empty()) {
        int x = sta.top();
        sta.pop();

        if (!visited[x-1]) {
            visited[x-1] = true;
            cop.push(x);
        }
        else if (cop.empty()) {
            fill(visited.begin(), visited.end(), false);
        }
        else {
            int i = cop.size();
            int y = cop.top();
            cop.pop();

            if (x != y) {
                sta.push(y); sta.push(x);
                opis.push_back(i);
                // cout << i << " " << i+1 << endl;
                wynik++;
            }
        }
    }
}


int main() {
    stack<int> sta, cop;

    int n;
    cin >> n;

    vector<bool> visited; visited.resize(n);

    int a;
    for (int i = 0; i < 2*n; i++) {
        cin >> a;
        sta.push(a);
    }

    int wynik = 0;
    vector<int> opis;

    tet(sta, cop, visited, wynik, opis);

    cout << wynik << endl;
    for (int i : opis) {
        cout << i << endl;
    }
    cout << endl;
}