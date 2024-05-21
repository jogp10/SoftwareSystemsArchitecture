#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "round.cpp"

using namespace std;

class Game
{
private:
    vector<Round> rounds;

public:
    void addRound(const Round &round)
    {
        rounds.push_back(round);
    }

    int getGameScore() const
    {
        int score = 0;

        for (size_t i = 0; i < rounds.size(); ++i)
        {
            const Round &currentRound = rounds[i];
            score += currentRound.getRoundScore();

            if (currentRound.hasBonusPlay())
            {
                break;
            }

            // Check for strikes or spares
            if (currentRound.isStrike())
            {
                // If strike, add the next two plays' scores
                // If next round is a 2 play round, add both plays
                // If next round is a 1 play round, add the next round's first play and the next round's first play
                const Round &nextRound = rounds[i + 1];
                score += nextRound.getPlayScore(1);

                if (nextRound.getRoundSize() > 1)
                {
                    score += nextRound.getPlayScore(2);
                }
                else if (i + 2 < rounds.size())
                {
                    score += rounds[i + 2].getPlayScore(1);
                }
            }
            else if (currentRound.isSpare())
            {
                // If spare, add the first play's score of the next round
                score += rounds[i + 1].getPlayScore(1);
            }
        }

        return score;
    }

    void setRounds(const vector<Round> &rounds)
    {
        this->rounds = rounds;
    }
};