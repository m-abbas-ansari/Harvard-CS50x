// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

//Word Count
unsigned int count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);
    int k;
    
    int h;
    h = hash(word); //computing hash code
    node *tmp = NULL;
    
    if(table[h] != NULL) //Checking if linked list exists at h
    {   
        //accessing  and traversing linked list at hash table index h
        for(tmp = table[h]; tmp != NULL; tmp = tmp->next )
        {
            k = strcasecmp((tmp->word),word);
            if(k == 0)
            {
            
                return true;
            }
        }
        
    }
    return false;



}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //Hash Function djb2 by Dan Bernstein.
    //source: http://www.cse.yorku.ca/~oz/hash.html

    unsigned long hash = 5381;
    int c ,n;
    n = strlen(word);

    for(int i = 0; i < n; i++)
    {
        c = tolower(word[i]);
        hash = ((hash << 5) + hash) + c;
    }

    return hash%N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Cleaning hash table so as to load data into it
    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    //Opening dictionary file
     FILE *read = fopen(dictionary, "r");
     if(read == NULL)
     {
         printf("File did not open succesfully\n");
         return false;
     }
     //string to store word form dictionary
     char *wrd = malloc((LENGTH + 1)*sizeof(char));
     if(wrd == NULL)
     {
         return false;
     }
     while(fscanf(read, "%s",wrd) != EOF)
     {
        count++; //incrementing word count

        //Creating a node
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }
        strcpy(n->word, wrd); //copying wrd into node

        //Inserting node into hash table
        int h = hash(wrd); //computing hash code
        n->next = table[h]; //pointing n to where table[h] points at
        table[h] = n;      //hash table[h] now points to node n
    }
    fclose(read);
    free(wrd);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp = NULL;
    node *cursor = NULL;
    //iterating through hash table
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            cursor = table[i];
            //iterating and freeing linked list at hash table index i
            while((cursor->next) != NULL)
            {
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
            if(cursor != NULL)
            {
            free(cursor);
            }   
        }
    }
    //Clearing hash table
    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    return true;
}
