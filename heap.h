#ifndef __HEAP_H__
#define __HEAP_H__

#define BLOCK_SIZE 1024
#define MAX_BLOCK_RECORDS ((BLOCK_SIZE - sizeof(short))/sizeof(Record))
#define CHARACTERISTIC_SIZE 5

typedef struct Record{
	int id;
	char name[15];
	char surname[20];
	char city[10];
}Record;

int HP_CreateFile(char *fileName);

int HP_OpenFile(char *fileName);

int HP_CloseFile(int fileDesc);

int HP_InsertEntry(int fileDesc, Record record);

void HP_GetAllEntries(int fileDesc, char* fieldName, void *value);

#endif
