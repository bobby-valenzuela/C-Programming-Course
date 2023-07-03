/*
A quick demo I thew together just to show that
*/

#include <stdio.h>
int main() {

    char name[]="";
    
    ///// Small text - 3chars
    printf("Size - Array Empty String: %zu\n",name);
    printf("Enter Text (3 chars): ");
    scanf("%s",name);
    printf("Text Entered: %s\n",name);
    printf("New Size: %zu\n",name);
    
    // Checking 3rd index
    printf("Checking value of Index 3 -> 4th char (Expecting Null Char): ") ;
    if(name[3] == '\0'){
        printf("FOUND NULL\n\n");
    }
    else{
        printf("DID NOT FIND NULL. Found this instead: %c \n\n",name[3]);
    }
    
    
    ///// Med Text - 10chars
    printf("Enter Longer Text (10 chars): ");
    scanf("%s",name);
    printf("Text Entered: %s\n",name);
    printf("New Size: %zu\n",name);
    
    // Checking 10th index
    printf("Checking value of Index 10 -> 11th char (Expecting Null Char): ") ;
    if(name[10] == '\0'){
        printf("FOUND NULL\n\n");
    }
    else{
        printf("DID NOT FIND NULL. Found this instead: %c \n\n",name[10]);
    }
    
    
    ///// Small Text - 3chars
    printf("Enter Small Text (3 chars): ");
    scanf("%s",name);
    printf("Text Entered: %s\n",name);
    printf("New Size: %zu\n",name);

    // Checking 3rd index
    printf("Checking value of Index 3 -> 4th char (Expecting Null Char): ") ;
    if(name[3] == '\0'){
        printf("FOUND NULL\n\n");
    }
    else{
        printf("DID NOT FIND NULL. Found this instead: %c \n\n",name[3]);
    }

    // Checking 3rd index
    printf("Q: Whats after null?\n") ;
    printf("Checking value of Index 4 -> 5th char (Expecting 5th char from last long text): ") ;
    if(name[4] == '\0'){
        printf("FOUND NULL\n\n");
    }
    else{
        printf("DID NOT FIND NULL. Found this instead: %c \n\n",name[4]);
    }

    // Checking last char of last string
    printf("Checking last char of last string -> Index 9 -> 10th char (Expecting last (10th) char from last long text): ") ;
    if(name[9] == '\0'){
        printf("FOUND NULL\n\n");
    }
    else{
        printf("DID NOT FIND NULL. Found this instead: %c \n\n",name[9]);
    }

    // Checking 10th index
    printf("Q: Is old null still there?\n") ;
    printf("Checking value of Index 10 -> 11th char (Expecting SegFault - last null should hahve been removed): ") ;
    if(name[10] == '\0'){
        printf("FOUND NULL\n");
    }
    else{
        printf("DID NOT FIND NULL. Found this instead: %c \n",name[10]);
    }
    
    
    return 0;
    
}
