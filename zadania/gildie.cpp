#include <bits/stdc++.h>

using namespace std;


void dfs(int i, char curr,  vector<vector<int>> &g, vector<bool> &visited, vector<char> &odp) {
    visited[i] = true;
    odp[i] = curr;

    for (int j : g[i]) {
        if (!visited[j]) {
            if (curr == 'K') {
                dfs(j, 'S', g, visited, odp);
            }
            else {
                dfs(j, 'K', g, visited, odp);
            }
        }
    }
}


void dfsUtil(vector<vector<int>> &g, vector<bool> &visited, vector<char> &odp) {
    char curr = 'K';
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            dfs(i, curr, g, visited, odp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, m;

    cin >> n;
    cin >> m;

    if (n == 1 || m == 0) {
        cout << "NIE" << endl;
    }
    else {
        int a, b;

        vector<vector<int>> g; g.resize(n);
        vector<bool> visited; visited.resize(n);

        int counter = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);

            if (!visited[a-1]) {
                visited[a-1] = true;
                counter++;
            }
            if (!visited[b-1]) {
                visited[b-1] = true;
                counter++;
            }
        }
        if (counter == n) {
            fill(visited.begin(), visited.end(), false);

            vector<char> odp; odp.resize(n);
            dfsUtil(g, visited, odp);

            cout << "TAK" << endl;
            for (char i : odp) {
                cout << i << endl;
            }
        }
        else {
            cout << "NIE" << endl;
        }
    }
    return 0;
}