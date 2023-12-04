#include <bits/stdc++.h>

using namespace std;
 
vector<vector<string>> numbers{{"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

string replace(string s){
    while (true){
        vector<int> pos = {int(s.find("one")), int(s.find("two")), int(s.find("three")), int(s.find("four")), int(s.find("five")), int(s.find("six")), int(s.find("seven")), int(s.find("eight")), int(s.find("nine"))};
        
        auto it = min_element(pos.begin(), pos.end(), [](const auto& lhs, const auto& rhs){ return (lhs == rhs == -1) ? lhs < rhs : ((lhs == -1 || rhs == - 1) ? -lhs < -rhs : lhs < rhs);});
        
        int index = it - pos.begin();

        if (*it == -1){
            return s;
        }

        s.replace(*it, numbers[index][0].size(), numbers[index][1]+numbers[index][0][size(numbers[index][0])-1]);
    }
    
    return s;
    
}

int main() {
    freopen("input.txt", "r", stdin);

    bool is_first = true;
    int sum = 0;
    string s;

    while (cin >> s) {
        s = replace(s);

        cout << s << endl;
        is_first = true;
        int first = 0, second = 0;
        for (auto c : s){
            if (isdigit(c)){
                if (is_first){
                    first = c - '0';
                    is_first = false;
                }
                second = c - '0';
                continue;
            }
        }
        sum += first*10 + second;
        //cout << first << " " << second << endl;

    }
    cout << "sum: " << sum << endl;
   return 0;
}