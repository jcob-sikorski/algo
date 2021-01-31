#include <bits/stdc++.h>

using namespace std;


class UnionFind {

private:

    // The number of elements in this union find
    int size;

    // Used to track the size of each of the component
    vector<int> sz;

    // id[i] points to the parent of i, if id[i] = i then i is a root node
    vector<int> id;

    // Tracks the number of components in the union find
    int numComponents;

public:

    // init
    void unionFind(int size) {

        this->size = numComponents = size;

        sz.resize(size);
        id.resize(size);

        for (int i = 0; i < size; i++) {
            id[i] = i; // Link to itself (self root)
            sz[i] = 1; // Each component is originally of size one
        }
    }

    // Find which component/set 'p' belongs to, takes amortized constant time.
    int find(int p) {

        // Find the root of the component/set
        int root = p;

        while (root != id[root]) {
            root = id[root];
        }

        // Compress the path leading back to the root.
        // Doing this operation is called "path compression"
        // and is what gives us amortized time complexity.
        while (p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }

    // Unify the components/sets containing elements 'p' and 'q'
    void unify(int p, int q) {

        int root1 = find(p);
        int root2 = find(q);

        // These elements are already in the same group!
        if (root1 == root2) {
            return;
        }

        // Merge smaller component/set into the larger one.
        if (sz[root1] < sz[root2]) {
            sz[root2] += sz[root1];
            id[root1] = root2;
        } else {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }

        // Since the roots found are different we know that the
        // number of components/sets has decreased by one
        numComponents--;
    }


    // Return whether or not the elements 'p' and
    // 'q' are in the same components/set.
    bool connected(int p, int q) {
      return find(p) == find(q);
    }

    // Return the size of the components/set 'p' belongs to
    int componentSize(int p) {
        return sz[find(p)];
    }

    // Return the number of elements in this UnionFind/Disjoint set
    int elements() {
        return size;
    }

    // Returns the number of remaining components/sets
    int components() {
        return numComponents;
    }
};



int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    unordered_map<char, int> alphaOrder; // indeks każdej z liter alfabetu
    for (int i = 0; i < alphabet.size(); i++) {
        alphaOrder[alphabet[i]] = i;
    }

    int x; // liczba równań
    int k; // liczba zmiennych
    cin >> x;
    cin >> k;

    // string alphabet 
    vector<int> varLen;
    int len;
    for (int i = 0; i < k; i++) {
        cin >> len;
        varLen.push_back(len);
    }

    int counter = 0;
    unordered_map<string, int> bijection; // przypisujemy wartość każdemu typowi komórki
    for (int i = 0; i < varLen.size(); i++) {
        for (int j = 0; j < varLen[i]; j++) {
            bijection[alphabet[i] + to_string(j)] = counter;
            counter++;
        }
    }

    unordered_map<int, vector<int>> g; // graf

    UnionFind uf;

    uf.unionFind(counter);

    for (int i = 0; i < x; i++) {
        int l;
        cin >> l;
        string L;
        cin >> L;

        int r;
        cin >> r;
        string R;
        cin >> R;

        vector<pair<int, int>> dependent; // łączymy równoległe do siebie komórki w równaniu

        int lLen = 0; // rzeczywista długość lewej strony równania

        for (int j = 0; j < L.size(); j++) {
            if (isalpha(L[j])) {
                for (int m = 0; m < varLen[alphaOrder[L[j]]]; m++) { // indeks w zmiennej
                    int bi = bijection[L[j] + to_string(m)]; // przypisana wartość do typu komórki
                    dependent.push_back(make_pair(bi, 0));
                    lLen++;
                }
            } 
            else {
                dependent.push_back(make_pair(L[j]-'0', 0));
                lLen++;
            }
        }
        int rLen = 0;
        for (int j = 0; j < R.size(); j++) {
            if (isalpha(R[j])) {
                for (int m = 0; m < varLen[alphaOrder[R[j]]]; m++) {
                    int bi = bijection[R[j] + to_string(m)];
                    dependent[rLen].second = bi;
                    rLen++;
                }
            }
            else {
                dependent[rLen].second = R[j]-'0';
                rLen++;
            }
        }
        if (lLen != rLen) { // jeśli długość stron równania nie jest równa to równanie jest sprzeczne
            continue;
        }

        for (pair<int, int> p: dependent) { // łączymy zależne od siebie grupy komórek
            uf.unify(p.first, p.second);
        }
    }
    int wynik = 1;
    wynik <<= uf.components(); // wynikiem jest 2 do liczby grup

    cout << wynik << endl;
    cout << endl;
}