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
		printf("enter the element to be Searched");
		scanf("%d %d",&element);
     i=0;
		while(i<num && element != a[i] )
     {
    	 i++;
     }
		if(i< num)
		{
			printf("element found at %d",i+1);

		}
		else{
			printf("element not found");
		}
	return 0;
}
