#include <iostream>
#include <vector>


using namespace std;

vector<int> primes(const int range) {
    vector<int> record(range+1);

    for (int i = 2; i <= range; i++) {
        for (int j = 2; i*j <= range; j++) {
            record[i*j] = 1;
        }
    }
    vector<int> primes;
    for (int i = 0; i < range; i++) {
        if (record[i] == 0) {
            primes.push_back(i);
        }
    }
    return primes;
}