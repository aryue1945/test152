#include <stdio.h>

unsigned mult(unsigned a, unsigned b, unsigned modulus, unsigned degree);
void P52(unsigned int s[12]);


int main(){
  unsigned int s[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
  P52(s);
  int i;
  for (i = 0; i < 12; i++)
    printf("%08x\n", s[i]);
 printf("\nResult: %08x\n", mult(0x12,0xAA,0b100011011,8));
 printf("\nResult: %08x\n", mult(0x91,0x6A,0b100011011,8));
 printf("\nResult: %08x\n", mult(0x86,0xBE,0b100011011,8));
 printf("\nResult: %08x\n", mult(0xFF,0x1C,0b100011011,8));
 printf("\nResult: %08x\n", mult(0xAB,0x4A,0b100011011,8));
 printf("\nResult: %08x\n", mult(0x55,0x24,0b100011011,8));
 return 0;
}
