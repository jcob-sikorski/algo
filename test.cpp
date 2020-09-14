#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

pair<int, int> construct(vector<int> &input_vec, vector<pair<int, int>> &tree, int l, int r, int node_index=1) {
    if (l == r) {
        tree.at(node_index) = make_pair(l, input_vec.at(l));
    } else {
        int mid = (l + r) / 2;

        pair<int, int> x = construct(input_vec, tree, l, mid, node_index*2+1);
        pair<int, int> y = construct(input_vec, tree, mid+1, r, node_index*2+2);

        tree.at(node_index) = x.second >= y.second ? y : x;
    }
    return tree.at(node_index);
}

pair<int, int> RMQ (vector<pair<int, int>> &tree, int l, int r, int curr_l, int curr_r, int node_index=1) {
    // If segment of this node is a part
    // of given range, then return
    // the min of the segment
    if (l <= curr_l && curr_r <= r)
        return tree[node_index];

    // L -------CURR_L-------CURR_R-------R
  
    // If segment of this node
    // is outside the given range
    if (curr_r < l || curr_l > r)
        return make_pair(INT32_MAX, INT32_MAX);
  
    // If a part of this segment
    // overlaps with the given range
    int mid = (curr_l + curr_r) / 2;


    pair<int, int> x = RMQ(tree, l, r, curr_l, mid, 2*node_index+1);
    pair<int, int> y = RMQ(tree, l, r, mid+1, curr_r, 2*node_index+2);

    return x.second >= y.second ? y : x;
}


//int count_billb(int l, int r, vector<int> &input_vec, vector<int> &tree, priority_queue<int> &q, int counter=0) {
void count_billb(int l, int r, vector<int> &input_vec, vector<pair<int, int>> &tree, int counter=0) {
    if (l != r) {
        // I have to find it by second value (index, element) to have access to its position
        // to split by it in the next step
        int split_index = RMQ(tree, l, r, 0, input_vec.size()-1).first;
        if (l < split_index && split_index < r) {
            counter++;
            //q.pop();

            //count_billb(l, split_index, input_vec, tree, q);
            //count_billb(split_index+1, r, input_vec, tree, q);

            count_billb(l, split_index, input_vec, tree);
            count_billb(split_index+1, r, input_vec, tree);

        }
    }
}


int main() {

    //int n;
    //cin >> n;

    vector<int> input_vec(10);
    generate(input_vec.begin(), input_vec.end(), rand);


    //int d, w;

    //for (int i = 0; i < n; i++) {
    //    cin >> d >> w;
    //    input_vec.push_back(w);
    //    q.push(-w);
    //}

    //vector<int> input_vec {5, 6, 2, 3, 1};

    vector<pair<int, int>> tree(input_vec.size()*4);

    construct(input_vec, tree, 0, input_vec.size()-1);

    for (int i = 0; i < tree.size(); i++) {
        if (tree.at(i).second != 0) {
            cout << i << "  " << tree.at(i).second << endl;
        }
    }
    cout << endl;

    // rec func splitting vector if next set of min buildings is spaced by smaller building
    // and then setting l and r and performing RMQ on both or more sets:
    //  for set in bigger set {
    //      perform RMQ
    //  }

    //for (int i = 0; i < input_vec.size(); i++) {
    //    RMQ(tree, 3, 4, 0, input_vec.size()-1)
    //}
    //cout << RMQ(tree, 3, 4, 0, input_vec.size()-1) << endl;

    int l = 0; int r = input_vec.size()-1;

    count_billb(l, r, input_vec, tree);

    cout << endl;
}