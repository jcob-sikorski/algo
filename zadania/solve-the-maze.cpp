#include<bits/stdc++.h>

using namespace std;


void bfs(queue<pair<int, int>> &q, vector<vector<char>> &mat, int &count_bad, int &n, int &m)
{

	if (mat[n-1][m-1] == 'B') {
		return;
	}
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();


		// top
        if (p.first-1 >= 0) {
			char cell = mat[p.first-1][p.second];
			if (cell == 'G') {
				return;
			}
			else if (cell == '.') {
				mat[p.first-1][p.second] = '#';
			}
        }
        // bottom
        if (p.first+1 < n) {
			char cell = mat[p.first+1][p.second];
			if (cell == 'G') {
				return;
			}
			else if (cell == '.') {
				mat[p.first+1][p.second] = '#';
			}
        }

        // left
        if (p.second-1 >= 0) {
			char cell = mat[p.first][p.second-1];
			if (cell == 'G') {
				return;
			}
			else if (cell == '.') {
				mat[p.first][p.second-1] = '#';
			}
        }
        // right
        if (p.second+1 < m) {
			char cell = mat[p.first][p.second+1];
			if (cell == 'G') {
				return;
			}
			else if (cell == '.') {
				mat[p.first][p.second+1] = '#';
			}
        }
		count_bad--;
	}
}


void dfs(pair<int, int> &p, vector<vector<char>> &mat, vector<vector<bool>> &vis, int &n, int &m, int &counter)
{
	vis[p.first][p.second] = true;

	// top
    if (p.first-1 >= 0 && !vis[p.first-1][p.second]) {
		char cell = mat[p.first-1][p.second];
		pair<int, int> coor = make_pair(p.first-1, p.second);

		if (cell == 'G') {
			dfs(coor, mat, vis, n, m, --counter);
		}
		else if (cell == '.') {
			dfs(coor, mat, vis, n, m, counter);
		}
    }
    // bottom
    if (p.first+1 < n && !vis[p.first+1][p.second]) {
		char cell = mat[p.first+1][p.second];
		pair<int, int> coor = make_pair(p.first+1, p.second);

		if (cell == 'G') {
			dfs(coor, mat, vis, n, m, --counter);
		}
		else if (cell == '.') {
			dfs(coor, mat, vis, n, m, counter);
		}
    }

    // left
    if (p.second-1 >= 0 && !vis[p.first][p.second-1]) {
		char cell = mat[p.first][p.second-1];
		pair<int, int> coor = make_pair(p.first, p.second-1);

		if (cell == 'G') {
			dfs(coor, mat, vis, n, m, --counter);
		}
		else if (cell == '.') {
			dfs(coor, mat, vis, n, m, counter);
		}
    }
    // right
    if (p.second+1 < m && !vis[p.first][p.second+1]) {
		char cell = mat[p.first][p.second+1];
		pair<int, int> coor = make_pair(p.first, p.second+1);
		if (cell == 'G') {
			dfs(coor, mat, vis, n, m, --counter);
		}
		else if (cell == '.') {
			dfs(coor, mat, vis, n, m, counter);
		}
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	
	int t, n, m, count_bad;
	char a;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		vector<vector<char>> mat(n, vector<char>(m));
		queue<pair<int, int>> q;

		int Gcounter = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> a;
				mat[j][k] = a;

				if (a == 'B') {
					q.push(make_pair(j, k));
				}
				else if (a == 'G') {
					Gcounter++;
				}
			}
		}
		count_bad = q.size();
		bfs(q, mat, count_bad, n, m);

		if (count_bad == 0 && (mat[n-1][m-1] == '.' || Gcounter == 0)) {
			vector<vector<bool>> vis(n, vector<bool>(m, false));
			pair<int, int> p = make_pair(n-1, m-1);

			dfs(p, mat, vis, n, m, Gcounter);

			if (!Gcounter) {
				cout << "Yes" << endl;
				continue;
			}
		}
		cout << "No" << endl;
	}

	return 0;
}