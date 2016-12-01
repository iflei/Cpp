#include <stdio.h>
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t size)
{
	assert(dest && src);
	void* ret = dest;
	char* d = (char*)dest;
	char* s = (char*)src;
	//内存重叠
	if((d > s) && (d < s + size))
	  while(size--)
		*(d+size) = *(s+size);
	else
	  while(size--)
		*d++ = *s++;

	return ret;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	my_memmove(arr + 5, arr + 2, 16);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
