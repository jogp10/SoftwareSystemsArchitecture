#ifndef ROLL_H
#define ROLL_H

class Roll
{
protected:
    int pinsKnocked;

public:
    Roll(int pins = 0) : pinsKnocked(pins) {}

    virtual ~Roll() {}

    virtual int getPinsKnocked() const
    {
        return pinsKnocked;
    }
};

class Play : public Roll
{
public:
    Play(int pins = 0) : Roll(pins) {}
};

class BonusPlay : public Roll
{
public:
    BonusPlay(int pins = 0) : Roll(pins) {}
};

#endif // ROLL_H
