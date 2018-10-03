/*
CHun Yue Leung
CSC152 HW2
Code: 9394
*/

#include <emmintrin.h>

void P52(unsigned int s[12]){
  int i, j;
  for (i = 0; i < 24; i++){
      __m128i vec[4];
      __m128i v1 = _mm_loadu_si128((__m128i *)s);
      __m128i v2 = _mm_loadu_si128((__m128i *)(s+4));
      __m128i v3 = _mm_loadu_si128((__m128i *)(s+8));
      __m128i v4 = _mm_loadu_si128((__m128i *)(s+12));
    // rotate left by 24
      v1 = _mm_xor_si128(_mm_srli_epi32(v1, 24), _mm_srai_epi32(v1, 8));    
      int x = (*(s+j) << 24)|(*(s+j) >> (32-24));
     
    // rotate left by 9
      int y = (*(s+4+j) << 9)|(*(s+4+j) >> (32-9));
     
      int z = *(s+8+j);
      *(s+8+j) = x^(z<<1)^((y&z)<<2);
      *(s+4+j) = y^x^((x|z)<<1);
      *(s+j) = z^y^((x&y)<<3);
    
    if (i % 4 == 0){
      int temp;
      
    // swap  
      temp = *s;
      *s = *(s+1);
      *(s+1) = temp;
    
    // swap  
      temp = *(s+2);
      *(s+2) = *(s+3);
      *(s+3) = temp; 

      *s = (*s) ^ 0x9e377900 ^ (24-i);
    } else if (i%4 == 2){
      int temp; 
      
     // swap  
      temp = *s;
      *s = *(s+2);
      *(s+2) = temp;
    
    // swap  
      temp = *(s+1);
      *(s+1) = *(s+3);
      *(s+3) = temp; 
    }
  }
}
