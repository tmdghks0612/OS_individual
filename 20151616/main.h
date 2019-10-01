#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

#define MAX_INPUT 100
#define MAX_LISTS 50

#define MAX_NAME_LENGTH 20
#define MAX_STRUCTURE_NAME 10

char* instruction[] = {
	"create","dumpdata","delete","quit","list"
};

enum Inst{
	CREATE = 0,
	DUMPDATA = 1,
	DELETE = 2,
	QUIT = 3,
	INST_LIST = 4
};
enum Inst instNum;

char* listInstruction[] = {
	"push_back", "pop_back", "pop_front", "front", "back", "insert_ordered", "empty", "size", "max", "min", "swap", "shuffle"
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
enum ListOp instListNum;

char* dataStructure[] = {
	"list", "hashtable", "bitmap"
};

enum DataStructure{
	LIST = 0,
	HASHTABLE = 1,
	BITMAP = 2
};
enum DataStructure dataStructureNum;

bool inputCmpInst(char* input);
void inputCmpListInst(char* input);

void createDataStructure(char* input);

struct list* lists[MAX_LISTS];
char* listNames[MAX_LISTS];
int listNum=0;
