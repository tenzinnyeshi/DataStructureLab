/*
@uthor: TENZIN YESHI, 2147258, 3MCA B
DATA STRUCTURES LAB 4
Q2: Generate N students records as structure input and sort the record based on marks and then rollno/name in ascending order. Display the result in a neat tabulated format.
*/
#include<stdio.h>
void displayRecord();
void selectionSort();
void swap();
struct student
{
	char name[80];
	int rollno;
	int marks;
};
int main()
{
	struct student record[100];
	int i,n;
	printf("\n************Student Record************\n");
	printf("\nEnter number of students to store records: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of %d Student: \n",i+1);
		printf("Enter student name: ");
		scanf("%s",&record[i].name);
		printf("Enter student rollno: ");
		scanf("%d",&record[i].rollno);
		printf("Enter student marks: ");
		scanf("%d",&record[i].marks);
	}
	selectionSort(record, n);
	displayRecord(record,n);
	return 0;
}
void displayRecord(struct student record[], int n)
{
	int i;
	printf("\n***********Records After Sorting Based on marks*****************\n");
	printf("\n\t-----------------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\n\t| Name: %s | Rollno: %d | Marks: %d |\n",record[i].name,record[i].rollno,record[i].marks);
	}	
	printf("\t-----------------------------------------");
}
void selectionSort(struct student arr[], int n)
{
	int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].marks < arr[min_idx].marks)
            min_idx = j;
            
        swap(&arr[min_idx], &arr[i]);
    }
}


void swap(struct student a[], struct student b[]) 
{
  struct student t;
   t = *a;
  *a = *b;
  *b = t;
}
