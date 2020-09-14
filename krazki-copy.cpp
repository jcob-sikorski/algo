#include <iostream>
#include <vector>
#include <unordered_map>

#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> sr;
    unordered_map<int, int> min_to_i;

    vector<int> k;

    int most_min = INT32_MAX;

    // for two lines
	for(int i = 0; i < 3; ++i) {
        string str;

		if(getline(cin, str)) {
			istringstream sstr(str);
			int x;

			// if first line
			if (i == 0) {
				sstr >> n >> m;
			}
			else if (i == 1) {
                int c = 0;
				while(sstr >> x) {
                    sr.push_back(x);

                    // compare to see if at this level is narrower
                    most_min = min(most_min, x);
                    min_to_i[c] = most_min;
                    c++;
				}
			}
            else {
                while(sstr >> x)
				{
                    k.push_back(x);
				}
            }
  		}
	}

    int last_h = n;
    for (int i = 0; i < m; i++) {
        int c = 0;
        while (k[i] <= sr[c] && c < last_h-1) {
            c++;
        }
        last_h = c;
        //cout << last_h << endl;
    }
    cout << last_h << endl;
    //int r;
    //int most_min = INT32_MAX;
    //for (int i = 0; i < n; i++) {
    //    cin >> r;
    //    sr.push_back(r);
//
    //    // compare to see if at this level is narrower
    //    most_min = min(most_min, r);
    //    min_to_i[i] = most_min;
//
    //    cout << i << "  " << min_to_i[i] << endl;
    //}



    //cout << endl;
}