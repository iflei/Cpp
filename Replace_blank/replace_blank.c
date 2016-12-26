//替换空格
#include <assert.h>

void ReplaceBlank(char* str, int size)
{
	assert(str && size > 0);

	int i = 0;
	int len = 0; //字符串长度
	int blank = 0; //空格数
	//统计字符串长度和空格数
	while(str[i])
	{
		++len;
		if(str[i]==' ')
		  ++blank;

		++i;
	}

	int newLen = len + 2 * blank;
	if(newLen > size)
	  return;

	int endStr = len; //末尾的'\0'也要复制
	int endNew  = newLen;

	//endStr和endNew指向同一个位置，所有空格都替换完了
	while(endStr >= 0 && endNew > endStr)
	{
		if(str[endStr] == ' ')
		{
			str[endNew--] = '0';//endNew移动三步
			str[endNew--] = '2';
			str[endNew--] = '%';
		}
		else
		  str[endNew--] = str[endStr];//endNew移动一步

		--endStr; //endStr向前移动
	}

}
