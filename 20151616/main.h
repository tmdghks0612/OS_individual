#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

#define MAX_INPUT 100
#define MAX_LISTS 50

char* instruction[] = {
	"create","dumpdata","delete","quit","list"
};

char* listInstruction[] = {
	"push_back", "pop_back", "pop_front", "front", "back", "insert_ordered", "empty", "size", "max", "min", "swap", "shuffle"
};

enum Inst{
	CREATE = 0,
	DUMPDATA = 1,
	DELETE = 2,
	QUIT = 3,
	LIST = 4
};

enum ListOp{
	PUSH_BACK = 0,
	POP_BACK = 1,
	POP_FRONT = 2,
	FRONT = 3,
	BACK = 4,
	INSERT_ORDERED = 5,
	EMPTY = 6,
	SIZE = 7,
	MAX = 8,
	MIN = 9,
	SWAP = 10,
	SHUFFLE = 11
};

bool inputCmpInst(char* input);
void inputCmpListInst(char* input);


enum Inst instName;
enum ListOp instListName;

struct list lists[MAX_LISTS];
int listNum=0;
