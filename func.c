
#ifndef FUNC_C_
#define FUNC_C_

#include <stdlib.h>
#include "func.h"
#include "utils.h"
#include "child.h"
#include "garden.h"

// read city from file
int readCity(City* city) {
	FILE* f = NULL;
	Garden** gardens = NULL;
	int numOfGardens = 0, i = 0;
	char* fileName = '\0';

	fileName = getNameFromUser("file");
	f = fopen(fileName, "r");
	free(fileName);
	if (!f) {
		printf("The file does not exist\n");
		return 0;
	}
	if (city->numOfGardens > 0)
		ReleaseCity(city);

	fscanf(f, "%d", &(city->numOfGardens));
	numOfGardens = city->numOfGardens;

	gardens = (Garden**) malloc(sizeof(Garden*) * numOfGardens);
	if (!gardens) {
		fclose(f);
		return 0;
	}

	city->gardens = gardens;

	for (i = 0; i < numOfGardens; i++)
		city->gardens[i] = readGardenFromFile(f);

	fclose(f);
	return 1;
}

// show the gardens in the city
void showCityGardens(const City* city) {
	int i = 0, numOfGardens = 0;

	printf("These are the city's details:\n");
	numOfGardens = city->numOfGardens;
	printf("\nNumber of gardens: %d\n", numOfGardens);

	for (i = 0; i < numOfGardens; i++) {
		printGardenToScreen(city->gardens[i]);
	}
}

void showSpecificGardenInCity(const City* city) {
	int place = -1;
	char* gardenName = "\0";

	gardenName = getNameFromUser("garden");
	place = findGardenInCity(city, gardenName);
	free(gardenName);

	if (place < 0) {
		printf("The requested garden does not exist in the city\n");
	} else {
		printf("These are the requested garden's details:\n");
		printGardenToScreen(city->gardens[place]);
	}

}

// save the city to a file
int saveCity(const City* city) {
	FILE* f = NULL;
	char* fileName = '\0';
	int numOfGardens = 0, i = 0;

	fileName = getNameFromUser("file");
	f = fopen(fileName, "w");
	free(fileName);
	if (!f)
		return 0;

	numOfGardens = city->numOfGardens;
	fprintf(f, "%d\n", numOfGardens);

	for (i = 0; i < numOfGardens; i++)
		printGardenToFile(f, city->gardens[i]);

	fclose(f);
	return 1;
}

// add garden to the city
int cityAddGarden(City* city) {
	int numOfGardens = 0;
	Garden** gardens = NULL;
	Garden* garden = NULL;

	garden = initGardenForCity(city);
	if (!garden) {
		return 0;
	}

	numOfGardens = city->numOfGardens;
	gardens = (Garden**) realloc(city->gardens, numOfGardens + 1);
	if (!gardens) {
		free(garden->name);
		free(garden);
		return 0;
	}

	gardens[numOfGardens] = garden;
	city->gardens = gardens;
	(city->numOfGardens)++;

	printf("The garden has been added succssfully\n");
	return 1;
}

// add child to a garden
int addChildToSpecificGardenInCity(City* city) {
	int numOfChildren = 0, place = -1;
	char* gardenName;
	Child** children = NULL;
	Child* child = NULL;

	gardenName = getNameFromUser("garden");
	place = findGardenInCity(city, gardenName);
	free(gardenName);

	if (place < 0) {
		printf("The garden does not exist in the city\n");
		return 0;
	}

	numOfChildren = city->gardens[place]->numOfChildren;
	children = (Child**) realloc(city->gardens[place]->children,
			numOfChildren + 1);
	if (!children) {
		return 0;
	}

	child = initChildForCity(city);
	if (!child) {
		return 0;
	}

	children[numOfChildren] = child;
	city->gardens[place]->children = children;
	(city->gardens[place]->numOfChildren)++;

	printf("The child has been added succssfully\n");
	return 1;
}

// add 1 year to child
void birthdayToChild(City* city) {
	char* nameOfGarden = "\0";
	int placeOfChild = -1, placeOfGarden = -1, id = 0;

	nameOfGarden = getNameFromUser("garden");
	placeOfGarden = findGardenInCity(city, nameOfGarden);
	free(nameOfGarden);

	if (placeOfGarden < 0) {
		printf("The garden does not exist in the city\n");
		return;
	}

	id = getIdOfChildFromUser();
	placeOfChild = findChildInGarden(city->gardens[placeOfGarden], id);
	if (placeOfChild < 0) {
		printf("The child does not exist in the garden\n");
		return;
	}

	(city->gardens[placeOfGarden]->children[placeOfChild]->age)++;
	printf("One year has been added succssfully\n");
}

// count the number of children in Kindergarten
int countChova(const City* city) {
	int i = 0, numOfGardens = 0, counterOfChildren = 0;
	numOfGardens = city->numOfGardens;
	for (i = 0; i < numOfGardens; i++)
		if (city->gardens[i]->type == KINDERGARTEN)
			counterOfChildren += city->gardens[i]->numOfChildren;
	return counterOfChildren;
}

// release the dynamic space of the city
void ReleaseCity(City* city) {
	int i = 0, numOfGardens = 0;
	numOfGardens = city->numOfGardens;

	for (i = 0; i < numOfGardens; i++) {
		releaseGarden(city->gardens[i]);
	}
	free(city->gardens);
	city->numOfGardens = 0;

	printf("City has been released succssfully\n");
}

#endif /* FUNC_C_ */
