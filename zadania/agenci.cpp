#include <bits/stdc++.h>

using namespace std;


int bfs(queue<pair<pair<int, int>, int>> &queue, unordered_map<int, vector<int>> &graph) {
    set<pair<int, int>> s;

    s.insert(queue.front().first);

    while (!queue.empty()) {

        pair<pair<int, int>, int> stan = queue.front(); 
        queue.pop();

        for (int i : graph[stan.first.first]) {
            for (int j : graph[stan.first.second]) {

                pair<pair<int, int>, int> p = make_pair(make_pair(i, j), stan.second+1);

                if (s.find(p.first) == s.end()) {

                    if (p.first.first == p.first.second) {
                        return p.second;
                    }
                    s.insert(p.first);
                    queue.push(p);
                }
            }
        }
    }
    return -1; // ?
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<pair<int, int>, int>> queue;
    unordered_map<int, vector<int>> graph;

    int a, b;
    cin >> a >> b;
    pair<pair<int, int>, int> start = make_pair(make_pair(a, b), 0);
    queue.push(start);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int wynik = bfs(queue, graph);

    if (wynik==-1) cout << "NIE" << endl;
    else cout << wynik << endl;

    return 0;
}