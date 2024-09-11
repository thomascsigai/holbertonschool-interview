#include "regex.h"

/**
 * regex_match - Checks if the string matches the pattern.
 * @str: The string to match.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the string matches the pattern, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	/* Base case: both string and pattern are empty */
	if (*str == '\0' && *pattern == '\0')
	{
		return (1);
	}

	/* If pattern is empty but string is not, no match */
	if (*pattern == '\0')
	{
		return (0);
	}

	/* Handle the '*' in the pattern */
	if (*(pattern + 1) == '*')
	{
		/* Case 1: '*' matches zero occurrence */
		if (regex_match(str, pattern + 2))
		{
			return (1);
		}

		/* Case 2: '*' matches one or more occurrences */
		if ((*str != '\0' && (*str == *pattern || *pattern == '.'))
		&& regex_match(str + 1, pattern))
		{
			return (1);
		}
	}
	else
	{
		/* Pattern does not have a '*' */
		if ((*str != '\0' && (*str == *pattern || *pattern == '.'))
		&& regex_match(str + 1, pattern + 1))
		{
			return (1);
		}
	}

	/* No match found */
	return (0);
}
