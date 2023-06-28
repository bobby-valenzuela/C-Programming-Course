#include <stdio.h>
#include <math.h>

int main(void){
    char letter;
    scanf("%c",&letter);

    int i;
    for(i=1; i<10; i=i+2){
        // how many cross to print at start
        int cross_count = floor((9 - i) / 2);
        int cross_num = 0;
        
        for(cross_num=0;cross_num<cross_count;cross_num++){
            printf("%c",'+');
        }
        
        
        // Print accepted chars
        int j;
        for(j=0; j<i; j++){
            printf("%c",letter);
            
        }
        
        // how many cross to print at end
        for(cross_num=0;cross_num<cross_count;cross_num++){
            printf("%c",'+');
        }
        
        printf("\n");
    }

    return 0;
    
}

/*


Write a C-program that reads an input character (using scanf) and displays the following pyramid pattern using the character read: 

Input
#
Output
++++#++++
+++###+++
++#####++
+#######+
#########


*/
