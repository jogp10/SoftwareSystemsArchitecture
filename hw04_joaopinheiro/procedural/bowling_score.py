import sys

def read_input(filename):
    plays = []
    with open(filename, 'r') as file:
        for line in file:
            plays.extend(map(int, line.strip().split()))
    return plays

def calculate_score(plays):
    score = 0
    round = 1
    play_index = 0
    while round <= 10:
        if plays[play_index] == 10:  # Strike
            score += 10 + plays[play_index + 1] + plays[play_index + 2]
            play_index += 1
        elif plays[play_index] + plays[play_index + 1] == 10:  # Spare
            score += 10 + plays[play_index + 2]
            play_index += 2
        else:
            score += plays[play_index] + plays[play_index + 1]
            play_index += 2
        round += 1
    return score

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python bowling_score.py <input_file>")
        sys.exit(1)

    input_file = sys.argv[1]
    plays = read_input(input_file)
    final_score = calculate_score(plays)
    print("Final score:", final_score)
