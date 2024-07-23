#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]){
	if (argc != 3) {
	printf("error, 3 < object or 3 > object");
	return -1;
	}


	FILE *f1 = fopen(argv[1], "rb");

	FILE *f2 = fopen(argv[2], "rb");
	
	unsigned char buffer1[4];
	unsigned char buffer2[4];
	size_t size;
	size = fread(buffer1, 1, 4, f1);
	if (size != 4){
		printf("16 binary size > 4 or < 4");
		return -1;
	}	
	size = fread(buffer2, 1, 4, f2);
	if (size!= 4){
		printf("16 binary size > 4 or < 4");
		return -1;
	}
	uint32_t a = 0;
	int b = 24;
	uint32_t c = 0;
	uint32_t d = 0;
	for (int i = 0; i<4; i++) {
		a += buffer1[i] << b;
		c += buffer2[i] << b;
		b -= 8;

	}		

	d = a + c;

	printf("\n %u(0x%x) + %u (0x%x) = %u(0x%x) ",a,a,c,c,d,d);

	fclose(f1);
	fclose(f2);	
		

		
	return 0;		
}
