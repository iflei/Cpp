#include <stdio.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t size)
{
	assert(dest && src);

	void* ret = dest;
	char* p = (char*)dest;
	char* q = (char*)src;

	while(size--)
	  *p++ = *q++;

	return ret;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int num[5] = { 0 };
	my_memcpy(num, arr + 2, 16);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}
