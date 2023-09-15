# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 100


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = [] #signifies teams as a list
    with open(sys.argv[1], 'r' ) as file:
        reader = csv.DictReader(file)
        # reads it as a dict row by row
        # then all VALUES of that column are allocated to the respective fieldname/column head/ KEY starting from the first line  even if the csv file
        # had a header with the keys written in the first row of the csv file
        # if the fieldname was something else like name, score then it will be considered as the column heads
        # and even the first header lines values will be considered under the diff KEY/fieldname/column head you specified

        # and if you use
########  'reader = csv.DictReader(file)'
# it automatically assumes that the first row contains the keys/field name
 # here i reads line by line as reader is a csv dict and they are read row wise
        for i in reader:   # each line of the reader is a individual dict with a key(team) and a value(rating)
            i["rating"] = int(i["rating"])
            # the key here is rating and eb=very columns rating value is taken
            #and converted to int then assigned to i["rating"] that line(i)'s rating VALUE
            teams.append(i) # now it is added row by row as it is what append does
            # therefore teams is a list of dictionaries
    counts = {} # here count is a dictionary containing many key - value pairs
    # TODO: Simulate N tournaments and keep track of win counts

    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1 # python automatically creates
                                # the count dictionary you do not have to specify every thing
        else:
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    while len(teams) != 1:
        teams = simulate_round(teams)

    return teams[0]["team"] # return out of teams list first row's value of key 'team'


if __name__ == "__main__":
    main()
