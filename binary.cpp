#include<stdio.h>
#include<stdlib.h>

int binary(int number[],int search,int n);

int main()
{
	int number[50],i,search,ans;
	//计皚 
	for(i=0;i<50;i++)
	{
		number[i]=2*i+1;
	}
	
	while(1)
	{
		printf("叫块璶碝т计:");
		scanf("%d",&search);
		if(search==-1)
		{
			break;
		}
		ans=binary(number,search,50);
		if(ans<0)
		{
			printf("тぃ计\n");
		}
		else
		{
			printf("计材%d竚\n",ans+1);
		}
	}
	
	system("pause");
	return 0;
}

//ノ癹伴籹binary search 
int binary(int number[],int search,int n)
{
	int high=n-1,low=0,mid;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(search==number[mid])
		{
			return mid;
		}
		else if(search>number[mid])
		{
			low=mid+1;
		}
		else if(search<number[mid])
		{
			high=mid-1;
		}
	}
	return -1;
} 
