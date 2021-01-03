#include <bits/stdc++.h>

using namespace std;


int lsb(int i) {
    // return value of least significant bit
    return i & -i;
}


vector<int> createTree(vector<int> arr) {
    // create 1 based tree
    vector<int> tree{0};
    tree.insert(tree.end(), arr.begin(), arr.end());
    
    // for each value in arr set its appropriate sum
    for (int i = 1; i <= tree.size(); i++) {
        // move to parent index
        int j = i + lsb(i);
        // if parent index isn't out of bounds of tree
        if (j <= tree.size()) {
            // add value of its child
            tree[j] += tree[i];
        }
    }

    return tree;
}


// void update(int val, int index, vector<int> &tree) {
//     tree[index] += val;

//     while (index < tree.size()) {
//         index += lsb(index);

//         tree[index] += val;
//     }
// }

int rangeSum(int a, int b, vector<int> &tree) {
    if (a > b) {
        swap(a, b);
    }

    int beforeeqA = 0;

    int toB = 0;
    a += 1;
    while (a != 0) {
        beforeeqA += tree[a];

        a -= lsb(a);
    }

    while (b != 0) {
        toB += tree[b];

        b -= lsb(b);
    }
    return toB - beforeeqA;
}

int main() {
    vector<int> arr = {5, 4, 2, 1, 6, 3};

    vector<int> tree = createTree(arr);

    for (int elem : tree) {
        cout << elem << " ";
    }
    cout << endl;

    cout << rangeSum(3, 6, tree) << endl;
    cout << endl;
}