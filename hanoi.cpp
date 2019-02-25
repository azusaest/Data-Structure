#include<stdio.h>
#include<stdlib.h>

int hanoi(int n,char buffer,char src,char dst)
{
	printf("hanoi(%d,%c,%c,%c)\n",n,buffer,src,dst);
	if(n==1)
	{
		printf("move disc from %c to %c\n",src,dst);
	}
	else
	{
		hanoi(n-1,dst,src,buffer);
		printf("move disc from %c to %c\n",src,dst);
		hanoi(n-1,src,buffer,dst);
	}
} 
int main()
{
	int n;
	printf("請輸入河內塔盤子的數量 : ");
	scanf("%d",&n);
	hanoi(n,'B','A','C');

	
	system("pause");
	return 0;
}
