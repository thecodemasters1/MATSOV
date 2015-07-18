#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS (0)
#define WRONG_ARGUMENTS (-1)
#define NOT_ENOUGH_MEMORY (-2)

int main(int argc, char * argv[])
{
	int iarg = 0;
	int len = 0;

	char * phrase = NULL;
	char * p = NULL;
	char * q = NULL;

	/* Check arguments */
	if( argc < 2 ) {

		printf("Usage: check_palindrome <phrase>\n");
		printf("Example: check_palindrome Madam, I'm Adam.\n");
		return WRONG_ARGUMENTS;
	}

	/* Calculate total length */
	len = 0;
	for(iarg = 1; iarg < argc; ++iarg) {

		len += strlen(argv[iarg]);
	}

	/* Allocate memory for the entire phrase + terminating NULL */
	phrase = malloc(len + 1);
	if( phrase == NULL ) {

		printf("Not enough memory.\n");
		return NOT_ENOUGH_MEMORY;
	}

	/* Copy words into phrase */
	phrase[0] = '\0';

	for(iarg = 1; iarg < argc; ++iarg) {

		strcat(phrase, argv[iarg]);
	}

	/* Check to see if phrase is a palindrome */
	p = phrase;
	q = phrase + len - 1;

	while(p < q) {

		while(0 == isalpha(*p)) {

			++p;
		}
		while(0 == isalpha(*q)) {

			--q;
		}
		if(tolower(*p) == tolower(*q)) {

			++p;
			--q;
		} else {

			break;
		}
	}

	if(p >= q ) {

		printf("Yes, this is a palindrome!\n");
	} else {

		printf("No, this is not a palindrome!\n");
	}

	/* Free memory */
	free(phrase);

	return SUCCESS;
}