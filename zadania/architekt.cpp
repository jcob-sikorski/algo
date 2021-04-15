#include <bits/stdc++.h>

using namespace std;


class UnionFind
{
private:
    int size;
    vector<int> id, height;

public:
    UnionFind(int size)
    {
        this->size = size;

        id.resize(size);
        height.resize(size);

        for (int i = 0; i < size; i++) {
            id[i] = i;
        }
    }

    int find(int p)
    {
        int root = p;
        while (root != id[root]) {
            root = id[root];
        }

        while (p != root) {
            int next = id[p];
            id[p] = root;
            int next_height = height[next];
            height[p] += height[next];
            p = next;
        }

        return root;
    }

    bool unify(int p, int q, int w)
    {
        int rootp = find(p);
        int rootq = find(q);

        int hp = height[p] + height[rootp];
        int hq = height[q];

        if (rootp == rootq) {
            if (height[p] == (height[q] + w)) {
                return true;
            }
            return false;
        }

        id[rootp] = rootq;
        height[rootp] = height[q] + height[rootq] + w;
        hp = height[rootp];

        return true;
    }

    void print()
    {
        for (int k = 1; k < height.size(); k++) {
            cout << k << ": " << height[k] << endl;
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, q;
    cin >> n >> q;

    UnionFind uf = UnionFind(n+1);

    int i, j, w;
    for (int a = 0; a < q; a++) {
        cin >> i >> j >> w;

        if (uf.unify(i, j, w)) {
            cout << "TAK" << endl;
        }
        else {
            cout << "NIE" << endl;
        }
        uf.print();
    }

    return 0;
}

// brak kaskadacji 



// 7 7
// 3 2 1
// 2 1 1
// 4 5 -1
// 5 6 1
// 6 7 1
// 3 4 -1
// 1 6 -2



// 4 4
// 1 2 1
// 2 3 1
// 3 4 1
// 1 4 3