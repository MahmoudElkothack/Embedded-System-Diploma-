#include<stdio.h>
int sumalldigit(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main(){
	int num;
	printf("enter num ");
	scanf("%d",&num);
	//sumalldigit(num);
	printf("%d",sumalldigit(num));
	return 0;
}
