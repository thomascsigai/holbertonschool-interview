#include "mul.h"

/**
 * init_digit_array - allocates and initializes an array to contain the digits
 *   of a base 10 number.
 *
 * @size: array size
 * Return: pointer to initialized array, or NULL on failure
 */
unsigned int *init_digit_array(size_t size)
{
	unsigned int *arr = malloc(sizeof(unsigned int) * size);
	size_t i;

	if (arr)
	{
		for (i = 0; i < size; i++)
			arr[i] = 0;
	}
	return (arr);
}

/**
 * string_int_multiply - multiplies two base 10 numbers represented as strings
 *                     and stores the result in an array of digits.
 *
 * @prod_digits: array to store digits of the product
 * @n1_digits: string containing multiplicand digits in ASCII
 * @n2_digits: string containing multiplier digits in ASCII
 * @n1_len: length of the multiplicand string
 * @n2_len: length of the multiplier string
 */
void string_int_multiply(unsigned int *prod_digits, char *n1_digits,
			 char *n2_digits, size_t n1_len, size_t n2_len)
{
	int i, j, sum;
	unsigned char digit1, digit2;

	if (!prod_digits || !n1_digits || !n2_digits)
		return;

	for (i = n1_len - 1; i >= 0; i--)
	{
		sum = 0;
		digit1 = n1_digits[i] - '0';

		for (j = n2_len - 1; j >= 0; j--)
		{
			digit2 = n2_digits[j] - '0';
			sum += prod_digits[i + j + 1] + digit1 * digit2;
			prod_digits[i + j + 1] = sum % 10;
			sum /= 10;
		}
		prod_digits[i + j + 1] += sum;
	}
}

/**
 * print_error - print error message and exit with code 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * error_checking - check for wrong input
 *
 * @argc: number of arguments
 * @argv: arguments vector
 */
void error_checking(int argc, char *argv[])
{
	int i;
	size_t j;

	if (argc != 3)
		print_error();

	for (i = 1; i < argc; i++)
		for (j = 0; j < strlen(argv[i]); j++)
			if (!isdigit(argv[i][j]))
				print_error();
}

/**
 * main - entry point
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	size_t i, av1_len, av2_len, prod_len;
	unsigned int *prod_digits;

	error_checking(argc, argv);

	av1_len = strlen(argv[1]);
	av2_len = strlen(argv[2]);
	prod_len = av1_len + av2_len;

	prod_digits = init_digit_array(prod_len);

	if (!prod_digits)
		print_error();

	string_int_multiply(prod_digits, argv[1], argv[2], av1_len, av2_len);

	for (i = 0; i < prod_len && prod_digits[i] == 0; i++)
		;

	if (i == prod_len)
		_putchar('0');
	else
	{
		for (; i < prod_len; i++)
			_putchar(prod_digits[i] + '0');
	}

	_putchar('\n');
	free(prod_digits);

	return (0);
}
