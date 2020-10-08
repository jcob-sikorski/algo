#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

typedef std::pair<char, int> p;

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2> &p) const
	{
		return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
	}
};


int BFS(pair<char, int> cell, 
        unordered_map<pair<char, int>, bool, pair_hash> visited, 
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr)   {

    // Create a queue for BFS
    list<pair<char, int>> queue;
  
    // Mark the current node as visited and enqueue it
    visited[cell] = true;
    queue.push_back(cell);
  
    while(!queue.empty()) {
        // Dequeue a vertex from queue
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (pair<char, int> i : corr[cell]) {
            if (visited[i][i.second]) {
                visited[i][i.second] = true;
                queue.push_back(i);
            }
        }
    }
    return 0;
}

int main() {
    // main eq
    string l = "1bad1"; string r = "acbe";


    // lenghts of letters in alphabet, given the alphabet order
    vector<int> letter_len{4, 2, 4, 4, 2};
    // alphabet to assign name of var (letter) to its given length
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // each letter has assigned bounds
    unordered_map<char, int> varlen;
    for (int i = 0; i < letter_len.size(); i++) {
        varlen[alphabet[i]] = letter_len[i];
    }

    // both sides of equation populated 
    // with length of var letters
    string left; string right;


    // make abstract repr of left and right
    for (int i = 0; i < l.size(); i++) {
        if (isdigit(l.at(i))) {
            left.push_back(l.at(i));
        }
        // if it's letter add n letters by size of var char
        else {
            for (int j = 0; j < varlen[l.at(i)]; j++) {
                left.push_back(l.at(i));
            }
        }
    }

    // doing the same for right side
    for (int i = 0; i < r.size(); i++) {
        if (isdigit(r.at(i))) {
            right.push_back(r.at(i));
        }
        // if it's letter
        else {
            for (int j = 0; j < varlen[r.at(i)]; j++) {
                right.push_back(r.at(i));
            }
        }
    }


    if (left.size() != right.size()) {
        cout << 0 << endl;
    } 
    else {
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr;

        // initialize vectors by size
        //for (auto kv : varlen) {
        //    corr[kv.first] = vector<vector<pair<char, int>>>(kv.second);
        //}

        for (pair<char, int> kv: varlen) {
            for (int i = 0; i < kv.second; i++) {
                corr[make_pair(kv.first, i)] = vector<pair<char, int>>();
            }
        }
        // counter to keep track of length of letter
        int LvarLenCounter = 0; int RvarLenCounter = 0;

        //int s = left.size();

        // create correlation between same indexes on both sides
        for (int i = 0; i < left.size(); i++) {
            // if lcell is letter then bond it with rcell
            if (isalpha(left.at(i))) {
                pair<char, int> p;
                // if rcell is letter correlate them
                if (isalpha(right.at(i))) {
                    p = make_pair(right.at(i), RvarLenCounter);
                }
                // if rcell is number bond them
                //else {
                //    p = make_pair(right.at(i), -1);
                //}
                corr[make_pair(left.at(i), LvarLenCounter)].push_back(p);

                // moving in abstract boundaries of vars
                if (LvarLenCounter < varlen[left.at(i)]-1) {
                    LvarLenCounter++;
                }
                else {
                    LvarLenCounter = 0;
                }
            }

            // moving in abstract boundaries of vars
            if (isalpha(right.at(i)) && RvarLenCounter < varlen[right.at(i)]-1) {
                RvarLenCounter++;
            } 
            else {
                RvarLenCounter = 0;
            }
        }
        LvarLenCounter = 0; RvarLenCounter = 0;



        // for right side correlating by index
        for (int i = 0; i < right.size(); i++) {
            // if rcell is letter then bond it with lcell
            if (isalpha(right.at(i))) {
                pair<char, int> p;
                // if lcell is letter bond them
                if (isalpha(left.at(i))) {
                    p = make_pair(left.at(i), LvarLenCounter);
                }
                // if lcell is number bond them
                //else {
                //    p = make_pair(left.at(i), 0);
                //}
                corr[make_pair(right.at(i), RvarLenCounter)].push_back(p);

                //cout << "----------------" << endl;
                //cout << right.at(i) << "  " << corr[right.at(i)][RvarLenCounter].size() << endl;
                //cout << "loop" << endl;
                
                for (auto j : corr[make_pair(right.at(i), RvarLenCounter)]) {
                    cout << j.first << " " << j.second << endl;
                }
                cout << endl;
                // moving in abstract boundaries of vars
                if (RvarLenCounter < varlen[right.at(i)]-1) {
                    RvarLenCounter++;
                }
                else {
                    RvarLenCounter = 0;
                }
            }
            // moving in abstract boundaries of vars
            if (isalpha(left.at(i)) && LvarLenCounter < varlen[left.at(i)]-1) {
                LvarLenCounter++;
            } 
            else {
                LvarLenCounter = 0;
            }
        }
        unordered_map<pair<char, int>, bool, pair_hash> visited;

        for (pair<char, int> kv: varlen) {
            for (int i = 0; i < kv.second; i++) {
                visited[make_pair(kv.first, i)] = false;
            }
        }

        for (pair<char, int> kv: varlen) {
            for (int i = 0; i < kv.second; i++) {
                BFS(make_pair(kv.first, i), visited, corr);
            }
        }
    }
    return 0;
}