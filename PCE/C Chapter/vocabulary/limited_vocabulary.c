/* the input file (first argument) should be a txt file.
 * white spaces should seperate between words.
 * the vocabulary file (second argument) should be a txt file in the format of:
 * 0firstword 1firstsynonym
 * 0secondword 1secondsynonym
 * 0thirdword 1thirdsynonym
 * etc... (the program ignores lines transitions in both files)
 * the program will change each of the words with its synonym. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if !defined(ERROR)
#define ERROR (-1)
#endif
#define MAX_LINE_LENGTH (250)
#define MAX_WORD_LENGTH (15)

#define true (1)
#define false (0)

static FILE* vocab_file;
static FILE* temp_file;
static FILE* text_file;
const static char* text_file_name;
const static char* vocab_file_name;
const static char* temp_file_name = "temp_file.txt";

int scan_file(FILE* file);
char* find_synonym(char* word);
int identical(char* w1, char* w2);
int error(char* message); /* prints "ERROR." and returns error value */
int rewrite_file();

int main(int argc, char* argv[])
{
	if(argc != 3) {
		return error("Usage: program_name text_file_name vocabulary_file_name");
	}

	text_file_name = argv[1];
	vocab_file_name = argv[2];

	 /* open streams for all of the files */
	text_file = fopen(text_file_name, "r");
	vocab_file = fopen(vocab_file_name, "r");
	temp_file = fopen(temp_file_name, "w");
	if(text_file == NULL || vocab_file == NULL || temp_file == NULL) {
		return error("text file, vocab file or temp file open error.");
	}

	if(scan_file(text_file) != 0) { /* documentation next to the function */
		return ERROR;
	}

	if(rewrite_file() != 0) { /* documentation next to the function */
		return ERROR;
	}

	if(remove(temp_file_name) != 0) { /* removes the temp file */
		return error("couldn't delete tempfile");
	}

	return 0;
}

int scan_file(FILE* file) /* scans the text file and writes a temp file with the fixed text */
{
	char* curword = malloc(MAX_WORD_LENGTH);
	char* synonym = malloc(MAX_WORD_LENGTH);

	if(curword == NULL || synonym == NULL) {
		return error("curword or synonym couldn't be allocated");
	}

	while(fscanf(file, "%s ", curword) != EOF)
	{
		synonym = find_synonym(curword);
		if(synonym == NULL) {
			fprintf(temp_file, "%s", "SYNONYM_IS_NULL");
			return error("Synonym is NULL");
		}
		fprintf(temp_file, "%s ", synonym);
	}
	return 0;
}

/* searches for a synonym in the vocabulary file.
 * if a synonym is found - it returns it.
 * if not - the original word is returned */
char* find_synonym(char* word)
{
	char* curword = malloc(MAX_WORD_LENGTH);
	char* prevword = malloc(MAX_WORD_LENGTH);
	if(curword == NULL || prevword == NULL) {
		return NULL;
	}

	FILE* prevwordp;
	if((prevwordp = fopen(vocab_file_name, "r")) == NULL) {
		return NULL;
	}
	rewind(vocab_file);

	while(fscanf(vocab_file, "%s ", curword) != EOF)
	{
		if(identical(curword+1, word) == true) /* curword points to the id (0 or 1) */
		{
			if((curword)[0] == '0') {
				fscanf(vocab_file, "%s ", curword);
				free(prevwordp);
				return (curword+1);
			} else {
				free(prevwordp);
				return (prevword+1);
			}
		}
		fscanf(prevwordp, "%s ", prevword);
	}
	free(prevword);
	return word;
}

int identical(char* w1, char* w2) /* returns true if the strings are identical and false if not */
{
	if(strlen(w1) != strlen(w2)) {
		return false;
	}

	int i = 0;
	do {
		if(w1[i] != w2[i]) {
			return false;
		}
		++i;
	} while(w1[i] != '\0');

	return true;
}

int rewrite_file()  /* rewrite the text file with the text from the temp file */
{
	if(fclose(text_file) != 0) {
		return error("Error closing textfile.");
	}

	text_file = fopen(text_file_name, "w");
	if(text_file == NULL) {
		return error("text file, vocab file or temp file open error.");
	}
	fclose(temp_file);
	temp_file = fopen("temp_file.txt", "r");

	char* str;
	if((str = malloc(MAX_WORD_LENGTH)) == NULL) {
		return error("could not allocate memory for str");
	}

	while(fscanf(temp_file, "%s ", str) != EOF)
	{
		fprintf(text_file, "%s ", str);
	}

	if(0 != fclose(text_file) || 0 != fclose(temp_file) || 0 != fclose(vocab_file)) {
		return error("Error closing textfile, tempfile or vocabfile");
	}

	return 0;
}

int error(char* message) { /* prints "ERROR.", a message and returns error value */

	printf("\n----->%s<-----\n%s\n\n", "ERROR:", message);
	return ERROR;
}
