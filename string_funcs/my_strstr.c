#include <stdio.h>
#include <assert.h>

const char* my_strstr(const char* str, const char* sub)
{
	assert(str && sub);
	const char* ret = NULL;
	const char* start = str;
	const char* p1 = start;
	const char* p2 = sub;

	while(*start)
	{
		ret = start;
		while(*p1++ == *p2++)
			if(*p2 == '\0')
				return ret;

		start++; //解决子问题
		p1 = start;
		p2 = sub;
	}

	return NULL;
}


const char* my_strstr2(const char* str, const char* sub)
{
	assert(str && sub);
	const char* start = str;
	const char* p1 = NULL;
	const char* p2 = NULL;

	while(*start)
	{
		p1 = start;
		p2 = sub;
		while(*p1 && *p1 == *p2)
		{
			p1++;
			p2++;
			if(*p2 == '\0')
			  return start;
		}
		start++;
	}
	return NULL;
}

int main()
{
	const char* str = "ABCBCEBCHBCDP";
	const char* sub = "BCD";
	printf("%s\n", my_strstr2(str, sub));
	return 0;
}
