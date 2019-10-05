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
	char buffer[20] = {-1,};
	sscanf(input,"%s %s",instructionName, buffer);
	if(!strcmp(instructionName, instruction[instNum = CREATE])){
		createDataStructure(input+7);
		//send after parts "create "
		return true;
	}
	else if(!strcmp(instructionName, instruction[instNum = DUMPDATA])){
		if(buffer[0] == -1){
			return true;
		}
		dumpDataStructure(input+9);
		return true;
	}
	else if(!strcmp(instructionName, instruction[instNum = DELETE])){
		deleteDataStructure(input+7);
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
	//initialize all datastructure types
	struct list* currList;

	char dataStructureName[MAX_NAME_LENGTH];
	sscanf(input,"%s", dataStructureName);
	//dataStructureType contains type of structure. dataStructureName contains the name of it
	if(currList = getListpointerByName(dataStructureName)){
		if(list_empty(currList)){
			return;
		}
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

void deleteDataStructure(char* input){
	int i=0;
	//initialize all datastructure types
	struct list* currList;
	struct list_elem* nextnode;
	char dataStructureName[MAX_NAME_LENGTH];
	sscanf(input,"%s", dataStructureName);
	//dataStructureType contains type of structure. dataStructureName contains the name of it
	if(currList = getListpointerByName(dataStructureName)){
		if(!list_empty(currList)){
			for(struct list_elem* e = list_begin(currList);e != list_tail(currList);e = list_next(e)){
				struct list_item *f = list_entry(e, struct list_item, elem);
				free(f);
			}
			for(struct list_elem* e = list_begin(currList);e != list_tail(currList);e = nextnode){
				nextnode = list_next(e);
				free(e);
			}
		}
		for(i=0;i<MAX_LISTS;++i){
			if(!strcmp(dataStructureName,listNames[i])){
				free(lists[i]);
				listNum--;
				for(i=0;i<listNum;++i){
					lists[i] = lists[i+1];
					listNames[i] = listNames[i+1];
				}
				return;
			}
		}
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
		//lists[0]->head
		listNum++;
	}
	else if(!strcmp(dataStructureType, dataStructure[dataStructureNum = HASHTABLE])){
		hashs[hashNum] = (struct hash*)malloc(sizeof(struct hash));
		hashNames[hashNum] = (char*)malloc(sizeof(char) * MAX_NAME_LENGTH);

		if(hash_init(hashs[hashNum],hashHashFunc ,hashLessFunc , 0)){
			printf("Initialize memory error!\n");
		}
		else{
			hashNum++;
		}
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
	char dataStructureName2[MAX_NAME_LENGTH] = {-1, };
	int newdata, newdata2, newdata3;
	int listSize=0;
	int i=0;
	//splice has a different format
	if(sscanf(input, "%s %s %d %s %d %d",listOperationName, dataStructureName, &newdata, dataStructureName2, &newdata2, &newdata3) == 6){
		if(!strcmp(listOperationName, listInstruction[instListNum = SPLICE])){
			int curridx = 0;
			int insertidx =0;
			struct list_item* itemp;
			struct list* list1 = getListpointerByName(dataStructureName);
			struct list* list2 = getListpointerByName(dataStructureName2);
			struct list_elem* insertnode = list_begin(list1);
			struct list_elem* startnode = list_begin(list2);
			struct list_elem* endnode = list_begin(list2);

			for(insertidx=0;insertidx < newdata; insertidx++){
				insertnode = list_next(insertnode);
			}

			for(curridx = 0; curridx<newdata2; curridx++){
				startnode = list_next(startnode);
			}

			for(curridx = 0;curridx<newdata3; curridx++){

				endnode = list_next(endnode);
			}
			list_splice(insertnode, startnode, endnode);

		}
		return;
	}
	else if(sscanf(input,"%s %s %s",listOperationName, dataStructureName, dataStructureName2) >= 2){
		if(!strcmp(listOperationName, listInstruction[instListNum = UNIQUE])){
			struct list* list1 = getListpointerByName(dataStructureName);
			if(dataStructureName2[0] == -1){
				list_unique(list1, NULL, func, 0);
			}
			else{		
				struct list* list2 = getListpointerByName(dataStructureName2);
				list_unique(list1, list2, func, 0);
			}
			return;
		}
	}
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
	else if(!strcmp(listOperationName, listInstruction[instListNum = PUSH_FRONT])){
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
	else if(!strcmp(listOperationName, listInstruction[instListNum = SORT])){
		list_sort(currList, func, 0);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = INSERT_L])){
		int idx = newdata;
		struct list_elem* e = list_begin(currList);
		struct list_elem* newnode = (struct list_elem*)malloc(sizeof(struct list_elem));
		struct list_item* itemp = (struct list_item*)malloc(sizeof(struct list_elem));
		itemp = list_entry(newnode,struct list_item, elem);
		itemp->data = newdata2;

		for(int curridx = 0; curridx<idx;++curridx){
			e = list_next(e);
		}
		list_insert(e, newnode);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = INSERT_ORDERED])){
		struct list_elem* newnode = (struct list_elem*)malloc(sizeof(struct list_elem));

		struct list_item* itemp = (struct list_item*)malloc(sizeof(struct list_elem));
		itemp = list_entry(newnode,struct list_item, elem);
		itemp->data = newdata;
		list_insert_ordered(currList, newnode, func, 0);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = EMPTY_L])){
		if(list_empty(currList)){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SIZE_L])){
		printf("%d\n",(int)list_size(currList));
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = MAX])){
		struct list_elem* maxelem;
		maxelem = list_max( currList, func, 0 );
		printf("%d\n",list_entry(maxelem, struct list_item, elem)->data);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = MIN])){
		struct list_elem* minelem;
		minelem = list_min( currList, func, 0 );
		printf("%d\n",list_entry(minelem, struct list_item, elem)->data);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SWAP])){
		struct list_elem* node1 = list_head(currList);
		struct list_elem* node2 = list_head(currList);

		for(int i=0;i<newdata+1;++i){
			node1 = list_next(node1);
		}
		for(int i=0;i<newdata2+1;++i){
			node2 = list_next(node2);
		}
		list_swap(node1, node2);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = REVERSE])){
		list_reverse(currList);
	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = SHUFFLE])){
		for(struct list_elem* e = list_begin(currList);e != list_tail(currList);e = list_next(e)){
			for(struct list_elem* f = list_begin(currList);f != list_tail(currList); f = list_next(f)){
				if(rand()%2){
					list_swap(e, f);
				}
			}
		}

	}
	else if(!strcmp(listOperationName, listInstruction[instListNum = REMOVE])){
		int idx = newdata;
		struct list_elem* e = list_begin(currList);
		struct list_item* itemp;

		for(int curridx = 0; curridx<idx;++curridx){
			e = list_next(e);
		}

		itemp = list_entry(e,struct list_item, elem);
		list_remove(e);
		free(itemp);
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

void inputCmpHashtableInst(char* input){
	struct hash* currHash;
	char HashOperationName[MAX_HASHOP_LENGTH];
	char dataStructureName[MAX_NAME_LENGTH];
	char newdata[MAX_HASHOP_LENGTH];
	int i=0,value=0;
	sscanf(input,"%s %s %s",HashOperationName,dataStructureName,newdata);
	//search for list with name of dataStructureName
	if(!(currList = getHashpointerByName(dataStructureName))){
		return;
	}
	if(!strcmp(HashOperationName, hashInstruction[instHashNum = APPLY])){
	}
	if(!strcmp(hashOperationName, hashInstruction[instHashNum = CLEAR])){
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = DELETE_H])){
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = EMPTY_H])){
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = FIND])){
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = INSERT_H])){
		value = atoi(newdata);
		hash_insert(currHash, hash_elem*);
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = INT_2])){
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = REPLACE])){
	}
	else if(!strcmp(hashOperationName, hashInstruction[instHashNum = SIZE_H])){
	}
	return;
}

struct hash* getHashpointerByName(char* name){
	int i=0;
	for(i=0;i<MAX_HASHS;++i){
		if(!strcmp(name,hashNames[i])){
			return hashs[i];
		}
	}
	return NULL;
}
