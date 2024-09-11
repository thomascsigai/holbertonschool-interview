#include "wild_cmp.h"

/**
 * wildcmp - Compares two strings with wildcard support.
 * @s1: The first string.
 * @s2: The second string, which may contain wildcards (*).
 *
 * Return: 1 if the strings match, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
    /* Base case: both strings are empty */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If pattern is empty but string is not */
    if (*s2 == '\0')
        return (0);

    /* If pattern has a '*', check for two scenarios */
    if (*s2 == '*')
    {
        /* Move past '*' and continue matching */
        if (wildcmp(s1, s2 + 1))
            return (1);
        
        /* If the current characters match, try to match the rest of s1 */
        if (*s1 != '\0' && wildcmp(s1 + 1, s2))
            return (1);
    }
    else
    {
        /* Check if the current characters match */
        if (*s1 != '\0' && (*s1 == *s2 || *s2 == '.'))
            return (wildcmp(s1 + 1, s2 + 1));
    }

    return (0);
}
