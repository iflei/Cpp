#include <stdio.h>

char SecondNotRepeatChar(char* str)
{
	if(str == NULL)
	  return 0;

	int i = 0;
	int hashTable[256];
	for(i = 0; i < 256; ++i)
		hashTable[i] = 0;

	char* hashKey = str;
	while(*hashKey != '\0')
	  hashTable[*(hashKey++)]++;

	hashKey = str;
	while(*hashKey != '\0')
	{
		if(hashTable[*hashKey] == 2)
		  return *hashKey;

		hashKey++;
	}
	return 0;
}

int main()
{
	char* str = "abcdefabcdefabc";
	printf("%c\n", SecondNotRepeatChar(str));
	return 0;
}
