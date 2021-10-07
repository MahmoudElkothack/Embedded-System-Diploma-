/*
 * main.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Mahmoud Elkot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DPRINTF(...)  { fflush(stdout);\
	                    fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}

//effective data
struct sdata{
	int ID;
	char name[20];
	float height;
};

struct sstudent{
	struct sdata student;
	struct sstudent* pNext;
};

struct sstudent* gpfirststudent=NULL;

void AddStudent(){
	//check if list is empty
	struct sstudent* newpstudent=NULL;
	struct sstudent* plastelement;
	char temp[20];
	if(gpfirststudent == NULL){
		//DPRINTF("first element\n");
         newpstudent = (struct sstudent*)malloc(sizeof(struct sstudent));
         gpfirststudent = newpstudent;
	}
	else{
		plastelement=gpfirststudent;
		while(plastelement->pNext){
			plastelement=plastelement->pNext;
		}
		 newpstudent = (struct sstudent*)malloc(sizeof(struct sstudent));
         plastelement->pNext=newpstudent;

	}
///FILL RECORD
	 DPRINTF("enter id");
	 gets(temp);
	 newpstudent->student.ID=atoi(temp);

	 DPRINTF("enter name");
		 gets(newpstudent->student.name);
	//	 newpstudent->student.ID=atoi(temp);


		 DPRINTF("enter height");
		 gets(temp);
		 newpstudent->student.height=atof(temp);

	  newpstudent->pNext=NULL;
}

int deletestudent(){
	char temp[20];
	int id;
	DPRINTF("enter id to delete");
	gets(temp);
	id=atoi(temp);
	if(gpfirststudent){
		struct sstudent* current=gpfirststudent;
		struct sstudent* pre=NULL;
		while(current){
        if(current->student.ID ==id){
        	if(pre)
        	{
            pre->pNext=current->pNext;
        	}else{  //first element
        		gpfirststudent=gpfirststudent->pNext;
        	}

        	free(current);
        	return 1;
        }
////////////////////loop to next node if not match id
        pre=current;
		current=current->pNext;
		}

	}

        DPRINTF("\nCan't find student id");

      return 0;

}


void viewstudent(){
  int count=0;
	struct sstudent* current=gpfirststudent;
	if(!gpfirststudent)
	{
        DPRINTF("\nlist is empty\n");

	}else{
		while(current){
		DPRINTF("\nrecord num:%d\n",count+1);
		DPRINTF("id=%d\n",current->student.ID);
		DPRINTF("name=%s\n",current->student.name);
		DPRINTF("height=%f\n",current->student.height);
		current=current->pNext;
		count++;
		}
	}
}

void delete_all(){

		struct sstudent* current = gpfirststudent;
		if(!gpfirststudent)
		{
	        DPRINTF("list is empty");
		}else{
			while(current){
				struct sstudent* temp = current;
			current=current->pNext;
			free(temp);
			}
			gpfirststudent=NULL;
		}




}


int get_elementbyindex(int index){
	int count=0;
	struct sstudent* temp;
	if(!gpfirststudent){ //empty
		DPRINTF("\nempty list\n");
	    return 0;
	}
	else{
		temp=gpfirststudent;
		//count++;
		while(temp){
			if(count == index)
			{DPRINTF("id=%d\n",temp->student.ID);
			DPRINTF("name=%s\n",temp->student.name);
			DPRINTF("height=%f\n",temp->student.height);

			return 0;
			}
			temp=temp->pNext;
		     count++;
		}


	}
   printf("\nwrong index\n");
 return 0;
	}

int get_listcount(){
	int count=0;
	struct sstudent*temp=gpfirststudent;
	//check if global is null
	if(!gpfirststudent)  //null
	{
		printf("empty list");
	//return 0;
	}else{
		//count++;
		while(temp)
		{
			count++;
			temp = temp->pNext;

		}
		printf("count=%d\n",count);
	  //  return count;
	}
	return count;
}

int get_listcount_by_recursive(struct sstudent*temp){
	int count=0;
	//struct sstudent*temp=gpfirststudent;
	//check if global is null
	if(!temp)  //null
		return 0;
	else{
	return 1+ get_listcount_by_recursive(temp->pNext);

	}
}

void get_element_from_last(){
	char temp[10];
    struct sstudent* current=gpfirststudent;
    struct sstudent*  pre=gpfirststudent;
    //pre,current=gpfirststudent;

    DPRINTF("pls enter index\n");
    gets(temp);
   int val= atoi(temp);
   if(!gpfirststudent) //null
   {
	   DPRINTF("empty list");
	   return;
   }
   else{
	   while(--val){  ///

		   current=current->pNext;
		   if(!current) //null
		   {
			  DPRINTF("error not suffcient index");
	           return;
		   }
		}
	   // we have  set the distance equal the val between them
     //now we get index from last element
	 while(current->pNext)
    {
    	current=current->pNext;
    	pre=pre->pNext;
    }


	 DPRINTF("====================");
	 DPRINTF("\nID:%d\n",pre->student.ID);
	 DPRINTF("name:%s\n",pre->student.name);
	 DPRINTF("height:%f\n",pre->student.height);
	 DPRINTF("====================");

   }

}

//get middle element of linked list
/*use fast pointer slow pointer
 * mean fast increment by 2
 *    increment slow by 1
 */
void get_middle_element(){
	struct sstudent* slow=gpfirststudent;
	struct sstudent* fast=gpfirststudent;
	if(!gpfirststudent) ///
	{
		DPRINTF("empty list");
		return;
	}
	else{

	while(fast->pNext){
		fast=fast->pNext->pNext;
		slow=slow->pNext;
	}
	     DPRINTF("====================");
		 DPRINTF("\nID:%d\n",  slow->student.ID);
		 DPRINTF("name:%s\n",  slow->student.name);
		 DPRINTF("height:%f\n",slow->student.height);
		 DPRINTF("====================");
}


}


/*
 * reverse linked list
 */

void reverse_linked_list(){
	struct sstudent* current=gpfirststudent;
	//struct sstudent* pre=gpfirststudent;
   int count = get_listcount();
	int i;
	DPRINTF("====================");
   while(--count)
    {
	   struct sstudent* current=gpfirststudent;  //every outer loop init to first element
    	for(i=1;i<=count;i++)
    	{
    		current=current->pNext;
    	}
    	 //DPRINTF("====================");
    	 DPRINTF("\nID:%d\n",  current->student.ID);
    	 DPRINTF("name:%s\n",  current->student.name);
    	 DPRINTF("height:%f\n\n",current->student.height);
    	 //DPRINTF("====================");

    }
   ///print the first node here
         //DPRINTF("====================");
      	 DPRINTF("\nID:%d\n",  current->student.ID);
      	 DPRINTF("name:%s\n",  current->student.name);
      	 DPRINTF("height:%f\n",current->student.height);
      	 DPRINTF("====================");

}







int main(){
char temp[20];
char index[10];
while(1){
	   DPRINTF("\n===============================\n");
   DPRINTF("\n        select one from option\n\n");
   DPRINTF("1.Add student\n");
   DPRINTF("2.delete student\n");
   DPRINTF("3.view student\n");
   DPRINTF("4.delete all students\n");
   DPRINTF("5.get by index\n");
   DPRINTF("6.get list count\n");
   DPRINTF("7.list count by recursive\n");
   DPRINTF("8.get element from last by index\n");
   DPRINTF("9.get middle element\n");
   DPRINTF("10.reverse linked list\n");
gets(temp);
switch(atoi(temp)){
case 1:
	AddStudent();
	break;
case 2:
	deletestudent();
	break;
case 3:
	viewstudent();
	break;
case 4:
	delete_all();
	break;
case 5:
	DPRINTF("\nPLS enter index");
	gets(index);
	get_elementbyindex(atoi(index));
	break;
case 6:
	get_listcount();
	break;
case 7:
	//int count = get_listcount_by_recursive(gpfirststudent);
    DPRINTF("COUNT=%d",get_listcount_by_recursive(gpfirststudent));
	break;
case 8:
	get_element_from_last();
   break;
case 9:
	//get_element_from_last();
   get_middle_element();
	break;
case 10:
	reverse_linked_list();
   break;
default:
	DPRINTF("\nwrong option\n");
    }
}
    return 0;

}





















