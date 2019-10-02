#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

#define MAX_INPUT 100
#define MAX_LISTS 50

#define MAX_NAME_LENGTH 20
#define MAX_STRUCTURE_NAME 10

#define MAX_LISTOP_LENGTH 15
#define MAX_INST_LENGTH 10
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
	PUSH_FRONT,
	POP_BACK,
	POP_FRONT,
	FRONT,
	BACK,
	INSERT_ORDERED,
	EMPTY,
	SIZE,
	MAX,
	MIN,
	SWAP,
	SHUFFLE
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
void dumpDataStructure(char* input);

struct list* lists[MAX_LISTS];
char* listNames[MAX_LISTS];
int listNum=0;

struct list_item listItems[MAX_LISTS];

