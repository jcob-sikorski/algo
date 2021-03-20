#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &matrix, queue<pair<int, int>> &q) {
    int n = matrix.size();
    int m = matrix[0].size();

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        //top
        if (curr.first-1 >= 0 && matrix[curr.first-1][curr.second] == 0) {
            matrix[curr.first-1][curr.second] = matrix[curr.first][curr.second]+1;
            q.push(make_pair(curr.first-1, curr.second));
        }
        //bottom
        if (curr.first+1 < n && matrix[curr.first+1][curr.second] == 0) {
            matrix[curr.first+1][curr.second] = matrix[curr.first][curr.second]+1;
            q.push(make_pair(curr.first+1, curr.second));
        }

        //right
        if (curr.second-1 >= 0 && matrix[curr.first][curr.second-1] == 0) {
            matrix[curr.first][curr.second-1] = matrix[curr.first][curr.second]+1;
            q.push(make_pair(curr.first, curr.second-1));
        }
        //left
        if (curr.second+1 < m && matrix[curr.first][curr.second+1] == 0) {
            matrix[curr.first][curr.second+1] = matrix[curr.first][curr.second]+1;
            q.push(make_pair(curr.first, curr.second+1));
        }

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    queue<pair<int, int>> q;

    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < m; j++) {
            if (a[j]-'0') {
                matrix[i][j] = 1;
                q.push(make_pair(i, j));
            }
        }
    }
    bfs(matrix, q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j]-1 << " ";
        }
        cout << endl;
    }
    return 0;
}