#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum RoundType {
    STRIKE,
    SPARE,
    NORMAL
};

// Function to parse plays into rounds and determine round type
vector<tuple<int, RoundType, int>> parseRounds() {
    vector<tuple<int, RoundType, int>> rounds;
    int pins;

    while (cin >> pins) {
        if (pins == 10) {
            rounds.push_back(make_tuple(10, STRIKE, 10));
        } else {
            int secondRoll = 0;
            cin >> secondRoll;
            
            if (pins + secondRoll == 10) {
                rounds.push_back(make_tuple(pins + secondRoll, SPARE, pins));
            } else {
                rounds.push_back(make_tuple(pins + secondRoll, NORMAL, pins));
            }
        }
    }

    return rounds;
}

int main() {
    vector<tuple<int, RoundType, int>> rounds = parseRounds();

    for (const auto& round : rounds) {
        cout << get<0>(round) << " ";

        switch (get<1>(round)) {
            case STRIKE:
                cout << "STRIKE";
                break;
            case SPARE:
                cout << "SPARE";
                break;
            default:
                cout << "NORMAL";
                break;
        }
        
        cout << " " << get<2>(round);

        cout << endl;
    }

    return 0;
}
