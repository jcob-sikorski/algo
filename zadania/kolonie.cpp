#include<bits/stdc++.h>

using namespace std;

class UnionFind
{
private:
    int size, numComponents;
    vector<int> compSize, id, masa, iqMax, iqMin;

public:
    UnionFind(int size)
    {
        this->size = numComponents = size;

        compSize.resize(size);

        id.resize(size);

        masa.resize(size);

        iqMax.resize(size);
        iqMin.resize(size);

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

    void setComp(int index, int m, int iq)
    {
        masa[index] = m;
        iqMax[index] = iq;
        iqMin[index] = iq;
    }

    void JOIN(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 == root2) return;

        if (compSize[root1] < compSize[root2]) {
            compSize[root2] += compSize[root1];

            masa[root2] += masa[root1];

            iqMax[root2] = max(iqMax[root2], iqMax[root1]);
            iqMin[root2] = min(iqMin[root2], iqMin[root1]);

            id[root1] = root2;
        }
        else {
            compSize[root1] += compSize[root2];

            masa[root1] += masa[root2];

            iqMax[root1] = max(iqMax[root1], iqMax[root2]);
            iqMin[root1] = min(iqMin[root1], iqMin[root2]);

            id[root2] = root1;
        }
        numComponents--;
    }

    int IQ_MAX(int p)
    {
        return iqMax[find(p)];
    }

    int IQ_MIN(int p)
    {
        return iqMin[find(p)];
    }

    int MASA(int p)
    {
        return masa[find(p)];
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    UnionFind uf = UnionFind(n);

    int m, iq;
    for (int i = 0; i < n; i++) {
        cin >> m >> iq;
        uf.setComp(i, m, iq);
    }

    unordered_map<string, int> mapper(
        {
            {"MASA", 0},
            {"IQ_MIN", 1},
            {"IQ_MAX", 2},
            {"JOIN", 3}
        }
    );

    cin.ignore();

    string line, op;
    int a, b;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        stringstream ss(line);
        ss >> op;

        switch (mapper[op]) {
            case 0:
            {
                ss >> a;
                int masa = uf.MASA(a-1);
                cout << masa << endl;
                break;
            }
            case 1:
            {
                ss >> a;
                int iq_min = uf.IQ_MIN(a-1);
                cout << iq_min << endl;
                break;
            }
            case 2:
            {
                ss >> a;
                int iq_max = uf.IQ_MAX(a-1);
                cout << iq_max << endl;
                break;
            }
            default:
            {
                ss >> a >> b;
                uf.JOIN(a-1, b-1);
                break;
            }
        }
    }

    return 0;
}
