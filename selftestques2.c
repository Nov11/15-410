#include <stdio.h>
int main()
{
	/*a*/
	printf("%p\n", (char*)((int)(0x100) - 8));//correct
	printf("%p\n", (char*)((char)(0x100) - 8));
	printf("%p\n", (char*)((char*)(0x100) - 4));
	printf("%p\n", (char*)((char*)(0x100) - 8));//correct
	/*e*/
	printf("%p\n", (char*)((int*)(0x100) - 4));
	printf("%p\n", (char*)((int*)(0x100) - 8));
	printf("%p\n", (char*)((char**)(0x100) - 8));
	printf("%p\n", (char*)((short*)(0x100) - 4));//correct
	/*i*/
	printf("%p\n", (char*)((short*)(0x100) - 8));
	
	return 0;
}
	
	