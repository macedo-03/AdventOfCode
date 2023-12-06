#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    string s;
    long long time, distance, winning_scenario = 0;
    
    getline(cin, s);
    stringstream ss(s);

    getline(ss, s, ':');
    getline(ss, s, ':');
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    time = stoll(s);

    getline(cin, s);
    ss = stringstream(s);

    getline(ss, s, ':');
    getline(ss, s, ':');
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    distance = stoll(s);
   
    cout << "Time: " << time << endl;
    cout << "Distance: " << distance << endl;
    //calculate number of winning scenarios
    for(int j = time/2; j>0; j--){
        if ((j * (time-j)) <= distance) break;
        winning_scenario += 2;
    }
    if (time % 2 == 0) winning_scenario--;  
 
    //print aswer value
    cout << winning_scenario << endl;
    return 0;
}