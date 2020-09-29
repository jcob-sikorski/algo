#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
//#include <numeric>
using namespace std;


int main() {
    // main eq
    string l = "1bad1"; string r = "acbe";

    // lenghts of letters in alphabet, given the alphabet order
    vector <int> len{4, 2, 4, 4, 2};
    // alphabet to assign name of var (letter) to its given length
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    unordered_map<int, int> lengths;
    for (int i = 0; i < len.size(); i++) {
        lengths[alphabet[i]] = len[i];
    }

    // count total/abstract length of one side of eq
    int sum = 0;
    for (int i = 0; i < l.size(); i++) {
        if (isalpha(l[i])) {
            sum += lengths[l[i]];
        }
        else {
            sum++;
        }
    }

    pair< vector<char>, vector<char> > eq;

    // malloc for to sides of vector
    eq.first.reserve((size_t) sum);
    eq.second.reserve((size_t) sum);

    for (auto x : l) {
        // if it's letter then make a node which each cell points to the given
        // cell in l and r string
        if (isalpha(x)) {
            for (int j = 0; j < lengths[x]; j++) {
                eq.first.push_back(x);
            }
        }
        else {
            eq.first.push_back('1');
        }
    }

    for (auto x : r) {
        // if it's letter then make a node which each cell points to the given
        // cell in l and r string
        if (isalpha(x)) {
            for (int j = 0; j < lengths[x]; j++) {
                eq.second.push_back(x);
            }
        }
        else {
            eq.second.push_back('1');
        }
    }

    // graph of correlations between vars and cells
    // with pointers to each cell in both sides of eq
    unordered_map< char, vector<int> > graph;

    // initializing graph
    for (auto x : l) {
        if (graph.find(x) == graph.end()) {
            graph[x] = vector<int>{};
        }
    }

    int index = 0;
    for (char x : l) {
        // if it's letter then make a node which each cell points to the given
        // cell in l and r string
        if (isalpha(x)) {
            for (int y : eq.first) {
                graph[x].push_back(y);
                index++;
            }
        }
        else {
            // if present in first side of equation and the element at the same position on the antagonal side is var, then
            // change the element at this position in this var
            int s = eq.second.size();

            // second DOES NOT EXIST!
            cout << eq.second.at(index) << endl;
            if ( !(graph.find(x) == graph.end()) && isalpha(eq.second.at(index))) {
                graph[eq.second.at(index)].push_back(x);
            }
            index++;
        }
    }

    for (char x : l) {
        for (char y : graph[x]) {
            cout << " " << y;
        }
        cout << endl;
    }

    cout << endl;
}