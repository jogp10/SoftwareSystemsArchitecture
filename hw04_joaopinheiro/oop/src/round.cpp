#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "roll.h"

class Round
{
private:
    std::vector<Roll *> plays;
    bool _hasBonusPlay = false;

public:
    void addPlay(const Play &play)
    {
        plays.push_back(new Play(play));
    }

    void addPlay(const BonusPlay &play)
    {
        plays.push_back(new BonusPlay(play));
        _hasBonusPlay = true;
    }

    int getRoundScore() const
    {
        int score = 0;
        for (const auto& play : plays)
        {
            score += play->getPinsKnocked();
        }
        return score;
    }

    bool isStrike() const
    {
        return plays.size() == 1 && plays[0]->getPinsKnocked() == 10;
    }

    bool isSpare() const
    {
        return plays.size() == 2 && getRoundScore() == 10;
    }

    size_t getRoundSize() const
    {
        return plays.size();
    }

    int getPlayScore(size_t playIndex) const
    {
        if (playIndex > plays.size())
        {
            return 0;
        }
        return plays[playIndex-1]->getPinsKnocked();
    }

    // Check if the last play is a BonusPlay
    bool hasBonusPlay() const
    {
        return _hasBonusPlay;
    }
};