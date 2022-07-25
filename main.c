#include "rsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - driver code.
 * @argc: number of command line arguments.
 * @argv: array holding command line arguments.
 * Return: either EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	FILE *fileptr;
	char *line = NULL;
	char *token;
	size_t linecap = 0;
	ssize_t linelen;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	fileptr = fopen(argv[1], "r");
	if (!fileptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((linelen = getline(&line, &linecap, fileptr)) > 0)
	{
		token = strtok(line, " \t\r\n\a");
		factorize(token);
	}
	free(line);
	line = NULL;
	fclose(fileptr);

	exit(EXIT_SUCCESS);
}
