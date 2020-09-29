#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
using namespace std;


int main() {
    // main equation
    string l = "1bad1"; string r = "acbe";

    // lenghts of letters in alphabet, given the alphabet order
    vector <int> len{4, 2, 4, 4, 2};
    // alphabet to assign name of var (letter) to its given length
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    unordered_map<int, int> lengths;
    for (int i = 0; i < len.size(); i++) {
        lengths[alphabet[i]] = len[i];
    }

    // holds dependencies of indexl and indexr which must be equal
    vector<vector<int>> matrix;


    // count total/abstract length of one side of equation
    int sum = 0;
    for (int i = 0; i < l.size(); i++) {
        if (isalpha(l[i])) {
            sum += lengths[l[i]];
        }
        else {
            sum++;
        }
    }

    for (int i = 0; i < sum; i++) {
        matrix.push_back(vector<int>(sum));
    }

    int rel = 0;
    int lindex = 0;

    for (auto x : l) {
        // if it's letter then make a node which each cell points to the given
        // cell in l and r string
        if (isalpha(x)) {
            for (int j = 0; j < lengths[x]; j++) {
                matrix[rel][rel] = 0;
                rel++;
            }
        }
        // if it's a number then skip it
        else {
            matrix[rel][rel] = l[lindex]-48;
            rel++;
        }
        lindex++;
    }
    rel = 0;
    int rindex = 0;
    for (auto x : r) {
        // if it's letter then make a node which each cell points to the given
        // cell in l and r string
        if (isalpha(x)) {
            for (int j = 0; j < lengths[x]; j++) {
                matrix[rel][rel] = 0;
                rel++;
            }
        }
        // if it's a number then skip it
        else {
            matrix[rel][rel] = r[rindex]-48;
            rel++;
        }
        lindex++;
    }


    

    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < sum; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}