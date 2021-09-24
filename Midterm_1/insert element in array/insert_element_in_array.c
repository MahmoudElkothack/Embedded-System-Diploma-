#include<stdio.h>
int main(){
	int a[20];
	int element ,loc,num,i;
	printf("enter num of elements");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);

	}
	printf("enter the element to be inserted and location");
	scanf("%d %d",&element,&loc);
	for(i =num;i>=loc;i--)
	{
		a[i]=a[i-1];
	}
	num++;
   a[loc-1]=element;
	for(i=0;i<num;i++){
		printf("%d ",a[i]);

	}
   return 0;
}
