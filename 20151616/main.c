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
	if(!strncmp(input, instruction[instNum = CREATE], 6)){
		createDataStructure(input+7);
		//send after parts "create "
		return true;
	}
	else if(!strcmp(input, instruction[instNum = DUMPDATA])){
		return true;
	}
	else if(!strcmp(input, instruction[instNum = QUIT])){
		return false;
	}
	else if(!strncmp(input, instruction[instNum = INST_LIST], 4)){
		inputCmpListInst(input+5);
		//send after parts "list_"
		return true;
	}
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
	if(!strcmp(input, listInstruction[instListNum = PUSH_BACK])){
	}
	else if(!strcmp(input, listInstruction[instListNum = POP_BACK])){
	}
	else if(!strcmp(input, listInstruction[instListNum = POP_FRONT])){
	}
	else if(!strcmp(input, listInstruction[instListNum = FRONT])){
	}
	else if(!strcmp(input, listInstruction[instListNum = BACK])){
	}
	else if(!strcmp(input, listInstruction[instListNum = INSERT_ORDERED])){
	}
	else if(!strcmp(input, listInstruction[instListNum = EMPTY])){
	}
	else if(!strcmp(input, listInstruction[instListNum = SIZE])){
	}
	else if(!strcmp(input, listInstruction[instListNum = MAX])){
	}
	else if(!strcmp(input, listInstruction[instListNum = MIN])){
	}
	else if(!strcmp(input, listInstruction[instListNum = SWAP])){
	}
	else if(!strcmp(input, listInstruction[instListNum = SHUFFLE])){
	}
	return;
}
