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
	int newdata, newdata2;
	int i=0;
	sscanf(input,"%s %s %d %d",listOperationName,dataStructureName,&newdata,&newdata2);
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
		struct list_elem* startnodep;
		startnodep = list_head(currList)->next;

		struct list_item* itemp = list_entry(startnodep, struct list_item, elem);
		printf("%d\n",itemp->data);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = BACK])){
		struct list_elem* endnodep;
		endnodep = list_tail(currList)->prev;

		struct list_item* itemp = list_entry(endnodep, struct list_item, elem);
		printf("%d\n",itemp->data);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = INSERT_ORDERED])){
		/*struct list_elem
		  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@how to use list_less_func by pointer??
		list_insert_ordered(struct list*, struct list_elem*, list_less_func*, void*);*/
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = EMPTY])){
		if(list_empty(currList)){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SIZE])){
		printf("%d\n",(int)list_size(currList));
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = MAX])){
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@how to use list_less_func
		//list_max(currList, )
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = MIN])){

	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SWAP])){
		struct list_elem* node1 = list_head(currList);
		struct list_elem* node2 = list_head(currList);

		for(int i=0;i<newdata;++i){
			node1 = list_next(node1);
		}
		for(int i=0;i<newdata2;++i){
			node2 = list_next(node2);
		}
		struct list_item* itemp1 = list_entry(node1, struct list_item, elem);
		struct list_item* itemp2 = list_entry(node2, struct list_item, elem);
		//swap(itemp1->data, itemp2->data);
		//swap(&node1, &node2);
		//swap implicit declarationd@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SHUFFLE])){
		//no shuffle? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
