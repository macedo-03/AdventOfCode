#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    string s;
    vector<long long> time, distance, winning_scenario;
    
    getline(cin, s);
    stringstream ss(s);

    while (ss >> s){
        if (!isdigit(s[0])) continue;
        time.push_back(stoll(s));
    }

    getline(cin, s);
    ss = stringstream(s);
    while (ss >> s){
        if (!isdigit(s[0])) continue;
        distance.push_back(stoll(s));
    }

    winning_scenario.resize(time.size(), 0);

    //calculate number of winning scenarios
    for (int i = 0; i < time.size(); i++){
        for(int j = time[i]/2; j>0; j--){
            if ((j * (time[i]-j)) <= distance[i]) break;
            winning_scenario[i] += 2;
        }
        if (time[i] % 2 == 0) winning_scenario[i]--;  
    }
 
    //print aswer values
    long long value = 1;
    for (int i = 0; i < time.size(); i++){
        cout << winning_scenario[i] << endl;
        value *= winning_scenario[i];
    }
    cout << "Value: " << value << endl;
    return 0;
}