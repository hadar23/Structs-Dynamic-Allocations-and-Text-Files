
#include "func.h"
#include <stdlib.h>

typedef enum {
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	EXIT
} choice;

// print the menu
void printMenu() {
	printf("\n\n");
	printf("Please choose one of the following options\n");
	printf("%d - Read city from file\n", READ_CITY);
	printf("%d - Print city to screen\n", SHOW_CITY);
	printf("%d - Print garden to screen\n", SHOW_GARDEN);
	printf("%d - Print city to File\n", WRITE_CITY);
	printf("%d - Add garden to city\n", ADD_GARDEN);
	printf("%d - Add child to garden\n", ADD_CHILD);
	printf("%d - Add year to child\n", CHILD_BIRTHDAY);
	printf("%d - Count children in kindergarten\n", COUNT_GRADUATE);
	printf("%d - Exit\n", EXIT);
}

// get the choice of the user
int menu() {
	int option;
	boolean goodOption = FALSE;
	option = -1;
	do {
		printMenu();
		scanf("%d", &option);
		clearBuffer();
		if (option < READ_CITY || EXIT < option)
			printf("Wrong option\n");
		else
			goodOption = TRUE;
	} while (!goodOption);
	printf("\n");
	return option;
}

// main function
int main() {
	City utz = { NULL, 0 };
	int uReq;

//first time read
	readCity(&utz);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY:
			readCity(&utz);
			break;

		case SHOW_CITY:
			showCityGardens(&utz);
			break;

		case SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY:
			saveCity(&utz);
			break;

		case ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",
					countChova(&utz));
			break;

		}
	} while (uReq != EXIT);

	ReleaseCity(&utz); //free all allocations

	return 1;
}
