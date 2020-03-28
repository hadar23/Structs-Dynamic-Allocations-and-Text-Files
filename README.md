# Structs-Dynamic-Allocations-and-Text-Files
Structs, Dynamic Allocations and Text Files - second year first semester's third C project

In this project we wrote a program that runs kindergartens in the city of Oz. 

There are several types of kindergartens: 
1) compulsory
2) pre-compulsory
3) pre-pre-compulsory

A **child structure** in the kindergarten contains the fields: 
1) ID - integer
2) age - integer

**Kindergarten structure** contains the fields: 
1) Kindergarten name - string of unknown length (one word can be assumed)
2) Kindergarten type - compulsory, pre-compulsory or pre-pre-compulsory
3) array of pointers for kindergarten children of unknown size
4) number of children - integer

**City structure**: 
1) Collection of kindergartens in the city
2) number of kindergartens - integer

The program is displaying a **menu** that allows the following actions until an exit option is selected.

1. Initialize kindergarten data in the city - Read all the data for all the kindergartens from a text file (The file format is given below).
2. Display city data to the screen.
3. Display specific kindergarten data for the screen. The user will give the kindergarten name.
4. Save - Write city data into a text file.
5. Add a kindergarten. Make sure the gene doesn't already exist.
6. Adding a child to the kindergarten. The user will give the kindergarten name. Make sure the child is not already registered (By ID).
7. Adding a year to the age of a particular child, in a particular kindergarten.
8. Return the total number of children in all compulsory kindergartens. (First grade assessments for the city)
0. Exit

Selecting from the menu will cause the requested activity, and then display the menu again, until you exit.
Files and functions are divided, so that for each structure and substructure there are an appropriate boot and print functions.

## File Format

First row: The number of kindergartens.  
Then For each kindergarten;  
First row: Kindergarten's name, Kindergarten's type, number of children.  
Then a row for each child: Child's ID, Child's age.

Example:

![image](https://raw.githubusercontent.com/aviasd/Structs-Dynamic-Allocations-and-Text-Files/master/README%20files/file%20format%20city.png)
