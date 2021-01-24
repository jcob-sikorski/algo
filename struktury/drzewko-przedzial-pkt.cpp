#include <bits/stdc++.h>

using namespace std;

// update na przedziale x-y
void update(int x, int y, int val, int base, vector<int> &tree) {
    x += base-1;
    y += base+1;

    int suma = 0;

    while (y-x > 1) {
        if (!(x&1)) {
            // DEBUG
            tree[x+1] += val;
            suma = tree[x+1];
        }

        if (y&1) {
            tree[y-1] += val;
            suma = tree[y-1];
        }

        x >>= 1; y >>=1;
    }
}

// zapytanie o sumę od pojedynczej komórki w górę
int query(int index, int base, const vector<int> &tree) {
    int res = 0;

    index += base;

    while (index) {
        res += tree[index];
        index >>= 1;
    }
    return res;
}

// konstruujemy drzewo w czasie O(n)
void construct(int base, vector<int> &arr, vector<int> &tree) {
    int end = base + arr.size();

    for (int i = base; i < end; i++) {
        // DEBUG
        int suma = arr[i-base];
        tree[i] = suma;
    }

    base >>= 1; end >>= 1;

    while (base) {
        for (int i = base; i <= end; i++) {
            // DEBUG
            int sum = 0;
            sum += tree[i*2];
            sum += tree[i*2+1];

            tree[i] = sum;
        }
        base >>= 1; end >>= 1;
    }
}


void display(int base, const vector<int> &arr, const vector<int> &tree) {
    int end = base + arr.size();

    while (base) {

        for (int i = base; i <= end; i++) {
            cout << tree[i] << " ";
        }
        base >>= 1; end >>= 1;

        cout << endl;
    }
}




int main() {
    vector<int> arr = {2, 4, -1, 6, 8, -7};

    int base = 1;

    while (base < arr.size()) {
        base <<= 1;
    }

    vector<int> tree;   tree.resize(base*2, 0);

    construct(base, arr, tree);

    display(base, arr, tree);

    query(4, base, tree);

    update(1, 4, 3, base, tree);

    display(base, arr, tree);

    query(4, base, tree);

    cout << endl;
}