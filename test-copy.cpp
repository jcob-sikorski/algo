#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
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

    int n;
    cin >> n;

    //vector<int> bud;
    vector<int> bud {5, 6, 2, 3, 1};
    priority_queue<int> q;

    //int d, w;
//
    for (int i = 0; i < bud.size(); i++) {
        //cin >> d >> w;
        q.push(-bud.at(i));
    }

    //unordered_map<int, int> count;
//
    //for (int i : bud) {
    //    if (!(bud.find(i) == bud.end())) {
    //        count[bud]++;
    //    } else {
    //        bud[count] = 0;
    //    }
    //}

    //vector<int> input_vec(100);

    //generate(input_vec.begin(), input_vec.end(), rand);

    vector<int> tree(bud.size()*4);

    construct(bud, tree, 0, bud.size()-1);

    // rec func splitting vector if next set of min buildings is spaced by smaller building
    // and then setting l and r and performing RMQ on both or more sets:
    //  for set in bigger set {
    //      perform RMQ
    //  }

    for (int i = 0; i < bud.size(); i++) {
        RMQ(tree, 3, 4, 0, bud.size()-1);
    }
    cout << RMQ(tree, 3, 4, 0, bud.size()-1) << endl;

    cout << endl;
}
//int l = 0;
//int r = input_vec.size()-1;
//
//int count_billb(int l, int r, vector<int> &input_vec, vector<int> &tree, priority_queue<int> &q, int counter=0) {
//    if (l != r) {
//        // I have to find it by second value (index, element) to have access to its position
//        // to split by it in the next step
//        int split_index = RMQ(tree, l, r, 0, input_vec.size()-1);
//        counter++;
//        q.pop();
//
//        count_billb(l, split_index, input_vec, tree, q);
//        count_billb(split_index+1, r, input_vec, tree, q);
//    }
//    else {
//        return;
//    }
//}