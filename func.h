
#ifndef FUNC_H_
#define FUNC_H_

#include "types.h"

int readCity(City* city);
void showCityGardens(const City* city);
void showSpecificGardenInCity(const City* city);
int saveCity(const City* city);
int cityAddGarden(City* city);
int addChildToSpecificGardenInCity(City* city);
void birthdayToChild(City* city);
int countChova(const City* city);
void ReleaseCity(City* city);

#endif /* FUNC_H_ */
