/*


















Lab 5: Inheritance
You are welcome to collaborate with one or two classmates on this lab, though it is expected that every student in any such group
contribute equally to the lab.

Simulate the inheritance of blood types for each member of a family.

$ ./inheritance
Child (Generation 0): blood type OO
    Parent (Generation 1): blood type AO
        Grandparent (Generation 2): blood type OA
        Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type OB
        Grandparent (Generation 2): blood type AO
        Grandparent (Generation 2): blood type BO

Background
A person’s blood type is determined by two alleles (i.e., different forms of a gene). The three possible alleles are A, B, and O, of
which each person has two (possibly the same, possibly different). Each of a child’s parents randomly passes one of their two blood
type alleles to their child. The possible blood type combinations, then, are: OO, OA, OB, AO, AA, AB, BO, BA, and BB.

For example, if one parent has blood type AO and the other parent has blood type BB, then the child’s possible blood types would be
AB and OB, depending on which allele is received from each parent. Similarly, if one parent has blood type AO and the other OB, then
the child’s possible blood types would be AO, OB, AB, and OO.

Getting Started
Open VS Code.

Start by clicking inside your terminal window, then execute cd by itself. You should find that its “prompt” resembles the below.

$
Click inside of that terminal window and then execute

wget https://cdn.cs50.net/2022/fall/labs/5/inheritance.zip
followed by Enter in order to download a ZIP called inheritance.zip in your codespace. Take care not to overlook the space between
wget and the following URL, or any other character for that matter!

Now execute

unzip inheritance.zip
to create a folder called inheritance. You no longer need the ZIP file, so you can execute

rm inheritance.zip
and respond with “y” followed by Enter at the prompt to remove the ZIP file you downloaded.

Now type

cd inheritance
followed by Enter to move yourself into (i.e., open) that directory. Your prompt should now resemble the below.

inheritance/ $
If all was successful, you should execute

ls
and you should see inheritance.c.

If you run into any trouble, follow these same steps again and see if you can determine where you went wrong!

Understanding
Take a look at the distribution code in inheritance.c.

Notice the definition of a type called person. Each person has an array of two parents, each of which is a pointer to another person
struct. Each person also has an array of two alleles, each of which is a char (either 'A', 'B', or 'O').

Now, take a look at the main function. The function begins by “seeding” (i.e., providing some initial input to) a random number
generator, which we’ll use later to generate random alleles. The main function then calls the create_family function to simulate the
creation of person structs for a family of 3 generations (i.e. a person, their parents, and their grandparents). We then call
print_family to print out each of those family members and their blood types. Finally, the function calls free_family to free any
memory that was previously allocated with malloc.

The create_family and free_family functions are left to you to write!

Implementation Details
Complete the implementation of inheritance.c, such that it creates a family of a specified generation size and assigns blood type
alleles to each family member. The oldest generation will have alleles assigned randomly to them.

The create_family function takes an integer (generations) as input and should allocate (as via malloc) one person for each member of
the family of that number of generations, returning a pointer to the person in the youngest generation. For example,
create_family(3) should return a pointer to a person with two parents, where each parent also has two parents. Each person should
have alleles assigned to them. The oldest generation should have alleles randomly chosen (as by calling the random_allele function),
and younger generations should inherit one allele (chosen at random) from each parent. Each person should have parents assigned to
them. The oldest generation should have both parents set to NULL, and younger generations should have parents be an array of two
pointers, each pointing to a different parent. We’ve divided the create_family function into a few TODOs for you to complete.

First, you should allocate memory for a new person. Recall that you can use malloc to allocate memory, and sizeof(person) to get the
number of bytes to allocate. Next, we’ve included a condition to check if generations > 1. If generations > 1, then there are more
generations that still need to be allocated. We’ve already created two new parents, parent0 and parent1, by recursively calling
create_family. Your create_family function should then set the parent pointers of the new person you created. Finally, assign both
alleles for the new person by randomly choosing one allele from each parent. Otherwise (if generations == 1), then there will be no
parent data for this person. Both parents of your new person should be set to NULL, and each allele should be generated randomly.
Finally, your function should return a pointer for the person that was allocated.
The free_family function should accept as input a pointer to a person, free memory for that person, and then recursively free memory
for all of their ancestors.

Since this is a recursive function, you should first handle the base case. If the input to the function is NULL, then there’s
nothing to free, so your function can return immediately. Otherwise, you should recursively free both of the person’s parents before
freeing the child. Walkthrough This video was recorded when the course was still using CS50 IDE for writing code. Though the
interface may look different from your codespace, the behavior of the two environments should be largely similar!


Hints
You might find the rand() function useful for randomly assigning alleles. This function returns an integer between 0 and RAND_MAX,
or 2147483647. In particular, to generate a pseudorandom number that is either 0 or 1, you can use the expression rand() % 2.
Remember, to allocate memory for a particular person, we can use malloc(n), which takes a size as argument and will allocate n bytes
of memory. Remember, to access a variable via a pointer, we can use arrow notation. For example, if p is a pointer to a person, then
a pointer to this person’s first parent can be accessed by p->parents[0]. Not sure how to solve? How to Test Your Code Upon running
./inheritance, your program should adhere to the rules described in the background. The child should have two alleles, one from each
parent. The parents should each have two alleles, one from each of their parents.

For example, in the example below, the child in Generation 0 received an O allele from both Generation 1 parents. The first parent
received an A from the first grandparent and a O from the second grandparent. Similarly, the second parent received an O and a B
from their grandparents.

$ ./inheritance
Child (Generation 0): blood type OO
    Parent (Generation 1): blood type AO
        Grandparent (Generation 2): blood type OA
        Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type OB
        Grandparent (Generation 2): blood type AO
        Grandparent (Generation 2): blood type BO

Execute the below to evaluate the correctness of your code using check50. But be sure to compile and test it yourself as well!

check50 cs50/labs/2023/x/inheritance
Execute the below to evaluate the style of your code using style50.

style50 inheritance.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/labs/2023/x/inheritance
*/
// Simulate genetic inheritance of blood type
// Headers
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 2
// Structs
// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[MAX];
    char alleles[MAX];
} person;

// Constants
const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

// Prototypes
person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL)
    {
        printf("Unable to allocate memory for person, generation =  %i\n", generations);
        // If this fails the first time, that's fine, but what if it fails on subsequent persons?
        // Not my problem (currently).
        return NULL;
    }

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }

    // If there are no generations left to create
    else
    {
        for (int i = 0; i < MAX; i++)
        {
            // TODO: Set parent pointers to NULL
            new_person->parents[i] = NULL;

            // TODO: Randomly assign alleles
            new_person->alleles[i] = random_allele();
        }
    }

    // TODO: Return newly created person
    // visualize(new_person)
    return new_person;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }

    // TODO: Free parents recursively
    for (int i = 0; i < MAX; i++)
    {
        free_family(p->parents[i]);
    }

    // TODO: Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
