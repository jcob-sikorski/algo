#include<bits/stdc++.h>

using namespace std;

void max_sum(int v, int k, int base, vector<int> &tree, vector<vector<int>> &dp) {
    if (v > base) {
        return;
    }
    dp[v][1] = tree[v];

    max_sum(v*2, k-1, base, tree, dp);
    max_sum(v*2 + 1, k-1, base, tree, dp);

    if (2*v < base) {
        for (int i = 2; i <= k; i++) {
            dp[v][i] = dp[v][1];
            vector<int> maxValue = {dp[2*v][k-i], dp[2*v + 1][i-1], dp[2*v][i-1], dp[2*v + 1][k-i]};

            int max_value = INT32_MIN;
            for (int j : maxValue) {
                max_value = max(max_value, j);
            }
            dp[v][i] += max_value;
            tree[0] = max(tree[0], dp[1][i]);
        }
    }
    // bottom-up approach
    // we calculate maximum for each node by max(L[k1, k2, ..., k-limit], R[k1, k2, ..., k-limit])
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int size = 2 << n;
    int base = 2 << (n-1);

    vector<int> tree;
    tree.resize(base);
    
    vector<vector<int>> dp;
    dp.resize(base);

    int a, b;
    for (int i = 1; i < base; i++) {
        cin >> a >> b;
        tree[i] = a + b;
    }
    for (int i = 1; i < base; i++) {
        dp[i].resize(k);
    }

    max_sum(1, k-1, base-1, tree, dp);

    int max_value = INT32_MIN;
    for (int i : dp[1]) {
        max_value = max(max_value, i);
    }
    cout << max_value << endl;
    return 0;
}