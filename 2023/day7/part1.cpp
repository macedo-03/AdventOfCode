#include <bits/stdc++.h>

using namespace std;

map<char, int> priority;

int main(){

    priority['2'] = 1;
    priority['3'] = 2;
    priority['4'] = 3;
    priority['5'] = 4;
    priority['6'] = 5;
    priority['7'] = 6;
    priority['8'] = 7;
    priority['9'] = 8;
    priority['T'] = 9;
    priority['J'] = 10;
    priority['Q'] = 11;
    priority['K'] = 12;
    priority['A'] = 13;
    
    freopen("input.txt", "r", stdin);

    vector<vector<string>> hands;

    string hand, bet;
    
    while(cin >> hand >> bet){
        vector<string> temp;
        temp.push_back(hand);
        temp.push_back(bet);

        string rank = "0";
        map<char, int> check;
        for(auto c : hand){
            if(check.find(c) == check.end()){
                check[c] = 1;
            }else{
                check[c]++;
                if (check[c] == 2){
                    if (rank == "0") rank = "1";
                    else if (rank == "1") rank = "2";
                    else if (rank == "3") rank = "4";
                }
                else if (check[c] == 3) {
                    if (rank == "1") rank = "3";
                    else if (rank == "2") rank = "4";
                }
                else if (check[c] == 4) rank = "5";
                else if (check[c] == 5) rank = "6";
            }
        }

        temp.push_back(rank);
        hands.push_back(temp);
    }

    sort(hands.begin(), hands.end(), [](vector<string> a, vector<string> b){
        if (a[2] == b[2]) {
            int i  = 0;
            while (i < a[0].size()){
                if (a[0][i] != b[0][i]) return priority[a[0][i]] < priority[b[0][i]];
                i++;
            }
        };
        return a[2] < b[2];
    });

    long long total = 0;
    int j = 1;
    for (auto v : hands){
        cout << "Hand: " << v[0] << " - Bet: " << v[1] << " - rank: " << v[2] << endl;
        total += j*stoi(v[1]);
        j++;
    }

    cout << "total: " << total << endl;

    return 0;
}