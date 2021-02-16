#include <bits/stdc++.h>

using namespace std;


void detectCycle(int node, int prev, vector<vector<int>> &g, vector<bool> &visited, vector<int> &odp, bool &cycle) {
    for (int i : g[node]) {
        if (visited[i] && i != prev) {
            cycle = true;
        }
        else if (!visited[i]) {
            cout << "node " << node << " i " << i << endl;
            visited[i] = true;
            detectCycle(i, node, g, visited, odp, cycle);
        }
    }
}


bool dfsUtil(vector<vector<int>> &g, vector<bool> &visited, vector<int> &odp) {
    bool cycle = false;
    
    for (int i = 0; i < g.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            detectCycle(i, i, g, visited, odp, cycle);

            if (!cycle) {
                return false;
            }
            cycle = false;
        }
    }

    return true;
}


// https://szkopul.edu.pl/problemset/problem/ptF7RsWMiiMdzzZWt5BKFAnT/site/?key=statement
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g; g.resize(n);
    vector<bool> visited; visited.resize(n);
    vector<int> odp; odp.resize(n);

    bool cycle;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    bool f = dfsUtil(g, visited, odp);
    cout << endl;
    if (b) {
        cout << "TAK" << endl;
        // for (int i : odp) {
        //     cout << i+1 << endl;
        // }
    }
    else {
        cout << "NIE" << endl;
    }

    return 0;
}