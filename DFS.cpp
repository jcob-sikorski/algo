#include <list>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

void DFS(pair<char, int> cell, 
        unordered_map<pair<char, int>, vector<bool>, pair_hash> visited, 
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr)   {
    // Mark the current node as visited and 
    // print it
    visited[cell][cell.second] = true;
    cout << cell.first << " " << cell.second << endl; 

    for (p P : corr[cell]) {
        if (visited[P].size() > 0) 
            if (!visited[P][P.second]) {
                DFS(P, visited, corr);
        }
    }
}