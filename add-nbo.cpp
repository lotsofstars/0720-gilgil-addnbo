#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <iomanip>
#include <stdlib.h>
#include <string>

char len;

int main(int argc, char *argv[]) {
	if (argc > 3)
	{
		printf("2개만 입력하시오.\n");
		return 0;
	}
		if (argc < 3)
	{
		printf("2개 입력 하시오.\n");
		return 0;
	}


	FILE    *firstfile;
	FILE    *secondfile;

	firstfile = fopen(argv[1], "rb");
	secondfile = fopen(argv[2], "rb");

	char str[50];
	uint8_t first_buffer[4];
	fread(first_buffer ,1, 4, firstfile);
	fclose(firstfile);

	uint8_t second_buffer[4];
	fread(second_buffer ,1, 4, secondfile);
	fclose(secondfile);

	uint32_t* p1 = reinterpret_cast<uint32_t*>(first_buffer);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(second_buffer);
	uint32_t n = *p1 + *p2; // TODO
	printf("The result is %d\n", n);
}
