#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <bitset>

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
    vector<bitset<1>> matrix;



    // YOU HAVE TO COUNT PLACES IN ONE STRING NOT WHOLE LENGTH OF EACH VAR IN BOTH STRINGS







    int sum = accumulate(len.begin(), len.end(), 0);

    for (int i = 0; i < sum; i++) {
        matrix.push_back(bitset<1>(sum));
    }

    int rel = 0;
    int lindex = 0;
    //for (int i = 0; i < l.size(); i++) {
    for (auto x : l) {
        // if it is letter then make a node which each cell points to the given
        // cell in l and r string
        if (isalpha(x)) {
            for (int j = 0; j < lengths[x]; j++) {
                matrix[rel][rel] = 0;
                rel++;
            }
        }
        else {
            matrix[rel][rel] = l[lindex];
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