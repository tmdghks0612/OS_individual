#include "main.h"

int main(){
	int i=0;
	char* input;

	do{
		free(input);
		input = (char*)malloc(sizeof(char) * MAX_INPUT);
		fgets(input,MAX_INPUT,stdin);
		input[strlen(input) - 1] = '\0';
		//change last index of the string to NULL

	}while(inputCmpInst(input));
	return 0;
}

bool inputCmpInst(char* input){
	int i=0;
	char instructionName[MAX_INST_LENGTH];
	char buffer[20];
	sscanf(input,"%s %s",instructionName, buffer);
	if(!strcmp(instructionName, instruction[instNum = CREATE])){
		createDataStructure(input+7);
		//send after parts "create "
		return true;
	}
	else if(!strcmp(instructionName, instruction[instNum = DUMPDATA])){
		dumpDataStructure(input+9);
		return true;
	}
	else if(!strcmp(instructionName, instruction[instNum = QUIT])){
		return false;
	}
	else if(!strncmp(instructionName, instruction[instNum = INST_LIST], 4)){
		inputCmpListInst(input+5);
		//send after parts "list_"
		return true;
	}
}
void dumpDataStructure(char* input){
	int i=0, j=0;
	struct list* currList;
	char dataStructureName[MAX_NAME_LENGTH];
	sscanf(input,"%s", dataStructureName);
	//dataStructureType contains type of structure. dataStructureName contains the name of it
	if(currList = getListpointerByName(dataStructureName)){
		for(struct list_elem* e = list_begin(currList);e != list_tail(currList);e = list_next(e)){
			struct list_item *f = list_entry(e, struct list_item, elem);
			printf("%d ", f->data);
		}
		printf("\n");
		return;
	}


	
	//write dumpdata for hashtable
	//write dumpdata for bitmap
	return;

}

void createDataStructure(char* input){
	char dataStructureName[MAX_NAME_LENGTH];
	char dataStructureType[MAX_STRUCTURE_NAME];
	sscanf(input,"%s %s", dataStructureType, dataStructureName);
	//dataStructureType contains type of structure. dataStructureName contains the name of it
	if(!strcmp(dataStructureType, dataStructure[dataStructureNum = LIST])){

		//malloc first!
		lists[listNum] = (struct list*)malloc(sizeof(struct list));
		listNames[listNum] = (char*)malloc(sizeof(char) * MAX_NAME_LENGTH);
		//listItems[listNum] = (struct list_item*)malloc(sizeof(struct list_item));

		//initialize operation
		list_init(lists[listNum]);
		strcpy(listNames[listNum],dataStructureName);

		printf("name : %s\n",listNames[listNum]);
		//lists[0]->head
		listNum++;
	}
	else if(!strcmp(dataStructureType, dataStructure[dataStructureNum = HASHTABLE])){
	}
	else if(!strcmp(dataStructureType, dataStructure[dataStructureNum = BITMAP])){
	}

	return;
}

void inputCmpListInst(char* input){
	struct list* currList;
	struct list_items* currListItem;
	char listOperationName[MAX_LISTOP_LENGTH];
	char dataStructureName[MAX_NAME_LENGTH];
	int newdata;
	int i=0;
	sscanf(input,"%s %s %d",listOperationName,dataStructureName,&newdata);
	//search for list with name of dataStructureName
	if(!(currList = getListpointerByName(dataStructureName))){
		return;
	}
	if(!strcmp(listOperationName, listInstruction[instListNum = PUSH_BACK])){
		struct list_elem* newnodep;
		struct list_elem* newnode = (struct list_elem*)malloc(sizeof(struct list_elem));

		list_push_back(currList,newnode);
		newnodep = list_tail(currList)->prev;
		//initialize and data input in list_item
		struct list_item* itemp = list_entry(newnodep, struct list_item, elem);
		itemp->data = newdata;

	}
	if(!strcmp(listOperationName, listInstruction[instListNum = PUSH_FRONT])){
		struct list_elem* newnodep;
		struct list_elem* newnode = (struct list_elem*)malloc(sizeof(struct list_elem));

		list_push_front(currList,newnode);
		newnodep = list_head(currList)->next;

		struct list_item* itemp = list_entry(newnodep, struct list_item, elem);
		itemp->data = newdata;

	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = POP_BACK])){
		struct list_elem* endnodep;
		endnodep = list_tail(currList)->prev;

		struct list_item* itemp = list_entry(endnodep, struct list_item, elem);
		list_pop_back(currList);
		free(itemp);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = POP_FRONT])){
		struct list_elem* startnodep;
		startnodep = list_head(currList)->next;

		struct list_item* itemp = list_entry(startnodep, struct list_item, elem);
		list_pop_front(currList);
		free(itemp);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = FRONT])){
		//printf("%d\n",list_begin(currList));
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = BACK])){
		//printf("%d\n",list_rbegin(currList));
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = INSERT_ORDERED])){
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = EMPTY])){
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SIZE])){
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = MAX])){
		//printf("%d\n",list_max(currList,))
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = MIN])){
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SWAP])){
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SHUFFLE])){
	}
	return;
}

struct list* getListpointerByName(char* name){
	int i=0;
	for(i=0;i<MAX_LISTS;++i){
		if(!strcmp(name,listNames[i])){
			return lists[i];
		}
	}
	return NULL;
}
