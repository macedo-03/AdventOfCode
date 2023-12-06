#include <bits/stdc++.h>
using namespace std;

//NOT FINISHED
int main(){

    freopen("input.txt", "r", stdin);
    vector<long long> seeds;
    vector<bool>converted;
    vector<long long> discontinuities;

    discontinuities.push_back(0);
    discontinuities.push_back(LLONG_MAX);


    string s;
    getline(cin, s);

    stringstream ss(s);
    string token;
    while (getline(ss, token, ' ')) {
        if (isdigit(token[0])){
            long long start, range;
            start = stoll(token);
            getline(ss, token, ' ');
            range = stoll(token);

            for (long long i = start; i < start+range; i++) {
                seeds.push_back(i);
            }
        }
    }

    while (getline(cin, s))
    {
        converted.clear();
        converted.resize(seeds.size(), false);
        while (getline(cin, s) && s != "") {
            if (!isdigit(s[0])) continue;

            stringstream ss(s);
            long long end, start, range;
            ss >> end >> start >> range;

            if (find(discontinuities.begin(), discontinuities.end(), start) == discontinuities.end()) {
                discontinuities.push_back(start);
            }

            if (start-1 >=0 && find(discontinuities.begin(), discontinuities.end(), start-1) == discontinuities.end()) {
                discontinuities.push_back(start-1);
            }

            if (find(discontinuities.begin(), discontinuities.end(), start+range) == discontinuities.end()) {
                discontinuities.push_back(start+range);
            }

            if (find(discontinuities.begin(), discontinuities.end(), start+range-1) == discontinuities.end()) {
                discontinuities.push_back(start+range-1);
            }

            sort(discontinuities.begin(), discontinuities.end());
        }
    }

    cout << "DISCONTINUITIES: \n";
    for (auto i : discontinuities) {
        cout << i << "\n";
    }

    //cout << "MIN_DIS: " << *min_element(seeds.begin(), seeds.end()) << "\n";
    

    return 0;
}