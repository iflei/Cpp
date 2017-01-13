#include <stdio.h>
#include <assert.h>

int SearchNum(int* arr, int size)
{
	assert(arr && size > 0);

	int i, k, j = 0;
	for(i = 0; i < size; ++i)
	{
		if(j == 0)
		  k = arr[i];

		if(k == arr[i])
		  ++j;
		else
		  --j;
	}
	return k;
}

int main()
{
	int arr[]={2,3,2,2,2,2,2,5,4,1,2,3};
	int ret = SearchNum(arr, sizeof(arr)/sizeof(int));
	printf("%d\n", ret);
	return 0;
}
