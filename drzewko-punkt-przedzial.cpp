#include <bits/stdc++.h>

using namespace std;

// update pojedynczej komórki
void update(int index, int val, int base, vector<int> &tree) {
    index += base;
    tree[index] = val;
    index >>= 1;

    while (index) {
        // DEBUG
        int sum  = tree[index*2] + tree[index*2+1];
        tree[index] = sum;
        index >>= 1;
    }
}

// zapytanie o przedział x-y
int query(int x, int y, int base, const vector<int> &tree) {
    int res = 0;

    x += base-1;
    y += base+1;

    while (y-x > 1) {
        if (!(x&1)) {
            res += tree[x+1];
        }

        if (y&1) {
            res += tree[y-1];
        }

        x >>= 1; y >>= 1;
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

    query(-1, 5, base, tree);

    update(2, -3, base, tree);

    display(base, arr, tree);

    query(0, 4, base, tree);

    cout << endl;
}