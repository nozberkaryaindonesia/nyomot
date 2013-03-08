//Written by Jiri P

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

main()
{
unsigned char z;
while(1==read(fileno(stdin),&z,1))
  {
	z = ~z;
	//reverse bit order
	uint32_t  b=z;
	b = ((b * 0x0802LU & 0x22110LU) | (b * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;
	z = b;
	if(z==0xa0) printf("\n");
	printf("%02x ",z);
	fflush(stdout);
	}
}
