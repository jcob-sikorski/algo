#include <bits/stdc++.h>

using namespace std;


void detectCycle(int node, int prev, vector<vector<int>> &g, vector<bool> &visited, vector<int> &cand, bool &cycle) {
    for (int i : g[node]) {
        if (visited[i] && i != prev) {
            cycle = true;
            cand.push_back(i);
        }
        else if (!visited[i]) {
            visited[i] = true;
            detectCycle(i, node, g, visited, cand, cycle);
        }
    }
}


bool dfsCycleUtil(vector<vector<int>> &g, vector<bool> &visited, vector<int> &cand) {
    bool cycle = false;
    
    for (int i = 0; i < g.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            detectCycle(i, i, g, visited, cand, cycle);

            if (!cycle) {
                return false;
            }
            cycle = false;
        }
    }

    return true;
}


void giveAnswer(int node, int prev, vector<vector<int>> &g, vector<bool> &visited, vector<int> &odp) {
    for (int i : g[node]) {
        if ((!visited[i] || i != prev) && odp[i] == 0) {
            visited[i] = true;
            odp[i] = node+1;
            giveAnswer(i, node, g, visited, odp);
        }
    }
}


void dfsAnswerUtil(vector<vector<int>> &g, vector<bool> &visited, vector<int> &cand, vector<int> &odp) {
    for (int i : cand) {
        if (!visited[i]) {
            visited[i] = true;
            giveAnswer(i, i, g, visited, odp);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g; g.resize(n);
    vector<bool> visited; visited.resize(n);
    vector<int> odp; odp.resize(n, 0);

    vector<int> cand;

    bool cycle;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    bool ok = dfsCycleUtil(g, visited, cand);
    if (ok) {
        cout << "TAK" << endl;
        fill(visited.begin(), visited.end(), false);

        dfsAnswerUtil(g, visited, cand, odp);
        for (int i : odp) {
            cout << i << endl;
        }
    }
    else {
        cout << "NIE" << endl;
    }

    return 0;
}