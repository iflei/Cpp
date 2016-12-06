#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while(*dest++ = *src++);
	return ret;
}

int main()
{
	char* p = "hello";
	char arr[10];
	printf("%s\n", my_strcpy(arr, p));
	return 0;
}
