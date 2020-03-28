
#include <stdlib.h>
#include "child.h"
#include "utils.h"

// initial a child, but first check if it already exists in the city
Child* initChildForCity(const City* city) {
	Child* child = NULL;
	int id = 0, age = 0, placeOfGarden = -1;

	id = getIdOfChildFromUser();

	placeOfGarden = findChildInCity(city, id);
	if (placeOfGarden >= 0) {
		printf("The child already exist in the city in garden %s\n",
				city->gardens[placeOfGarden]->name);
		return NULL;
	}

	child = (Child*) malloc(sizeof(Child));
	if (!child)
		return NULL;

	child->id = id;

	while (age <= 0) {
		printf("Enter the age of the child\n");
		scanf("%d", &age);
		clearBuffer();
		if (age <= 0)
			printf("Wrong age\n");
	}
	child->age = age;

	return child;
}

// get id of child from the user
int getIdOfChildFromUser() {
	int id = 0;
	boolean goodId = FALSE;
	do {
		printf("Enter the id of the child\n");
		scanf("%d", &id);
		clearBuffer();
		if (id <= 0)
			printf("Wrong id\n");
		else
			goodId = TRUE;
	} while (!goodId);
	return id;
}

// find child in the city
int findChildInCity(const City* city, int id) {
	int i, numOfGardens;
	numOfGardens = city->numOfGardens;

	for (i = 0; i < numOfGardens; i++)
		if (!(findChildInGarden(city->gardens[i], id) < 0))
			return i;

	return -1;
}

// find child in the garden
int findChildInGarden(const Garden* garden, int id) {
	int i, numOfChildren;
	numOfChildren = garden->numOfChildren;

	for (i = 0; i < numOfChildren; i++)
		if (id == garden->children[i]->id)
			return i;

	return -1;
}

// print child to the screen
void printChildToScreen(const Child* child) {
	printf("Child ID: %d,\t Child age: %d\n", child->id, child->age);
}

// print child to the file
void printChildToFile(FILE* f, const Child* child) {
	fprintf(f, "%d %d\n", child->id, child->age);
}

// read child from the file
Child* readChildFromFile(FILE* f) {
	Child* child = NULL;

	child = (Child*) malloc(sizeof(Child));
	if (!child)
		return NULL;

	fscanf(f, "%d %d", &(child->id), &(child->age));
	return child;
}
