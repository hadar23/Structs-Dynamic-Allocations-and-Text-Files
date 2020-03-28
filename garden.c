
#include <stdlib.h>
#include <string.h>
#include "garden.h"
#include "utils.h"
#include "child.h"

const char* gardenTypeArr[NoOfTypes] = { "Kindergarten", "Pre Kindergarten",
		"Pre Pre Kindergarten" };

// initial a garden, but first check if it already exists in the city
Garden* initGardenForCity(const City* city) {
	Garden* garden = NULL;
	char* name = '\0';

	name = getNameFromUser("garden");
	if (findGardenInCity(city, name) >= 0) {
		printf("The garden already exist in the city\n");
		free(name);
		return NULL;
	}

	garden = (Garden*) malloc(sizeof(Garden));
	if (!garden) {
		free(name);
		return NULL;
	}

	garden->name = name;
	garden->type = getTypeOfGardenFromUser();
	garden->children = NULL;
	garden->numOfChildren = 0;
	return garden;
}

// get type of garden from the user
gardenType getTypeOfGardenFromUser() {
	int i = 0, type = -1;
	boolean goodType = FALSE;
	do {
		printf("Enter type of kindergarten\n");
		for (i = 0; i <= PRE_PRE_KINDERGARTEN; i++)
			printf("%d for %s\n", i, gardenTypeArr[i]);
		scanf("%d", &type);
		clearBuffer();
		if (type < 0 || NoOfTypes <= type)
			printf("Wrong type\n");
		else
			goodType = TRUE;
	} while (!goodType);
	return (gardenType) type;

}

// find a garden in the city
int findGardenInCity(const City* city, const char* name) {
	int i = 0, numOfGardens = 0;
	numOfGardens = city->numOfGardens;

	for (i = 0; i < numOfGardens; i++)
		if (strcasecmp(name, city->gardens[i]->name) == 0)
			return i;

	return -1;
}

// print the garden to the screen
void printGardenToScreen(const Garden* garden) {
	Child** children = NULL;
	int numOfChildren = 0, i = 0;

	numOfChildren = garden->numOfChildren;
	children = garden->children;

	printf("\nGarden name: %s,\t Garden type: %s,\t Number of children: %d\n",
			garden->name, gardenTypeArr[garden->type], numOfChildren);
	for (i = 0; i < numOfChildren; i++) {
		printChildToScreen(children[i]);
	}
}

// print the garden to the file
void printGardenToFile(FILE* f, const Garden* garden) {
	Child** children = NULL;
	int numOfChildren = 0, i = 0;

	numOfChildren = garden->numOfChildren;
	children = garden->children;

	fprintf(f, "%s\t%d %d\n", garden->name, garden->type, numOfChildren);
	for (i = 0; i < numOfChildren; i++) {
		printChildToFile(f, children[i]);
	}
}

// read garden from the file
Garden* readGardenFromFile(FILE* f) {
	int numOfChildren = 0, i = 0;
	Garden* garden = NULL;

	garden = (Garden*) malloc(sizeof(Garden));
	if (!garden)
		return NULL;

	garden->name = readStringFromFile(f);
	if (!garden->name) {
		free(garden);
		return NULL;
	}

	fscanf(f, "%u %d", &(garden->type), &(garden->numOfChildren));

	numOfChildren = garden->numOfChildren;

	garden->children = (Child**) malloc(sizeof(Child) * numOfChildren);
	if (!garden->children) {
		free(garden->name);
		free(garden);
		return NULL;
	}

	for (i = 0; i < numOfChildren; i++) {
		garden->children[i] = readChildFromFile(f);
	}
	return garden;
}

// release the dynamic space of the garden
void releaseGarden(Garden* garden) {
	int i = 0, numOfChildren = 0;
	for (i = 0; i < numOfChildren; i++) {
		free(garden->children[i]);
	}
	free(garden->children);
	free(garden->name);
	free(garden);
}
