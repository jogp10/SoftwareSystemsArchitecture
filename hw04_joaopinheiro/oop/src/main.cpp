#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "game.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    Game game;
    vector<Round> rounds;
    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        int pins;
        while (iss >> pins)
        {
            if (rounds.size() < 10)
            { // Check if we've completed 10 rounds
                if (rounds.empty() || rounds.back().getRoundSize() == 2 || rounds.back().getRoundScore() == 10)
                {
                    rounds.push_back(Round()); // Start a new round
                }
                rounds.back().addPlay(Play(pins));
            }
            else
            { // Handle the 10th round
                if (rounds.back().getRoundSize() == 2)
                {
                    rounds.back().addPlay(BonusPlay(pins));
                    break;
                }
                rounds.back().addPlay(Play(pins));
            }
        }
    }
    game.setRounds(rounds);

    int score = game.getGameScore();
    cout << "Final score: " << score << endl;

    return 0;
}