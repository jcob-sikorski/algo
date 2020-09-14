#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int construct(vector<int> &input_vec, vector<int> &tree, int l, int r, int node_index=1) {
    if (l == r) {
        tree.at(node_index) = input_vec.at(l);
    } else {
        int mid = (l + r) / 2;
        tree.at(node_index) = min(construct(input_vec, tree, l, mid, node_index*2+1),
                            construct(input_vec, tree, mid+1, r, node_index*2+2));
    }
    return tree.at(node_index);
}

int RMQ (vector<int> tree, int l, int r, int curr_l, int curr_r, int node_index=1) {
    // If segment of this node is a part
    // of given range, then return
    // the min of the segment
    if (l <= curr_l && curr_r <= r)
        return tree[node_index];

    // L -------CURR_L-------CURR_R-------R
  
    // If segment of this node
    // is outside the given range
    if (curr_r < l || curr_l > r)
        return INT32_MAX;
  
    // If a part of this segment
    // overlaps with the given range
    int mid = (curr_l + curr_r) / 2;

    return min(RMQ(tree, l, r, curr_l, mid, 2*node_index+1),
                RMQ(tree, l, r, mid+1, curr_r, 2*node_index+2));
}


int main() {
    //vector<int> input_vec(100);
    vector<int> input_vec {5, 6, 2, 3, 1};

    //generate(input_vec.begin(), input_vec.end(), rand);

    vector<int> tree(input_vec.size()*4);

    construct(input_vec, tree, 0, input_vec.size()-1);


    for (int i = 0; i < input_vec.size(); i++) {
        
    }
    RMQ(tree, 3, 4, 0, input_vec.size()-1);

    cout << endl;
}