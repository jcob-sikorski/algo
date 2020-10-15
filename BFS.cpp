#include <list>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int BFS(pair<char, int> cell, 
        unordered_map<pair<char, int>, vector<bool>, pair_hash> visited, 
        unordered_map<pair<char, int>, vector<pair<char, int>>, pair_hash> corr)   {
    
    if (visited[cell].size() > 0) {

        // Create a queue for BFS
        list<pair<char, int>> queue;
    
        // Mark the current node as visited and enqueue it
        visited[cell][cell.second] = true;
        queue.push_back(cell);
    
        while(!queue.empty()) {
            // Dequeue a vertex from queue
            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (p P : corr[cell]) {
                if (visited[P].size() > 0) {

                    if (!visited[P][P.second]) {
                        visited[P][P.second] = true;
                        queue.push_back(P);
                    }

                }
            }
        }
    }
    return 0;
}