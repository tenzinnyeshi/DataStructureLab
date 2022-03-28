#include<stdio.h>
void insertionSort(int arr[], int n);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
void printArray(int array[], int size);
int main()
{
	int num,i,arr[100];
	int choice;
	printf(" Enter a number to set the limit for a random number \n");  
    scanf (" %d", &num);  
    for (i = 0; i <num; i++)  
    {  
		arr[i] = rand();
    }  
    printf("Before sorting \n");
    for(i=0;i<num;i++)
    {
    	printf("%d\t",arr[i]);
	}
	do{
		printf("\n1.Insertion sort:\n");
		printf("2.Quick sort:\n");
		printf("3.Display:\n");
		printf("4.Exit:\n");
		printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
        switch(choice)  
        {
        	case 1:
        		insertionSort(arr,num);
        		break;
        	case 2:
        		quickSort(arr, 0, num - 1);
        		break;
        	case 3:
        		printArray(arr,num);
        	case 4:
        		exit(0);
        	default:
        		printf("Invalid choice");
		}
	}while(choice!=4);
	
	
	
	return 0;
}
void insertionSort(int arr[], int n)
{
	int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];

  int i = (low - 1);
int j;

  for ( j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
	int i;
	printf("After sorting:\n");
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
