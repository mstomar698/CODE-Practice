//BUBBLE SORT/

#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>
#include<dos.h>
#include<time.h>
int main()
{
 clock_t start,end;

 int i,n,j,temp,k;
 printf("\nEnter No of elements in the array:");
 scanf("%d",&n);
 start = clock();
 int *p=(int*) malloc(n*sizeof(int));
 printf("Enter the elements of array to be sorted:");
 for(i=0;i<n;i++)
	 {
	  *(p+i)=rand();
	 }
 printf("\nThe Elements of the unsorted array are:\n");
 for(i=0;i<n;i++)
	 {
	  printf("%d\t",*(p+i));
	 }
 printf("\n");
//code_which_follows_bubble_sort_algorithm
 /*for(i=0;i<n;i++)
	 {
	  for(j=0;j<n;j++)
		  {
			if(*(p+j)>*(p+j+1))
			  {
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			  }

		  }
		printf("\nArray after pass node %d:",i);
		for(k=0;k<n;k++)
		printf("  %d  ",*(p+k));
	  } */
//code_which_follows_merge_sort
int merge(int arr[], int start,int finish, int mid){
	int n1 =mid-start+1;
	int n2= finish -mid;
	int l[n1],m[n2];
	for(int i=0;i<n1;i++)
		l[i]=arr[start+i];
	for(intj=0;j<n2;j++)
		m[j]=arr[mid+1+j];
	int i,j,k;
	i=0;
	j=0;
	k=start;
	while(i<n1 && j<n2){
		if(l[i]<=m[j]){
			arr[k]=l[i];
			i++;
		}
		else{
			arr[k]=m[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=l[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=m[j];
		j++;
		k++;
	}
	return;
}

int mergesort(int arr[], int start,int finish){
	int length = finish- start +1;
	if(length==1)
		return;
	else{	
	mid = start+(length/2)-1;
	mergesort(arr,start,finish);
	mergesort(arr,mid+1,finish);
	merge(arr,start,finish,mid+1);
	
	}
	return;
}
/*void printarray(int arr[],int n){
	for(int i=0; i< n;i++){
		printF("%d",arr[i]);
		printf("\n");
	}
}*/

 //printf("\n\nThe Elements of the sorted array are(BY BUBBLE SORT):\n");
 printf("\n\nThe Elements of the sorted array are(BY MERGE SORT):\n");
 for(i=0;i<n;i++)
	 {
	  printf("%d\t",*(p+i));
	 }
  end = clock();
 printf("\nThe time for the event was: %f",(end-start)/CLK_TCK);
 return 0;
 }

