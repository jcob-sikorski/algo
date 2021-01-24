#include <bits/stdc++.h>

using namespace std;

int lsb(int i) {
    // return value of least significant bit
    return i & -i;
}

// creates tree in constant n + n * log n time
vector<int> createTree(const vector<int> &arr) {
    // create 1 based tree
    vector<int> tree;
    tree.reserve(arr.size()+1);
    tree.push_back(0);

    // create differential array
    for (int i = 1; i < arr.size(); i++) {
        tree.push_back(arr[i] - arr[i-1]);
        cout << tree[i] << " ";
    } cout << endl;
    
    // for each value in arr set its appropriate sum
    for (int i = 1; i < tree.size(); i++) {
        // move to parent index
        int j = i + lsb(i);
        // if parent index isn't out of bounds of tree
        if (j < tree.size()) {
            // substract value of its child
            tree[j] += tree[i];
        }
    }

    return tree;
}

// lets you check value of 1 element in a tree in log n time
int query(int x, const vector<int> &tree) {
    int beforeeq = 0;


    while (x != 0) {
        beforeeq += tree[x];

        x -= lsb(x);
    }
    return beforeeq;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> tree = createTree(arr);

    for (int elem : tree) {
        cout << elem << " ";
    }
    cout << endl;

    for (int i = 1; i < tree.size(); i++) {
        cout << query(i, tree) << endl;
    }
    cout << endl;
}