#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<vector<int>> &g, vector<bool> &visited) {
    visited[i] = true;
    for (int j : g[i]) {
        if (!visited[j]) {
            dfs(j, g, visited);
        }
    }
}


int dfsUtil(vector<vector<int>> &g, vector<bool> &visited) {
    int counter = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            dfs(i, g, visited);
            counter++;
        }
    }
    return counter;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    vector<vector<int>> g; g.resize(n);
    vector<bool> visited; visited.resize(n);

    int a;
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        g[i].push_back(a-1);
        g[a-1].push_back(i);
    }

    int wynik = dfsUtil(g, visited);

    cout << wynik << endl;

    return 0;
}