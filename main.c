#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "BF.h"
#include "heap.h"

#define FILENAME_HEAP 		"heap"
#define FILENAME_CSV 		"100000.csv"

int main(int argc, char** argv) 
{
	int heapFile, i;
	char buffer[BUFSIZ], *ptr, *token;
	const char delim[] = ",\"";
	Record record;

	BF_Init();
	
	/* Create heap file */
	if(HP_CreateFile(FILENAME_HEAP) < 0) {
		fprintf(stderr, "Error creating heap file.\n");
		exit(EXIT_FAILURE);
	}
	
	/* Open heap file */
	if ((heapFile = HP_OpenFile(FILENAME_HEAP)) < 0) { 
		fprintf(stderr, "Error opening heap file.\n");
		exit(EXIT_FAILURE);
	}
	
	//HP_GetAllEntries(heapFile, "all", "all");
	
	/* Open the file. */
	FILE *file = fopen(FILENAME_CSV, "r");
	
	if ( file ){
		while(fgets(buffer, sizeof buffer, file)){
			ptr = buffer;
			
			token = strtok(ptr, delim);
			long int converted_value = strtol( token, NULL, 10);
			if(errno != 0){
				perror("Problem Converting with strtol: ");
			}
			record.id = converted_value;
			token = strtok (NULL, delim);
			strncpy ( record.name, token, 15);
			token = strtok (NULL, delim);
			strncpy ( record.surname, token, 20);
			token = strtok (NULL, delim);
			strncpy ( record.city, token, 10);
			
			if (HP_InsertEntry(heapFile, record) < 0){ 
				fprintf(stderr, "Error inserting entry in heap file.\n");
			}
		}
		fclose(file);
	}
	else{
		perror(FILENAME_CSV);
	}
	
	//HP_GetAllEntries(heapFile, "all", "all");
	//HP_GetAllEntries(heapFile, "lathos", "all");
	
	/*SWITCH THESE 2 LINES WITH THE THIRD TO PASS ID AS A STRING*/
	//int id = 1875111;				
	//HP_GetAllEntries(heapFile, "id", &id);
	
	//HP_GetAllEntries(heapFile, "id", "1875111");
	
	HP_GetAllEntries(heapFile, "name", "Byron");
	//HP_GetAllEntries(heapFile, "surname", "Wolfman");
	//HP_GetAllEntries(heapFile, "city", "Thessaloniki");
	
	/* Close heap file */
	if (HP_CloseFile(heapFile) < 0) { 
		fprintf(stderr, "Error closing heap file.\n");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
