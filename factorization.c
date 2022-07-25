#include "rsa.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - print out the two numbers which when multiplied
 * together result in the number in question.
 * @num: string representing the number to factorize.
 */
void factorize(char *num)
{
	long long int product = atoll(num);
	long long int i;
	long long int other;

	for (i = 2; i * i <= product; i++)
	{
		if (i * i == product)
		{
			printf("%lld=%lld*%lld\n", product, i, i);
			return;
		}
		if ((product % i == 0) && isPrime(i))
		{
			other = product / i;
			if (isPrime(other))
			{
				printf("%lld=%lld*%lld\n", product, other, i);
				return;
			}
		}
	}
}

/**
 * isPrime - check if an integer is a prime number.
 * @n: the number to perform the primality test on.
 * Return: Either 0 or 1.
 */
int isPrime(long long int n)
{
	long long int i;

	if (n == 2)
		return (1);
	else if (n % 2 == 0)
		return (0);
	for (i = 2; i * i <= n; i++)
	{
		if (n % ((2 * i) + 1) == 0)
			return (0);
	}
	return (1);
}
