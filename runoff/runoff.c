/*
Runoff
For this program, you’ll implement a program that runs a runoff election, per the below.

./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
Background
You already know about plurality elections, which follow a very simple algorithm for determining the winner of an election: every
voter gets one vote, and the candidate with the most votes wins.

But the plurality vote does have some disadvantages. What happens, for instance, in an election with three candidates, and the
ballots below are cast?

Five ballots, tie betweeen Alice and Bob

A plurality vote would here declare a tie between Alice and Bob, since each has two votes. But is that the right outcome?

There’s another kind of voting system known as a ranked-choice voting system. In a ranked-choice system, voters can vote for more
than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. The resulting
ballots might therefore look like the below.

Three ballots, with ranked preferences

Here, each voter, in addition to specifying their first preference candidate, has also indicated their second and third choices. And
now, what was previously a tied election could now have a winner. The race was originally tied between Alice and Bob, so Charlie was
out of the running. But the voter who chose Charlie preferred Alice over Bob, so Alice could here be declared the winner.

Ranked choice voting can also solve yet another potential drawback of plurality voting. Take a look at the following ballots.

Nine ballots, with ranked preferences

Who should win this election? In a plurality vote where each voter chooses their first preference only, Charlie wins this election
with four votes compared to only three for Bob and two for Alice. But a majority of the voters (5 out of the 9) would be happier
with either Alice or Bob instead of Charlie. By considering ranked preferences, a voting system may be able to choose a winner that
better reflects the preferences of the voters.

One such ranked choice voting system is the instant runoff system. In an instant runoff election, voters can rank as many candidates
as they wish. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner
of the election.

If no candidate has more than 50% of the vote, then an “instant runoff” occurs. The candidate who received the fewest number of
votes is eliminated from the election, and anyone who originally chose that candidate as their first preference now has their second
preference considered. Why do it this way? Effectively, this simulates what would have happened if the least popular candidate had
not been in the election to begin with.

The process repeats: if no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for
them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority,
that candidate is declared the winner.

Let’s consider the nine ballots above and examine how a runoff election would take place.

Alice has two votes, Bob has three votes, and Charlie has four votes. To win an election with nine people, a majority (five votes)
is required. Since nobody has a majority, a runoff needs to be held. Alice has the fewest number of votes (with only two), so Alice
is eliminated. The voters who originally voted for Alice listed Bob as second preference, so Bob gets the extra two vote. Bob now
has five votes, and Charlie still has four votes. Bob now has a majority, and Bob is declared the winner.

What corner cases do we need to consider here?

One possibility is that there’s a tie for who should get eliminated. We can handle that scenario by saying all candidates who are
tied for last place will be eliminated. If every remaining candidate has the exact same number of votes, though, eliminating the
tied last place candidates means eliminating everyone! So in that case, we’ll have to be careful not to eliminate everyone, and just
declare the election a tie between all remaining candidates.

Some instant runoff elections don’t require voters to rank all of their preferences — so there might be five candidates in an
election, but a voter might only choose two. For this problem’s purposes, though, we’ll ignore that particular corner case, and
assume that all voters will rank all of the candidates in their preferred order.

Sounds a bit more complicated than a plurality vote, doesn’t it? But it arguably has the benefit of being an election system where
the winner of the election more accurately represents the preferences of the voters.

Getting Started
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt
resembles the below:

$
Next execute

wget https://cdn.cs50.net/2022/fall/psets/3/runoff.zip
in order to download a ZIP called runoff.zip into your codespace.

Then execute

unzip runoff.zip
to create a folder called runoff. You no longer need the ZIP file, so you can execute

rm runoff.zip
and respond with “y” followed by Enter at the prompt to remove the ZIP file you downloaded.

Now type

cd runoff
followed by Enter to move yourself into (i.e., open) that directory. Your prompt should now resemble the below.

runoff/ $
If all was successful, you should execute

ls
and see a file named runoff.c. Executing code runoff.c should open the file where you will type your code for this problem set. If
not, retrace your steps and see if you can determine where you went wrong!

Understanding
Let’s take a look at runoff.c. We’re defining two constants: MAX_CANDIDATES for the maximum number of candidates in the election,
and MAX_VOTERS for the maximum number of voters in the election.

Next up is a two-dimensional array preferences. The array preferences[i] will represent all of the preferences for voter number i,
and the integer preferences[i][j] here will store the index of the candidate who is the jth preference for voter i.

Next up is a struct called candidate. Every candidate has a string field for their name, and int representing the number of votes
they currently have, and a bool value called eliminated that indicates whether the candidate has been eliminated from the election.
The array candidates will keep track of all of the candidates in the election.

The program also has two global variables: voter_count and candidate_count.

Now onto main. Notice that after determining the number of candidates and the number of voters, the main voting loop begins, giving
every voter a chance to vote. As the voter enters their preferences, the vote function is called to keep track of all of the
preferences. If at any point, the ballot is deemed to be invalid, the program exits.

Once all of the votes are in, another loop begins: this one’s going to keep looping through the runoff process of checking for a
winner and eliminating the last place candidate until there is a winner.

The first call here is to a function called tabulate, which should look at all of the voters’ preferences and compute the current
vote totals, by looking at each voter’s top choice candidate who hasn’t yet been eliminated. Next, the print_winner function should
print out the winner if there is one; if there is, the program is over. But otherwise, the program needs to determine the fewest
number of votes anyone still in the election received (via a call to find_min). If it turns out that everyone in the election is
tied with the same number of votes (as determined by the is_tie function), the election is declared a tie; otherwise, the last-place
candidate (or candidates) is eliminated from the election via a call to the eliminate function.

If you look a bit further down in the file, you’ll see that these functions — vote, tabulate, print_winner, find_min, is_tie, and
eliminate — are all left to up to you to complete!

Specification
Complete the implementation of runoff.c in such a way that it simulates a runoff election. You should complete the implementations
of the vote, tabulate, print_winner, find_min, is_tie, and eliminate functions, and you should not modify anything else in runoff.c
(and the inclusion of additional header files, if you’d like).

vote
Complete the vote function.

The function takes arguments voter, rank, and name. If name is a match for the name of a valid candidate, then you should update the
global preferences array to indicate that the voter voter has that candidate as their rank preference (where 0 is the first
preference, 1 is the second preference, etc.). If the preference is successfully recorded, the function should return true; the
function should return false otherwise (if, for instance, name is not the name of one of the candidates). You may assume that no two
candidates will have the same name. Hints tabulate Complete the tabulate function.

The function should update the number of votes each candidate has at this stage in the runoff.
Recall that at each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been
eliminated. Hints print_winner Complete the print_winner function.

If any candidate has more than half of the vote, their name should be printed and the function should return true.
If nobody has won the election yet, the function should return false.
Hints
find_min
Complete the find_min function.

The function should return the minimum vote total for any candidate who is still in the election.
Hints
is_tie
Complete the is_tie function.

The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
The function should return true if every candidate remaining in the election has the same number of votes, and should return false
otherwise. Hints eliminate Complete the eliminate function.

The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
The function should eliminate the candidate (or candidates) who have min number of votes.
Walkthrough

Usage
Your program should behave per the example below:

./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice
Testing
Be sure to test your code to make sure it handles…

An election with any number of candidate (up to the MAX of 9)
Voting for a candidate by name
Invalid votes for candidates who are not on the ballot
Printing the winner of the election if there is only one
Not eliminating anyone in the case of a tie between all remaining candidates
Execute the below to evaluate the correctness of your code using check50. But be sure to compile and test it yourself as well!

check50 cs50/problems/2023/x/runoff
Execute the below to evaluate the style of your code using style50.

style50 runoff.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2023/x/runoff
*/
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
} candidate;

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
void reset_voter_preferences(void);

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
    reset_voter_preferences();

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

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
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // What is a valid vote?
    // Candidate must exist.
    // Candidate not ranked before?
    // Search through each candidates name to find a match
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            if (rank == 0)
            {
                preferences[voter][rank] = i;
                return true;
            }
            else
                for (int j = 0; j < rank; j++)
                {

                    if (preferences[voter][j] == i)
                    {
                        return false;
                    }
                    if (j == rank - 1 && preferences[voter][j] != i)
                    {
                        preferences[voter][rank] = i;
                        return true;
                    }
                }
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Count the votes for each candidate still in the running
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int k = 0; k < candidate_count; k++)
            {
                if (preferences[i][j] == k && candidates[k].eliminated != true)
                {
                    candidates[k].votes++;
                    j = candidate_count;
                }
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Test
    // if majority votewinner, print winner, return true.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2 + voter_count % 2)
        {
            printf("We have a winner! %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    //    return 0;
    int min;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            min = candidates[i].votes;
            i = candidate_count;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    // does more than one candidate have min number votes?
    int tie_counter = 0, remaining_candidate = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            remaining_candidate++;
            if (candidates[i].votes == min)
            {
                tie_counter++;
            }
        }
    }
    if (tie_counter == remaining_candidate)
    {
        return true;
    }
    else if (tie_counter > 1) // there's a tie, either eliminate all or declare all winners.
    {
        return false;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // set canindate wit min votes elimination status to true.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
void reset_voter_preferences(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = -5;
        }
    }
}