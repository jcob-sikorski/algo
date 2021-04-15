#include<bits/stdc++.h>

using namespace std;


class UnionFind
{
private:
    int size, numComponents;
    vector<int> compSize, id;

public:
    UnionFind(int size)
    {
        this->size = numComponents = size;

        compSize.resize(size);
        id.resize(size);

        for (int i = 0; i < size; i++) {
            id[i] = i;
            compSize[i] = 1;
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
            p = next;
        }

        return root;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    int componentSize(int p)
    {
        return compSize[find(p)];
    }

    int components()
    {
        return numComponents;
    }

    int getSize()
    {
        return size;
    }

    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 == root2) return;

        if (compSize[root1] < compSize[root2]) {
            compSize[root2] += compSize[root1];
            id[root1] = root2;
        }
        else {
            compSize[root1] += compSize[root2];
            id[root2] = root1;
        }
        numComponents--;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, m, k;
    cin >> n >> m >> k;

    UnionFind uf = UnionFind(n);

    int a, b;
    vector<pair<int, int>> v; v.reserve(m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        // uf.unify(a-1, b-1);
        v.push_back(make_pair(a-1, b-1));

        // int numComponents = uf.components();
        // if (uf.components() == k) {
        //     break;
        // }
    }

    int counter = 0;
    for (int i = v.size()-1; i >= 0; i--) {
        uf.unify(v[i].first, v[i].second);
        counter++;

        if (uf.components() == k) {
            break;
        }
    }

    cout << m - counter + 1 << endl;

    return 0;
}