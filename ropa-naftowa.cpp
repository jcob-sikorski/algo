#include <bits/stdc++.h>

using namespace std;

bool comparePairs(const pair<long double, long double> &l, const pair<long double, long double> &r)
{
    return l.first/l.second > r.first/r.second;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    long double w;
    cin >> w;

    vector<pair<long double, long double>> cv;

    long double a, b;
    for (int i = 0; i < n; i++) 
    {
        cin >> a >> b;
        cv.push_back(make_pair(a, b));
    }
    sort(cv.begin(), cv.end(), comparePairs);

    long double x = 0, total = 0;
    for (int i = 0; i < n; i++) 
    {
        long double mid, lo = 0, hi = cv[i].second;

        for (int j = 0; j < 60; j++) 
        {
            mid = lo + (hi-lo)/2;

            if (x + mid <= w) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        x += mid;
        total += (cv[i].first/cv[i].second)*mid;
    }

    cout << fixed << showpoint;
    cout << setprecision(4);

    cout << total << endl;


    return 0;
}