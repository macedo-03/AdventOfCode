#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt", "r", stdin);
    vector<long long> seeds;
    vector<bool>converted;

    string s;
    getline(cin, s);

    stringstream ss(s);
    string token;
    while (getline(ss, token, ' ')) {
        if (isdigit(token[0]))seeds.push_back(stoll(token));
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

            for (int i = 0; i < seeds.size(); i++) {
                if (seeds[i] >= start && seeds[i] < start+range) {
                    if (!converted[i]) {
                        seeds[i] = end + (seeds[i] - start);
                        converted[i] = true;
                        }
                }
            }
            
    }
    }
    for (int i = 0; i < seeds.size(); i++) {
        cout << i << ": " << seeds[i] << "\n";
    }

    cout << "MIN_DIS: " << *min_element(seeds.begin(), seeds.end()) << "\n";
    

    return 0;
}