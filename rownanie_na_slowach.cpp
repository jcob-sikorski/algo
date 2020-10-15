#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <utility>
#include <set>

using namespace std;

typedef std::pair<char, int> p;

//struct pair_hash { 
//    static_assert(sizeof(size_t)==8); 
//
//    std::size_t operator() (const std::pair<int8_t, int32_t> &p) const { 
//
//    return static_cast<uint64_t>(p.first) << (4*8) | static_cast<uint64_t>(p.second); 
//    } 
//};


struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2> &p) const
	{
		return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
	}
};


void BFS(pair<char, int> cell, set<int> visited, 
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr,
        unordered_map<pair<char, int>, bool, pair_hash> is_number)   {
        //unordered_map<pair<char, int>, int, pair_hash> visited, 
        //unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr,
        //unordered_map<pair<char, int>, bool, pair_hash> is_number)   {
    //cout << visited[make_pair('c', 1)] << endl;
    int x = (cell.first - '0')*1000000 + cell.second;
    if (visited.find(x) != visited.end()) {

        // Create a queue for BFS
        list<pair<char, int>> queue;
    
        // Mark the current node as visited and enqueue it
        //visited[cell][cell.second] = true;
        visited.insert(x);
        cout << " visited: " << cell.first << " " << cell.second << endl;
        queue.push_back(cell);
    
        while(!queue.empty()) {
            // Dequeue a vertex from queue
            cell = queue.front();
            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (p P : corr[cell]) {
                int y = (P.first - '0')*1000000 + P.second;
                //if (visited[P].size() > 0) {
                //cout << visited('c' - '0')*1000000 + 1] << endl;
                if (visited.find(y) != visited.end()) {
                    //if (!visited[P][P.second]) {
                    //visited[P][P.second] = true;
                    visited.insert(y);
                    cout << "visited: " << P.first << " " << P.second << endl;
                    queue.push_back(P);
                }
                //}
            }
        }
    }
}


void DFS(pair<char, int> cell, 
        unordered_map<pair<char, int>, vector<bool>, pair_hash> visited, 
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr,
        unordered_map<pair<char, int>, bool, pair_hash> is_number)   {

    if (visited[cell].size() > 0) {
        // Mark the current node as visited and 
        // print it
        visited[cell][cell.second] = true;
        cout << cell.first << " " << cell.second << endl; 

        for (p P : corr[cell]) {
            if (visited[P].size() > 0) {
                cout << P.first << " " << P.second << " visited: " << visited[P][P.second] << endl;
                if (!visited[P][P.second]) {
                    DFS(P, visited, corr, is_number);
                }
            }
        }
    }
}

int main() {
    // main eq
    //string l = "1bad1"; string r = "acbe";
    string l = "1ab0"; string r = "bc";

    // lenghts of letters in alphabet, given the alphabet order
    //vector<int> letter_len{4, 2, 4, 4, 2};
    vector<int> letter_len{2, 3, 4};

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
    for (auto s: left) {
        cout << s;
    }
    //cout << "   =   ";
    cout << endl;

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
    for (auto s: right) {
        cout << s;
    }
    cout << endl;

    if (left.size() != right.size()) {
        cout << 0 << endl;
    } 
    else {
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr;
        unordered_map<pair<char, int>, bool, pair_hash> is_number;

        for (pair<char, int> kv: varlen) {
            for (int i = 0; i < kv.second; i++) {
                corr[make_pair(kv.first, i)] = vector<pair<char, int>>();
            }
        }
        // counter to keep track of length of letter
        int LvarLenCounter = 0; int RvarLenCounter = 0;

        // create correlation between same indexes on both sides
        for (int i = 0; i < left.size(); i++) {
            // if lcell is letter then bond it with rcell
            if (isalpha(left.at(i))) {

                // if rcell is letter correlate them
                if (isalpha(right.at(i))) {
                    pair<char, int> p;
                    p = make_pair(right.at(i), RvarLenCounter);
                    corr[make_pair(left.at(i), LvarLenCounter)].push_back(p);
                }
                //else {
                //    is_number[make_pair(left.at(i), LvarLenCounter)] = true;
                //}

                // moving in abstract boundaries of vars
                if (LvarLenCounter < varlen[left.at(i)]-1) {
                    LvarLenCounter++;
                }
                else {
                    LvarLenCounter = 0;
                }
            }
            //else {
            //    is_number[make_pair(left.at(i), LvarLenCounter)] = true;
            //}


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
                
                // if lcell is letter bond them
                if (isalpha(left.at(i))) {
                    pair<char, int> p;
                    p = make_pair(left.at(i), LvarLenCounter);
                    corr[make_pair(right.at(i), RvarLenCounter)].push_back(p);
                }
                //else {
                //    is_number[make_pair(right.at(i), RvarLenCounter)] = true;
                //}


                // moving in abstract boundaries of vars
                if (RvarLenCounter < varlen[right.at(i)]-1) {
                    RvarLenCounter++;
                }
                //else {
                //    RvarLenCounter = 0;
                //}
            }
            //else {
            //    is_number[make_pair(right.at(i), RvarLenCounter)] = true;
            //}


            // moving in abstract boundaries of vars
            if (isalpha(left.at(i)) && LvarLenCounter < varlen[left.at(i)]-1) {
                LvarLenCounter++;
            } 
            else {
                LvarLenCounter = 0;
            }
        }
        //unordered_map<pair<char, int>, vector<bool>, pair_hash> visited;
        set<int> visited;
        //unordered_map<int, int> visited;
        for (auto kv: corr) {
            int x = (kv.first.first - '0')*1000000 + kv.first.second;
            //kv.second.size()
            //visited[kv.first] = vector<bool>();
            //for (int i = 0; i < kv.second.size(); i++) {
                //visited[kv.first].push_back(false);
            //visited[x] = 0;
            visited.insert(x);
            //}
        }
        // graph traversal and elimination of 'no choice' cells
        for (auto kv: corr) {
            BFS(kv.first, visited, corr, is_number);
        }
    }
    return 0;
}