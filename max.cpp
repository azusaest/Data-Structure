#include<stdio.h>

int max(int *iptr[],int n);

int main(void)
{
	int i;
	int array[10];
	int *iptr[10];
	
	printf("�п�J10�ӼƦr : ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&array[i]);
		iptr[i]=&array[i];
	}
	
	printf("%d\n",max(iptr,10));
	return 0;
}

int max(int *iptr[],int n)
{
	int i,max1;
	max1=*iptr[0];
	for(i=0;i<n-1;i++)
	{
		if(*iptr[i]>max1)
		{
			max1=*iptr[i];
		}
	}
	return max1;
}
