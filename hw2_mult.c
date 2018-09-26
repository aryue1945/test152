/*
CHun Yue Leung
CSC152 HW2
Code: 9394
*/

unsigned mult(unsigned a, unsigned b, unsigned modulus, unsigned degree){
	unsigned extra = 0;
	while(a != 0){
        /* remove the 1 term if a has a 1 term, extra then increase by b*/
		if (a&1){ 
			a = a^1;
			extra = extra^b;
		}
        
        /* divide a by x, multiply b by x */
		a = a >> 1;
		b = b << 1;
        
        /* reduce b by modulus if b has a degree term*/ 
		if ((b>>degree)&1) 
			b = b^modulus;
	}
	return extra;
}


