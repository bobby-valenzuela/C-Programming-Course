#include <stdio.h>
#include <limits.h>

int main (void){


    printf("[Short Int]\t\t Size: \t%4d bytes\t%d to %d\n", sizeof(short int) , SHRT_MIN, SHRT_MAX);
    printf("[Short Int-Unsigned]\t Size: \t%4d bytes\t%d to %d\n", sizeof(unsigned short int) , 0, USHRT_MAX);
    printf("[Long Int]\t\t Size: \t%4d bytes\n", sizeof(long int) );
    printf("[Long Int-Unsigned]\t Size: \t%4d bytes\n", sizeof(unsigned long int) );
    printf("[char]\t\t\t Size: \t%4d bytes\n", sizeof( char ) );
    printf("[float]\t\t\t Size: \t%4d bytes\n", sizeof( float ) );
    printf("[double]\t\t Size: \t%4d bytes\n", sizeof( double ) );


    return 0;
}

// OUTPUT
// [Short Int]              Size:     2 bytes      -32768 to 32767
// [Short Int-Unsigned]     Size:     2 bytes      0 to 65535
// [Long Int]               Size:     8 bytes
// [Long Int-Unsigned]      Size:     8 bytes
// [char]                   Size:     1 bytes
// [float]                  Size:     4 bytes
// [double]                 Size:     8 bytes
