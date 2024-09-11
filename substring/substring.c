#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - Finds all starting indices of substrings in `s` that are
 *                   concatenations of each word in `words` exactly once.
 * @s: The string to scan.
 * @words: Array of words.
 * @nb_words: Number of words in the array.
 * @n: Pointer to store the number of found indices.
 * 
 * Return: An array of starting indices. NULL if no substrings are found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *result = NULL;
    int word_len = strlen(words[0]);
    int concat_len = word_len * nb_words;
    int s_len = strlen(s);
    int i, j, k;

    if (s_len < concat_len || nb_words == 0 || word_len == 0)
    {
        *n = 0;
        return NULL;
    }

    // Initialize word count map
    int *word_count = (int *)calloc(nb_words, sizeof(int));
    for (i = 0; i < nb_words; i++)
    {
        for (j = 0; j < nb_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                word_count[i]++;
                break;
            }
        }
    }

    *n = 0;
    result = (int *)malloc(sizeof(int) * (s_len / word_len + 1));

    // Sliding window approach
    for (i = 0; i <= s_len - concat_len; i++)
    {
        int temp_count[nb_words];
        memcpy(temp_count, word_count, sizeof(int) * nb_words);

        for (j = 0; j < nb_words; j++)
        {
            char *word = (char *)malloc(word_len + 1);
            strncpy(word, s + i + j * word_len, word_len);
            word[word_len] = '\0';

            int match = 0;
            for (k = 0; k < nb_words; k++)
            {
                if (strcmp(word, words[k]) == 0 && temp_count[k] > 0)
                {
                    temp_count[k]--;
                    match = 1;
                    break;
                }
            }
            free(word);
            if (!match)
                break;
        }

        if (j == nb_words)
        {
            result[*n] = i;
            (*n)++;
        }
    }

    if (*n == 0)
    {
        free(result);
        result = NULL;
    }
    
    free(word_count);
    return result;
}
