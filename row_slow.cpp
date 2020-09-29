#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // main eq
    string left = "1bad1"; string right = "acbe";

    // lenghts of letters in alphabet, given the alphabet order
    vector <int> len{4, 2, 4, 4, 2};
    // alphabet to assign name of var (letter) to its given length
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    unordered_map<char, int> varLen;
    for (int i = 0; i < len.size(); i++) {
        varLen[alpha[i]] = len[i];
    }

    string l; string r;
    // make abstract repr of left and right
    for (int i = 0; i < left.size(); i++) {
        if (isdigit(left.at(i))) {
            l.push_back(left.at(i));
        }
        // if it's letter add n letters by size of var char
        else {
            for (int j = 0; j < varLen[left.at(i)]; j++) {
                l.push_back(left.at(i));
            }
        }
    }

    // doing the same for right side
    for (int i = 0; i < right.size(); i++) {
        if (isdigit(right.at(i))) {
            r.push_back(right.at(i));
        }
        // if it's letter
        else {
            for (int j = 0; j < varLen[right.at(i)]; j++) {
                r.push_back(right.at(i));
            }
        }
    }

    // printing both sides
    for(auto x : l) {cout << " " << x;}
    cout << "  =  ";
    for(auto x : r) {cout << " " << x;}
    cout << endl;


    unordered_map<char, vector<vector<pair<char, int>>> > corr;

    // initialize vectors by size
    for (auto kv : varLen) {
        corr[kv.first] = vector<vector<pair<char, int>>>(kv.second);
    }

    int LvarLenCounter = 0; int RvarLenCounter = 0;

    // create correlation between same indexes on both sides
    // for left side correlating by index
    for (int i = 0; i < l.size(); i++) {

        // if lcell is letter bond lcell with rcell
        if (isalpha(l.at(i))) {
            // if rcell is letter bond them
            if (isalpha(r.at(i))) {
                corr[l.at(i)][LvarLenCounter].push_back(make_pair(r.at(i), RvarLenCounter));
            }
            // if rcell is number bond them
            else {
                corr[l.at(i)][LvarLenCounter].push_back(make_pair(r.at(i), -1));
            }
            
            // moving in abstract boundaries of vars
            if (LvarLenCounter < varLen[l.at(i)]-1) {
                LvarLenCounter++;
            }
            else {
                LvarLenCounter = 0;
            }
        }

        // moving in abstract boundaries of vars
        if (isalpha(r.at(i)) && RvarLenCounter < varLen[r.at(i)]-1) {
            RvarLenCounter++;
        } 
        else {
            RvarLenCounter = 0;
        }
    }

    LvarLenCounter = 0; RvarLenCounter = 0;

    // for right side correlating by index
    for (int i = 0; i < r.size(); i++) {

        // if lcell is letter bond lcell with rcell
        if (isalpha(r.at(i))) {
            // if rcell is letter bond them
            if (isalpha(l.at(i))) {
                corr[r.at(i)][RvarLenCounter].push_back(make_pair(l.at(i), LvarLenCounter));
            }
            // if rcell is number bond them
            else {
                corr[r.at(i)][RvarLenCounter].push_back(make_pair(l.at(i), -1));
            }

            // moving in abstract boundaries of vars
            if (RvarLenCounter < varLen[r.at(i)]-1) {
                RvarLenCounter++;
            }
            else {
                RvarLenCounter = 0;
            }
        }
        // moving in abstract boundaries of vars
        if (isalpha(l.at(i)) && LvarLenCounter < varLen[l.at(i)]-1) {
            LvarLenCounter++;
        } 
        else {
            LvarLenCounter = 0;
        }
    }
    cout << endl;
}