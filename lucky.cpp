#include<stdio.h>
#include<stdlib.h>

int main()
{
	int Array[9],i,j,temp,lucky=0,id;
	int count = 8;
	printf("請輸入身分證後九碼的數字:");
	scanf("%d",&id);
	while(count >= 0)
	{
		Array[count] = id % 10;
		id /= 10;
		count--;
	}
	for(i=0;i<=7;i++)
	{
		for(j=i;j<=8;j++)
		{
			if(Array[i]>Array[j])
			{
				temp=Array[i];
				Array[i]=Array[j];
				Array[j]=temp;
			}
		}
	}
	printf("由小到大:%d%d%d%d%d%d%d%d%d\n",Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7],Array[8]);
	for(i=0;i<=8;i++)
	{
		lucky+=Array[i]*i;
	}
	printf("幸運數字為:");
	for(i=0;i<=8;i++)
	{
		printf("(%d*%d)",Array[i],i);
		if(i<8)
		{
			printf("+");
		}
	}
	printf("=%d\n",lucky);
	
	system("pause");
	return 0;
} 
