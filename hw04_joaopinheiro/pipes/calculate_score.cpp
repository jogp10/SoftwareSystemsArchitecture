#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum RoundType {
    STRIKE,
    SPARE,
    NORMAL
};

// Function to calculate the score based on rounds
int calculateScore(const vector<tuple<int, RoundType, int>>& rounds) {
    int score = 0;

    for (size_t i = 0; i < 10; ++i) {
        const auto& round = rounds[i];

        if (get<1>(round) == STRIKE) {
            score += 10; // Add 10 for the strike

            if (i + 1 < rounds.size()) {
                score += get<0>(rounds[i + 1]); 

                if (i + 2 < rounds.size() && get<1>(rounds[i + 1]) == STRIKE) {
                    score += get<2>(rounds[i + 2]); 
                }
            }
        } else if (get<1>(round) == SPARE) {
            score += 10;

            if (i + 1 < rounds.size()) {
                score += get<2>(rounds[i + 1]); 
            }
        } else {
            score += get<0>(round);
        }
    }

    return score;
}

int main() {
    vector<tuple<int, RoundType, int>> rounds;

    int pins, firstPlay;
    string roundType;
    while (cin >> pins >> roundType >> firstPlay) {
        RoundType type;
        if (roundType == "STRIKE") {
            type = STRIKE;
        } else if (roundType == "SPARE") {
            type = SPARE;
        } else {
            type = NORMAL;
        }
        rounds.push_back(make_tuple(pins, type, firstPlay));
    }

    int score = calculateScore(rounds);
    cout << "Final score: " << score << endl;

    return 0;
}
