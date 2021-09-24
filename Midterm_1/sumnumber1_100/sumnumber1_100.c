/********
AUTHOR:Mahmoud ALI Elkot
*************/
#include <stdio.h>
void sum1_100(){
	static int i=0;
	static int sum =0;
	if(i>100)
	{
		printf("%d\n",sum);
	//	return 0;
	}
		else{
		sum+=i;
	     i++;
		sum1_100();
	}
return 0;
}
/*void sum(int n){

	printf("%d\n",n*(n+1)/2);
}*/
int main() {

//sum(100);
sum1_100();
   return 0;
}
