if __name__ == "__main__":
    line = input()
    plays = input()
    line = [int(l) for l in line.split(' ')]
    plays = [int(l) for l in plays.split(' ')]

    players = [0 for i in range(0, line[0])]
    for i in range(0, line[0]):
        players[i] = 0
        for j in range(0, line[1]):
            players[i] = players[i] + plays[i + j * line[0]]

    winner = 1
    points = -1

    for i in range(0, line[0]):
        if players[i] >= points:
            points = players[i]
            winner = i + 1

    print(winner)