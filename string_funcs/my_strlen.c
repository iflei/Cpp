#include <stdio.h>
#include <assert.h>

size_t my_strlen(const char* str)
{
	assert(str);

	int count = 0;
	while(*str++)
		count++;

	return count;
}

int my_strlen2(const char* str)
{
	assert(str);

	const char* p = str;
	while(*str)
	  str++;

	return str-p;
}

int main()
{
	printf("%d\n", my_strlen2("hello world!"));
	return 0;
}
