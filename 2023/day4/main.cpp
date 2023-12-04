#include <bits/stdc++.h>

using namespace std;

vector<int> keyss;

int main()
{
    long long total_points = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> cards(200, 0);
    string line, temp;

    while (getline(cin, line))
    {
        stringstream ss(line);
        int card_id, points = 0;

        ss >> temp >> card_id >> temp;
        vector<int> keys(100, 0);

        cards[card_id] == 0 ? cards[card_id] = 1 : cards[card_id]++;

        while (ss >> temp && temp != "|")
        {
            //cout << "Keys:" << temp << endl;
            keys[stoi(temp)] = 1;
        }

        while (ss >> temp)
        {
            if (keys[stoi(temp)] == 1)
            {
                //cout << "Values:" << temp << endl;
                points++;
                //cout << "Point: " << points << endl;
            }
        }
        for (int i = 1; i <= points; i++)
        {
            cards[card_id+i] += 1 * cards[card_id];
        }
        //cout << "Points: " << points << endl;
        points *= cards[card_id];
        total_points += points;
    }
    cout << "-->Points" << ": " << total_points << endl;
/*
    for (int i = 1; i < cards.size(); i++)
    {
        if (cards[i] != 0)
        {
            cout << "Card " << i << ": " << cards[i] << endl;
        }
    }
*/
    cout << "Total cards: " << accumulate(cards.begin(), cards.end(), 0) << endl;
   
    return 0;
}