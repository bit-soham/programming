#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            //in computer ranks and the voters start from 0
            // here j defines the rank and for each rank the vote function is implemented
            // the value of j is passed on to rank and i is passed to voter showing which voter is voting
            // so a specific rank and voter and a candidate name is passed onto
            //"bool vote(int voter, int rank, string name)"

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }

        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;// recount after some candidates eliminated
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //here candidate name matching is done and that candidates vote count is increased
    for (int j = 0 ; j < candidate_count ; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            preferences[voter][rank] = j; // imagine 2-d table with j values filling in
                                          //  with one voter for each row and ranks for column
                                          // like (0,3) == 3 ; means 1st voter in rank 4 voted for candidate no. 4
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // imagine the 2-d table in the vote function for this one
    // name of table is preferences, i = rows,voters , j = columns,ranks
    for (int i = 0 ; i < voter_count ; i++)
    {
        for (int j = 0 ; j < candidate_count ; j++)
        {
            // see previos vote fxn where preferences[voter][rank] = j;
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes++;
                break ;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0 ; i < candidate_count ; i++)
    {
        // each voter has atleast in any rank once voted for the winning candidate
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // sorting like in plurality just finding the min vote
    int n = 0;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (!candidates[i].eliminated)// n = no. of candidates not eliminated
        {
            n++;
        }
    }

    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (!candidates[i].eliminated)
        {
            int k = 0;
            for (int j = 0 ; j < candidate_count ; j++)
            {

                if (j != i)// no comparism with itself
                {
                    if (!candidates[j].eliminated)
                    {
                        if (candidates[i].votes <= candidates[j].votes)// comparisn between candidates not eliminated
                        {
                            k++; //least vote amount will have k = n-1 as it is not compared with itself
                        }
                        else
                        {
                            break ;//if even once that vote is greater means it is never the minimum vote amount so abondon it
                        }
                        if (k == n - 1)
                        {
                            return candidates[i].votes;//this guy has the least votes
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int n = 0;
    int k = 0;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (!candidates[i].eliminated)
        {
            n++;
            {
                if (candidates[i].votes == min)//tie occurs when only the candidates with the highest no. of votes is left
                                               //or some with same highest no. of votes are ther and rest are eliminated
                                               // therefore that highest amount of votes will be the minimum no.
                {                              // and each candidate not eliminated will have that "min" amount of vote
                    k++;
                }
            }
        }
    }
    if (n == k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (candidates[i].votes == min)// eleminate candidates with minimum amount of votes
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}