#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m;

    int limit = 0;
    int num;

    vector<int> r;
    vector<int> k;

    // for two lines
	for(int i = 0; i < 3; ++i) {
        string str;

		if(getline(cin, str)) {
			istringstream sstr(str);
			int x;

			// if first line
			if (i == 0) {
				sstr >> n >> m;
				//n = x;
			}
			else if (i == 1) {
				while(sstr >> x) {
					r.push_back(x);
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

    int curr = 0;
    int h = n;

    while (curr < m) {
        for (int i = 0; i < h; i++) {
            if (k[curr] > r[i]) {
                h = i;
            }
        }
        curr++;
    }
    if (h == n) {
        cout << 0 << endl;
    }
    else {
        cout << h << endl;
    }
}