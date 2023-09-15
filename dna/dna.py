import csv
import sys

list = []


def main():

    check()
    filename = sys.argv[1]
    sequence = sys.argv[2]

    # TODO: Read database file into a variable
    memory = read_database(filename)

    # TODO: Read DNA sequence file into a variable
    DNA = read_sequence(sequence)

    # TODO: Find longest match of each STR in DNA sequence
    counts = {}
    for i in range(1, len(list)):
        counts[list[i]] = longest_match(DNA, list[i])

    # TODO: Check database for matching profiles
    person = check_name(memory, counts)
    print(person)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


def check():
    if len(sys.argv) != 3:
        print("Incorrect Usage\n Usage: python dna.py data.csv sequence.txt")
    else:
        return 0


def read_database(filename):
    global list
    memory = []
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        list = reader.fieldnames
        for i in reader:
            memory.append(i)
    return memory


def read_sequence(sequence):
    with open(sequence, "r") as file:
        s = file.read()
        return s


def check_name(memory, counts):
    for i in range(0, len(memory) - 1):
        k = 0
        for j in range(1, len(list)):
            if (int(memory[i][list[j]]) == counts[list[j]]):
                k += 1
                if k == len(list) - 1:
                    return memory[i]["name"]

    return 'No match'


main()
