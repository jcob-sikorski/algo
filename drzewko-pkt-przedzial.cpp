#include <bits/stdc++.h>

using namespace std;

void update(int i, int val, int base, vector<int> &tree) {
    // init index as leave in tree
    i += base;

    // set leave to desired val
    tree[i] = val;

    // while index has parent
    while (i > 1) {
        // jump to parent
        i /= 2;

        // update value in leave
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}


int query(int x, int y, int base, int &suma, vector<int> &tree) {
    // init x and y as leaves in tree
    x = base + x-1;
    y = base + y+1;

    // while y and x don't have common parent
    while (y - x > 1) {

        // if x is par
        if (!(x & 1)) {
            suma += tree[x+1];
        }
        // if y is npar
        if (y & 1) { 
            suma += tree[y-1];
        }

        // jump to parent
        x /= 2;
        y /= 2;
    }
    return suma;
}


int main() {
    int n = 7;

    vector<int> arr = {4, -1, 3, -2, 6, 7, -4};

    int base = 1;

    // calculate base
    while (base < n) {
        base *= 2;
    }

    // init
    vector<int> tree; tree.resize(base*2, 0);

    for (int i = 0; i < arr.size(); i++) {
        int val = arr[i];
        update(i, val, base, tree);

        cout << "------------- " << i << endl;
        for (int j = 0; j < tree.size(); j++) {
            cout << " { " << j << " } " << tree[j];
        }
        cout << endl;
        cout << endl;
        cout << endl;
    }
    cout << endl;
}