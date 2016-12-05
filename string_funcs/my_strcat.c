#include <stdio.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);

	char* ret = dest;
	while(*dest) //dest指向0
	  dest++; 

	while(*dest++ = *src++)
	  ;

	return ret;
}

char* my_strncat(char* dest, const char* src, size_t count)
{
	assert(dest && src);

	char* ret = dest;
	while(*dest)
	  dest++;

	while(conut--)
	  *dest++ = *src++;

	*dest = '\0';
	return ret;
}

int main()
{
	char str[20] = "hello";
	char* p = " world";
	printf("%s\n", my_strcat(str, p));
	return 0;
}
