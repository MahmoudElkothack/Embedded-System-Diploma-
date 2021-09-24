#include<stdio.h>
#include<string.h>
int main(){
char str[1000],ch;
int i,count=0;
printf("enter string \n");

gets(str);
printf("enter ch to find fre\n");
scanf("%c",&ch);
for(i=0;str[i]!='\0';i++){
	if(str[i]==ch)
		count++;

}
printf("fre=%d",count);

	/*char str[]="hi";
	printf("len=%d",strlen(str));
*/
	return 0;
}
