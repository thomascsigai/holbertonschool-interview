/**
 * wildcmp - Compares two strings with wildcard support.
 * @s1: The first string.
 * @s2: The second string, which may contain wildcards (*).
 *
 * Return: 1 if the strings match, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings are empty, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If pattern is empty but the string is not */
	if (*s2 == '\0')
		return (0);

	/* If the pattern has a '*', check for both cases */
	if (*s2 == '*')
	{
		/* Skip '*' and continue matching (zero characters) */
		if (wildcmp(s1, s2 + 1))
			return (1);

		/* If the current characters match, try to match the rest of s1 */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
	}
	else
	{
		/* If characters match or current character in s2 is '.', continue */
		if (*s1 != '\0' && (*s1 == *s2 || *s2 == '.'))
			return (wildcmp(s1 + 1, s2 + 1));
	}

	/* If no match is found */
	return (0);
}
