#include <bits/stdc++.h>

using namespace std;

int query(int i, int base, vector<int> &tree) {
    // init index as leave in tree
    i += base - 1;

    // set leave to desired val
    int var = 0;

    // while index has parent
    while (i > 0) {
        // add subvalue
        var += tree[i];

        // jump to parent
        i /= 2;
        // index -= index & (-index); 
    }
    return var;
}


void update(int x, int y, int val, int base, vector<int> &tree) {
    // init x and y as leaves in tree
    x += base - 1;

    y += base - 1;
    // y = base + y+1;

    tree[x] += val;

    if (x != y) {
        tree[y] += val;
    }

    // while y and x don't have common parent
    while (y - x > 1) {

        // if x is par
        if (!(x & 1)) {
            tree[x+1] += val;
        }
        // if y is npar
        if (y & 1) { 
            tree[y-1] += val;
        }

        // jump to parent
        x /= 2;
        y /= 2;
    }
}


int main() {
    int n = 7;

    // vector<int> arr = {4, -1, 3, -2, 6, 7, -4};

    int base = 1;

    // calculate base
    while (base < n) {
        base *= 2;
    }

    // init
    vector<int> tree; tree.resize(base*2, 0);


    for (int i = 1; i <= n; i++) {

        update(i, i+1, 1, base, tree);

        for (int j = 0; j < tree.size(); j++) {
            cout << " {" << j << "} >> " << tree[j] << "  ";
        }
        cout << endl;
    }


    for (int i = 1; i <= n; i++) {
        cout << query(i, base, tree) << endl;
    }

    cout << endl;
}