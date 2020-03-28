
#include "utils.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// read string from the file
char* readStringFromFile(FILE* f) {
	char temp[100];
	fscanf(f, "%s", temp);
	return strdup(temp);
}

// get name of something from the user
char* getNameFromUser(char* nameOfWhat) {
	char temp[MAX_LENGTH];
	printf("Enter the name of the requested %s (max length = %d)\n", nameOfWhat,
	MAX_LENGTH);
	scanf("%s", temp);
	printf("\n");
	temp[strcspn(temp, "\n")] = '\0';
	return strdup(temp);
}

// clear the buffer
void clearBuffer() {
	while (getchar() != '\n') {
	}
}
