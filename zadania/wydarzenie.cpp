#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

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


    int n;
    cin >> n;

    UnionFind uf = UnionFind(n+1);

    int xi;
    for (int i = 1; i <= n; i++) {
        cin >> xi;
        if (xi != 0) {
            uf.unify(xi, i);
        }
    }

    int k;
    cin >> k;

    set<int> roots;

    int a;
    for (int i = 0; i < k; i++) {
        cin >> a;
        roots.insert(uf.find(a));
    }

    cout << roots.size() << endl;

    return 0;
}