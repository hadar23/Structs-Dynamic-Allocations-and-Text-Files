
#ifndef TYPES_H_
#define TYPES_H_

typedef enum {
	FALSE, TRUE
} boolean;

typedef enum {
	KINDERGARTEN, PRE_KINDERGARTEN, PRE_PRE_KINDERGARTEN, NoOfTypes
} gardenType;

typedef struct {
	int id;
	int age;
} Child;

typedef struct {
	char* name;
	gardenType type;
	Child** children;
	int numOfChildren;

} Garden;

typedef struct {
	Garden** gardens;
	int numOfGardens;
} City;

#endif /* TYPES_H_ */
