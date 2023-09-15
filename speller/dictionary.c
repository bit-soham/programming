// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 457678;

// Hash table
node *table[N];

int length = 0;
unsigned int buckets = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    buckets = hash(word);
    // n is a pointer pointing toward a node
    node *n = table[buckets];
    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // printf("%s ", word);
    int s = strlen(word);
    int k = round(s / 2);
    int index = 0;
    int sum = 0;

    if (s > 1)
    {
        index += 26;
        if (s > 2)
        {
            index += 676; // add all combinations of two letters
            for (int i = 0; i < s; i++)
            {
                sum += toupper(word[i]);
            }
            int j = round(sum % 26);

            index += j * 17576;
            index += (toupper(word[0]) - 'A') *
                     676; // chunk of 676 for each starting letter contaoining all conbinations of last and middle letter
            index += (toupper(word[s - 1]) - 'A') * 26;
            index += toupper(word[k]) - 'A';
            // printf("%i ", index);
            return index;
        }
        else
        {
            index += (toupper(word[0]) - 'A') * 26;
            index += toupper(word[s - 1]) - 'A';
            // printf("%i ", index);
            return index;
        }
    }
    else
    {
        index += toupper(word[0]) - 'A';
        // printf("%i ", index);
        return index;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    // set temporary place for word
    char tmp[LENGTH + 1];
    while (fscanf(dict, "%s", tmp) != EOF)
    {
        // find hash
        buckets = hash(tmp);
        // make a node
        node *n = malloc(sizeof(node));

        n->next = table[buckets];
        // node n points to wher hash_head was pointing

        // nodes word
        strcpy(n->word, tmp);

        // tabele, hash_head pints to n
        table[buckets] = n;
        // do not free n as it is now part of the linked list
        length++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int k = length;
    return k;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        if (n != NULL)
        {
            while (n != NULL)
            {
                node *tmp = n;
                n = n->next;
                free(tmp);
            }
        }
        else
        {
           free(n);
        }
    }
    return true;
}
