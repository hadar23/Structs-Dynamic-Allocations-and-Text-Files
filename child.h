
#ifndef CHILD_H_
#define CHILD_H_

#include <stdio.h>
#include "types.h"

Child* initChildForCity(const City* city);
int getIdOfChildFromUser();
int findChildInCity(const City* city, int id);
int findChildInGarden(const Garden* garden, int id);
void printChildToScreen(const Child* child);
void printChildToFile(FILE* f, const Child* child);
Child* readChildFromFile(FILE* f);

#endif /* CHILD_H_ */
