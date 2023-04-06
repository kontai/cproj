/*
*	READ_AND_REARRAY
*	2021/04/11
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columnts, int max);
void rearrange(char *output, char const *input, int n_column, int const column[]);

void main() {
	int n_columns;
	int colummns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	n_columns = read_column_numbers(colummns, MAX_COLS);

	while (gets(input) != NULL) {
		printf("Original input: %s\n", input);
		read_column_numbers(output, input, n_columns, colummns);
		printf("Rearranged line: %s\n", output);
	}

	system("pause");
}

/*
* 獲取行數與
*/
int read_column_numbers(int colummns[], int max) {
	int num = 0;
	int ch;
	while (num < max && scanf("%d", &colummns[num]) == 1 && colummns[num] >= 0)
		num += 1;
	if (num % 2 != 0)
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	while ((ch = getchar()) != EOF && ch != '\n')
		;

	return num;
}

void rearrange(char *output, char const *input, int n_column, int const column[]) {
	int col;
	int output_col;
	int len;
	len = strlen(input);
	output_col = 0;

	for (col = 0; col < n_column ; col += 2) {
		int nchars = column[col + 1] - column[col] + 1;

		if (column[col] >= len || output_col == MAX_INPUT - 1)
			break;
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		strncpy(output + output_col, input, column[col], nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';





}
