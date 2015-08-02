#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#if !defined(ERROR)
#define ERROR (-1)
#endif

#define true (1)
#define false (0)
#define MAX_BOARD_SIZE (99)

int string_to_int(char* numbers);
int initialize_board(char* argv[]);
int step_board();
int count_live_neighbours(int row, int column);
int print_board();
char visualize_cell(int row, int column);

static int* cell; /* The board */
static int rows, columns;

int main(int argc, char* argv[])
{
	if(argc != 13) {
		printf("Usage: game_of_life rows columns generations a b c d e f g h i\n");
		printf("Each of the letters a-i is one of the cells:\n");
		printf("a  b  c\nd  e  f\ng  h  i\n");
		printf("If a letter is 0, the cell will start the game as a dead cell.\n");
		printf("Else, the cell will start the game as a live cell.\n\n");
	}

	if(rows > MAX_BOARD_SIZE || columns > MAX_BOARD_SIZE) { // T: Should check rows and columns values after init
// T: what if rows size will be less than 3?
		printf("Maximum board size (height or width) is 255!"); // T: MAX_BOARD_SIZE accoring to you is 99
		return ERROR;
	}

	rows = string_to_int(argv[1]);
	columns = string_to_int(argv[2]);

	if((cell = malloc(sizeof(int)*rows*columns)) == NULL) {
		printf("couldn't allocate memory for cell array");
		return ERROR;
	}
        // T: seperate between operations- init board and parsing arguments
	initialize_board(argv); /* creates the initial board according to arguments */

	int i;
	for(i=0; i<argv[3][0]-48; i++) { /* calculate #argv[3] generations */
		if(step_board() == ERROR) {
			printf("error in step_board function");
			return ERROR;
		}
	}

	if(print_board() == ERROR) { /* prints the updated board to result.txt */
		printf("error in print_board function");
		return ERROR;
	}

	free(cell);

	printf("Finished calculating. The result is in Result.txt.\n\n");

	return 0;
}

int string_to_int(char* numbers)
{
	if(numbers == NULL) {
		printf("String pointer is null!");
		return ERROR;
	}

	int counter = 0, index = 0;
	int i = (int)pow(10, strlen(numbers)-1);
	for(;i>0;i/=10)
	{
		counter += i*((int)numbers[index]-48); // T: better write `0` instead of 48
		++index;
	}
	return counter;
}

int initialize_board(char* argv[])
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(argv[i*3+j+4][0] == '0') {
				cell[i*columns + (rows/2-1)*columns + columns/2 - 1 + j] = 0;
			} else {
				cell[i*columns + (rows/2-1)*columns + columns/2 - 1 + j] = 1;
			}
		}
	} // T: Should be init of the rest of the board, not only the 9 squere

	return 0;
}

int step_board() /* checks all of the cells and updates them by the rules */
{
	int newcell[rows][columns]; // T: compilation error, array size can't be variable
	int liveneighs;
        // T: init new cell array
	int i, j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{
			liveneighs = count_live_neighbours(i, j);
			if(liveneighs == ERROR) {
				return ERROR;
			}

			switch(liveneighs)
			{
			case 3: newcell[i][j] = 1;
					break;
			case 2: if(cell[i*columns+j] == 1) { // T: newcell[i][j]= cell[I*columns+j]
						newcell[i][j] = 1;
					} else {
						newcell[i][j] = 0;
					}
					break;
			default: newcell[i][j] = 0;
			}
		}
	}

	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{
			cell[i*columns + j] = newcell[i][j];
		}
	}

	return 0;
}

int count_live_neighbours(int row, int column) /* counts the live neighbours of a specific cell */
{
	int neighs = 0;
	int up=0, down=0, right=0, left=0;

	if(row != 0) { up = 1; }
	if(row != rows-1) { down = 1; }
	if(column != 0) { left = 1; }
	if(column != columns-1) { right = 1; }

	if(up == 1) {
		if(cell[(row-1)*columns + column] == 1) {
			++neighs;
		}
	}
	if(down == 1) {
		if(cell[(row+1)*columns + column] == 1) {
			++neighs;
		}
	}
	if(left == 1) {
		if(cell[row*columns + column-1] == 1) {
			++neighs;
		}
	}
	if(right == 1) {
		if(cell[row*columns + column+1] == 1) {
			++neighs;
		}
	}
	if(up == 1) {
		if(left == 1) {
			if(cell[(row-1)*columns + column-1] == 1) {
				++neighs;
			}
		}
		if(right == 1) {
			if(cell[(row-1)*columns + column+1] == 1) {
				++neighs;
			}
		}
	}
	if(down == 1) {
		if(left == 1) {
			if(cell[(row+1)*columns + column-1] == 1) {
				++neighs;
			}
		}
		if(right == 1) {
			if(cell[(row+1)*columns + column+1] == 1) {
				++neighs;
			}
		}
	}
        // T: No, it will work but think about other way
	return neighs;
}

int print_board() /* prints the updated board to result.txt */
{
	FILE* result;
	if((result = fopen("result.txt", "w")) == NULL) {
		printf("error opening result file");
		return ERROR;
	}

	int i, j;
	for(i=0; i<rows; i++) {
		for(j=0; j<columns; j++) {
			fprintf(result, "%c ", visualize_cell(i, j));
		}
		fprintf(result, "\n");
	}

	if(fclose(result) != 0) {
		printf("error closing result file");
		return ERROR;
	}
	return 0;
}

char visualize_cell(int row, int column) /* returns X if cell is alive, decimal if not */
{
	if(cell[row*columns + column] == 0) {
		return '.';
	}

	return 'X';

}
