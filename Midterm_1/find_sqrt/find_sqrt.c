/********
AUTHOR:Mahmoud ALI Elkot
*************/
#include<stdio.h>
#include<math.h>
double findsqart(double num){

	return sqrt(num);


}
int main(){
	int num;
	printf("enter num to find sqrt\n");
	scanf("%d",&num);
	printf("%lf",findsqart(num));
}
