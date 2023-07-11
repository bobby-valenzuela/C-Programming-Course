#include <stdio.h>

struct student{
	char firstName[30];
	int birthYear;
};
// function prototypes
void printStudent(struct student);
void readStudent(struct student *studptr);
int main(void) {
    // Creating an instance - but not defining it
    struct student me;

    // Define the instance here via user input)
    readStudent(&me);

    // Printing defined student instance
    printStudent(me);
	return 0;
}

// Define
void readStudent(struct student *studptr) {
    printf("First name: ");
    scanf("%s", (*studptr).firstName);
    // ^ scanf does no require adding an ampersamd for strings (chr arrays)
    // also, notice how we nee to dereference the struct with (*struct)
  
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear);
    // ^ scanf requires adding an ampersamd for ints 
}

// Print
void printStudent(struct student stud) {
    printf("Name: %s \n", stud.firstName);
	printf("Year of birth: %d\n",stud.birthYear);
}
