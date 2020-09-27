#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void r_trav(long long int k, long long int ref_point, vector<long long int> &vec, unordered_map<long long int, pair<long long int, pair<long long int, long long int>>> &city, long long int n, long long int rth) {
    long long int sum_r = 0;
    long long int sum = 0;
    // this loop makes sure that pointer r from ref_point
    // is kept in range of graph
    while (rth != ref_point && sum < k) {
        // current sum of distances from ref_point to pointer r
        sum_r += city[rth].second.first;

        // current sum of distances from ref_point to pointer r
        
        // calculate optimal cost for transport from fixed place
        // for each city from right
        vec[rth-1] = city[rth].first*sum_r;
        sum += vec[rth-1];

        rth++;
        rth = rth == n+1 ? 1 : rth;
    }
}

long long int l_trav(long long int k, long long int ref_point, vector<long long int> &vec, unordered_map<long long int, pair<long long int, pair<long long int, long long int>>> &city, long long int n, long long int lth) {
    long long int sum_l = 0;
    long long int sum = 0;

    // this loop makes sure that pointer r from ref_point
    // is kept in range of graph
    while (lth != ref_point && sum < k) {
        // current sum of distances from ref_point to pointer r
        sum_l += city[lth].second.second;
        
        // calculate optimal cost for transport from fixed place
        // for each city from right
        sum += min(vec[lth-1], city[lth].first*sum_l);
        
        lth = lth == 1 ? n+1 : lth;
        lth--;
    }
    return min(k, sum);
}

int main() {
    long long int n;
    cin >> n;

    // city with two distances to the adjacent cities
    unordered_map<long long int, pair<long long int, pair<long long int, long long int>>> city;

    long long int z1, d1;
    cin >> z1 >> d1;

    city[1] = make_pair(z1, make_pair(0, d1));

    for (long long int i = 2; i <= n; i++) {
        long long int z, d;
        cin >> z >> d;

        city[i] = make_pair(z, make_pair(city[i-1].second.second, d));
    }

    city[1] = make_pair(z1, make_pair(city[n].second.second, d1));

    long long int k = INT64_MAX;

    // start from first city going from left to right
    // and gradually save price for each city
    // if approched twice the city compare two prices and add lower to total_koszt

    long long int counter = 1;

    // this loop moves ref_point counter
    while (counter <= n) {
        // pointers from ref_points
        long long int rth, lth;
        rth = counter + 1 == n+1 ? 1 : counter+1;
        lth = counter - 1 == 0 ? n : counter-1;

        vector<long long int> vec(n, INT64_MAX);

        r_trav(k, counter, vec, city, n, rth);
        k = l_trav(k, counter, vec, city, n, lth);

        counter++;
    }

    cout << k << endl;
}