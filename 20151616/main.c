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
	if(!strcmp(input, instruction[instName = CREATE])){
		return true;
	}
	else if(!strcmp(input, instruction[instName = DUMPDATA])){
		return true;
	}
	else if(!strcmp(input, instruction[instName = QUIT])){
		return false;
	}
	else if(!strncmp(input, instruction[instName = LIST], 4)){
		inputCmpListInst(input+5);
		//send after parts "list_"
		return true;
	}
}

void inputCmpListInst(char* input){
	if(!strcmp(input, listInstruction[instListName = PUSH_BACK])){
	}
	else if(!strcmp(input, listInstruction[instListName = POP_BACK])){
	}
	else if(!strcmp(input, listInstruction[instListName = POP_FRONT])){
	}
	else if(!strcmp(input, listInstruction[instListName = FRONT])){
	}
	else if(!strcmp(input, listInstruction[instListName = BACK])){
	}
	else if(!strcmp(input, listInstruction[instListName = INSERT_ORDERED])){
	}
	else if(!strcmp(input, listInstruction[instListName = EMPTY])){
	}
	else if(!strcmp(input, listInstruction[instListName = SIZE])){
	}
	else if(!strcmp(input, listInstruction[instListName = MAX])){
	}
	else if(!strcmp(input, listInstruction[instListName = MIN])){
	}
	else if(!strcmp(input, listInstruction[instListName = SWAP])){
	}
	else if(!strcmp(input, listInstruction[instListName = SHUFFLE])){
	}
	return;
}
