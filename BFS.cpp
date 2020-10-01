#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

int BFS(pair<char, int> cell, unordered_map<char, vector<char> > visited, unordered_map<char, vector<vector<pair<char, int>>> > corr) {

    // Create a queue for BFS
    list<pair<char, int>> queue;
  
    // Mark the current node as visited and enqueue it
    visited[cell.first][cell.second] = '1';
    queue.push_back(cell);
  
    while(!queue.empty()) {
        // Dequeue a vertex from queue
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (pair<char, int> i : corr[cell.first][cell.second]) {
            if (visited[i.first][i.second] == '0') {
                visited[i.first][i.second] = '1';
                queue.push_back(i);
            }
        }
    }
    return 0;
}