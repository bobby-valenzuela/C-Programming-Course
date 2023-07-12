#include <stdio.h>

struct node{
    int studentID;
    char * name[20];
    // Pointer to next node in list
    struct node * next;
};

int main(void) {
    //! showMemory(start=65520)
    
    // First node
    char student1Name[11] = { 'J','i','m','o','t','h','y',' ','H','.','\0' };
    struct node student1 = { 1, student1Name, NULL};

    // Second node    
    char student2Name[7] = { 'P','a','m',' ','B','.','\0' };
    struct node student2 = { 33, student2Name, NULL};
    
    // Third node
    char student3Name[8] = { 'M','.','S','c','o','t','t','\0' };
    struct node student3 = { 35, student3Name, NULL};
    
    // Create current pointer
    struct node * current;
    
    // Manually set/define "next" pointers
    current = &student1;
    current->next = &student2;
    current->next->next = &student3;
    
    // Loop through all nodes
    while (current!=NULL) {
        printf("(StudentID: %d, Name: %s)\n", current->studentID, *(current->name));
        current = current->next;
    }
    /*
        The above prints:
        (StudentID: 1, Name: Jimothy H.)
        (StudentID: 33, Name: Pam B.)
        (StudentID: 35, Name: M.Scott)
    */
	return 0;
}
