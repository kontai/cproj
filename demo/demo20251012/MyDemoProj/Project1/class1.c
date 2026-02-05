#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	char *str1 = "Hello, World!";
	char *str2 = (char *)malloc(20 * sizeof(char));
	if (str2 == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	strcpy(str2, str1);
	printf("%s\n", str2);
	free(str2);
	return 0;
}