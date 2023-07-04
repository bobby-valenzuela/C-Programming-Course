
#include <stdio.h>

int main() {
    
    // Print mem addr without pointer
    int age = 21;
    printf("MemAddr: %p\n",&age);  // -> MemAddr: 0x7ffc97a0bfe4

    // Print mem addr  with pointer
    int * agePtr = &age;
    printf("MemAddr: %p\n",agePtr); // -> MemAddr: 0x7ffc97a0bfe4
    
    // Print value from mem addr (0x15 = 21)
    printf("Value: %p\n",* &age);   // -> Value: 0x15
    printf("Value: %p\n",* agePtr); // -> Value: 0x15
    
    // Print value from mem addr (0x15 = 21)
    int ageFound = * &age;
    printf("Value: %d\n", ageFound); // -> Value: 21

    // Save val in var from mem addr
    int newAge = * &age;
    printf("Value: %d\n", newAge); // -> Value: 21

    // Changing val from mem addr
    * &newAge = * &newAge + 1;
    printf("Value: %d\n", newAge); // -> Value: 22

    return 0;
}
