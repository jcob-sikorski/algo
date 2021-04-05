#include<bits/stdc++.h>

using namespace std;

struct backtrack {
    int node;
    int dist;
};

void bfs(int i, vector<vector<int>> &v, vector<vector<int>> &dist, vector<backtrack> szlak, int d=0) {
    for (int j : v[i]) {
        if (dist[i][j] == INT32_MAX) {
            for (backtrack x : szlak) {
                dist[j][x.node] = d - x.dist;
                // dist[node_d.first][j] = d - node_d.second;
            }

            szlak.push_back({j, d});
            bfs(j, v, dist, szlak, d+1);

        }
    }
}

void bfsUtil(int start, vector<vector<int>> &v, vector<vector<int>> &dist) {
    vector<bool> vis(v.size(), false);
    vector<backtrack> szlak;
    
    szlak.push_back({start, 0});
    for (int i : v[start]) {
        if (dist[start][i] == INT32_MAX) {

            // odleglosc od sasiada zawsze rowna 1
            dist[start][i] = 1;
            szlak.push_back({i, 1});

            bfs(i, v, dist, szlak, 1);
            szlak.erase(szlak.begin(), szlak.end());
        }
    }
}

int main () {
    int n, m, k;
    cin >> n >> m >> k;


    vector<vector<int>> v(2*n+2, vector<int>());
    vector<vector<int>> dist(v.size(), vector<int>(2*n+2, INT32_MAX));

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b+n);
        v[b].push_back(a+n);

        v[a+n].push_back(b);
        v[b+n].push_back(a);
    }

    int s, t;
    long d;
    for (int i = 0; i < k; i++) {
        cin >> s >> t >> d;

        bfsUtil(s, v, dist);
        int dist1 = dist[s][t+n];
        int dist2 = dist[t][s+n];

        int dist3 = dist[s+n][t];
        int dist4 = dist[t+n][s];

        cout << i << endl;

        // if (dist[t][s] <= d && ((dist[t][s] & 1) && (d &1))) {
        //     cout << "TAK" << endl;
        // }
        // else {
        //     cout << "NIE" << endl;
        // }
    }

    // jest błąd kiedy idzie do samego siebie (chyba?)

    return 0;
}