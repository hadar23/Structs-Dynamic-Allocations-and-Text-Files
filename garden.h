
#ifndef GARDEN_H_
#define GARDEN_H_

#include "types.h"
#include <stdio.h>

const char* gardenTypeArr[NoOfTypes];

Garden* initGardenForCity(const City* city);
gardenType getTypeOfGardenFromUser();
int findGardenInCity(const City* city, const char* name);
void printGardenToScreen(const Garden* garden);
void printGardenToFile(FILE* f, const Garden* garden);
Garden* readGardenFromFile(FILE* f);
void releaseGarden(Garden* garden);


#endif /* GARDEN_H_ */
