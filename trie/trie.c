// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);
void visualize(node *list, int child);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
        fclose(infile);
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char* word)
/*
You probably want to start by setting a node pointer, cursor to the root of the trie.
Iterate through every letter in the argument word and, as you do, determine the array index that corresponds to that letter.
You can use the index for a letter to check if children[index] is a NULL pointer, meaning the word does not exist in the trie.
If children[index] is in fact a node, you can reset cursor to this node and check for the next letter in its children nodes.
Remember that the lookup should be case-insensitive. For instance, A and a should correspond to 0, B and b corresponds to 1, etc.
*/
{
    bool check_result = false;
    // Set a node pointer, cursor, to the root of the trie.
    node *cursor = root;
    int cursor_position = 0;
    int index;
    /*
    //start at root
    printf("position 0: %c\n", tolower(word[0]));
    index = tolower(word[0]) - 'a';
    printf("index: %i\n", index);
    if (cursor->children[0])
    {
        printf("root %i\n", cursor->is_word);
        //move to 0x1
        cursor = cursor->children[0];
    }
    //start at 0x1
    printf("position 1: %c\n", tolower(word[1]));
    index = tolower(word[1]) - 'a';
    printf("index: %i\n", index);
    if (cursor->children[index])
    {
        printf("0x1 %i\n", cursor->is_word);
        //move to 0x2
        cursor = cursor->children[index];
    }
    //start at 0x2
    printf("position 2: %c\n", tolower(word[2]));
    index = tolower(word[2]) - 'a';
    printf("index: %i\n", index);
    if (cursor->children[index])
    {
        printf("0x2 %i\n", cursor->is_word);
        //move to 0x3
        cursor = cursor->children[index];
    }
    //start at 0x3
    printf("end of word: expect 1 see: %i\n", cursor->is_word);
    if (cursor->children[index])
    {
        printf("Exists\n");
        cursor = cursor->children[index];
    }
    if (!NULL)
    {
        printf("not null prints Exists\n");
        cursor = cursor->children[index];
    }*/



    // Iterate through every letter in the argument word and, as you do, determine the array index
    // that corresponds to that letter.
    while (word[cursor_position] != '\0')
    {
        // printf("cursor position: %i\n", cursor_position);
        // You can use the index for a letter to check if children[index] is a NULL pointer, meaning
        // the word does not exist in the trie.
        index = tolower(word[cursor_position]) - 'a';
        // printf("index: %i\n", index);
        // visualize(cursor, index);
        if (cursor->children[index] == NULL)
        {
            return check_result;
        }
        // If children[index] is in fact a node, you can reset cursor to this node and check for the
        // next letter in its children nodes.
        else
        {
            cursor_position++;
            /* if (word[cursor_position] == '\0')
            {
                break;
            }*/
            cursor = cursor->children[index];
        }

            // Remember that the lookup should be case-insensitive. For instance, A and a should
            // correspond to 0, B and b corresponds to 1, etc.
    }

    // printf("index: %i\n", index);
    check_result = cursor->is_word;

    return check_result;
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node* current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}

void visualize(node *list, int child)
{
    printf("\n+-- List Visualizer --+\n\n");
    //while (list !=NULL)
    //{
        printf("Location %p\n", list);
        if (list->is_word)
        printf("is_word:\n");
        printf("Next: %p\n\n", list->children[child]);
        //list = list->next;
    //}
    printf("\n+---------------------+\n\n");
}