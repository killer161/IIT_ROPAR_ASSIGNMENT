#include<stdio.h>
#include <stdlib.h>
#include<time.h>

void reverse_array(unsigned int arr[],int n)        //reversed an array
{
	int left=0;
	int right=n-1;
	while(left<right)
   {
		int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
	}
}
double bubble_sort(unsigned int arr[],int n)     // Bubble sort 
{ 
   clock_t start,end;
   start=clock();     //for time calculation
	int i,j;
	for(i=0;i<n-1;i++)   // No of passes
	{    
	int flag=0;
//flag use for the redudced the number of passes.if the array is sorted then with the help of flag we break the loop and print the sorted array
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp= arr[j];            // swap the element
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
	end=clock();
   double total_time= ((double)(end-start))/CLOCKS_PER_SEC;
   return total_time;
}

double insertion_sort(unsigned int arr[],int n)    // insertion sort
{
	  clock_t start,end;
   start=clock();     //for time calculation
	int i,temp,j;
		for(i=1;i<n;i++)      // here starting from 1 because we break the array into 2 part 1.sorted 2.unsorted and index 0 is sorted
	{
		temp=arr[i];             // store the element and then compare 
		j=i-1;
		while(j>=0 && temp<arr[j])       
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
		end=clock();
   double total_time=((double) (end-start))/CLOCKS_PER_SEC;
   return total_time;
}
double selection_sort(unsigned int arr[],int n)       // selection sort
{  
   clock_t start,end;
   start=clock();     //for time calculation
    int i,j;
for(i=0;i<n-1;i++)        //number of passes
	{
		int min=i;
		int j;
		for(j=i+1;j<n;j++)  // find the index of min element.
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		if(min!=i)   // if index zero element is minimum then that case no need of swap.
		{
			int temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
	end=clock();
   double total_time=((double) (end-start))/CLOCKS_PER_SEC;	
   return total_time;
}
int partion(unsigned int arr[],int first,int last)
{
	int pivot,start,end;
	pivot=arr[first];
	start=first;
	end=last;
	while(start<end)
	{
		
	while(arr[start]<=pivot)
	{
		start++;
	}
	while(arr[end]>pivot)
	{
		end--;
	}
	if(start<end)
	{
		int temp;
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
	}
}
	int temp;
	temp= arr[first];
	arr[first]=arr[end];
	arr[end]=temp;
	return end;
}
double quick_sort(unsigned int arr[], int first,int last)
{  clock_t start,end;
   start=clock();     //for time calculation
     if(first<last)
	 {
	 	int index_pivot;
	 	index_pivot=partion(arr, first,last);
	 	quick_sort(arr,first,index_pivot-1);
	 	quick_sort(arr,index_pivot+1,last);
	}
	end=clock();
   double total_time= ((double)(end-start))/CLOCKS_PER_SEC;
   return total_time;
		 
}
void merge(unsigned int arr[],int left,int middle,int right)
{
	int i=left;
	int j=middle+1;
	int k=left;
	int temp_arr[right+1];
	
	while(i<=middle && j<=right)
	{
		if(arr[i]<=arr[j])
		{
			temp_arr[k++]=arr[i++];
		}
		else
		{
			temp_arr[k++]=arr[j++];
		}
	}
	if(i>middle)
	{
		while(j<=right)
		{
			temp_arr[k++]=arr[j++];
		}
	}
	else
	{
		while(i<=middle)
		{
			temp_arr[k++]=arr[i++];
		}
	}
	for(k=left;k<=right;k++)
	{
		arr[k]=temp_arr[k];
	}
}
double merge_sort(unsigned int arr[],int first,int last)
{    
   clock_t start,end;
   start=clock();     //for time calculation
	if(first<last)
	{
		int mid= (first+last)/2;
		merge_sort(arr,first,mid);
		merge_sort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
	end=clock();
   double total_time= ((double)(end-start))/CLOCKS_PER_SEC;
   return total_time;
}

int main()
{
   int t,l;
	scanf("%d",&t);
	 l=t;
	int z=0;
	   int n[t],s[t],k[t],p[t];
	while(t--)
	{  
   scanf("%d %d %d %d",&n[z],&s[z],&k[z],&p[z]);  
   z++;            
} 
z=0;
  while(l--)
  {
  /*int sizeofarray = n[z];
  	int sortingalgo = s[z];
  	int inputformat = k[z];
  	int outputformat = p[z]; */
  	int i;
  	unsigned int arr[n[z]],arr2[n[z]];
  	
  	switch(k[z])
  	{
  		case 0: 
  		for(i=0;i<n[z];i++)
  		{
  			arr[i]=rand()%1000000;
		  }
		  break;
		case 1:
		  	for(i=0;i<n[z];i++)
		  	{
		  		arr[i]=rand()%1000000;
			  }
			  quick_sort(arr, 0,n[z]-1);
			  break;
		case 2:
			for(i=0;i<n[z];i++)
			{
				arr[i]=rand()%1000000;
			}
			quick_sort(arr, 0,n[z]-1);
			reverse_array(arr,n[z]);
			break;
	}
	for(int i = 0; i < n[z];i++){
  		arr2[i] = arr[i];
	  }
	double execution_time=0;
	switch(s[z])
	{
		case 0:
		
			execution_time=bubble_sort(arr,n[z]);
			break;
		case 1:
			execution_time=selection_sort(arr,n[z]);
			break;
		case 2:
			execution_time=insertion_sort(arr,n[z]);
			break;
		case 3:
			execution_time=merge_sort(arr,0,n[z]-1);
			break;
		case 4:
		   execution_time=quick_sort(arr,0,n[z]-1);
			break;
			
	}		
  	switch(p[z])
	  {
	  	case 0:
	  		printf("%lf\n",execution_time);
	  		break;
	  	case 1:
	  		
	  		if(n[z]<50)
	  		{
	  			for(int i=0;i<n[z];i++)
	  			{
	  				printf("%d ",arr[i]);
				  }
				  			  printf("\n");

			  }
			  else{
			  
			  for(i=0;i<50;i++)
			  {
			  	printf("%d ",arr[i]);
			  }
			  			  printf("\n");

		}
			  printf("%lf\n",execution_time);
	  		
	  		break;
	  	case 2:
	  		 if(n[z]<50)
	  		{
	  			for(int i=0;i<n[z];i++)
	  			{
	  				printf("%d ",arr2[i]);
				  }
				  			  printf("\n");

				  for(int i=0;i<n[z];i++)
				  {
				  	printf("%d ",arr[i]);
				  }
				  			  printf("\n");

			  }else{
			  	for(int i=0;i<50;i++)
			  {
			  	printf("%d ",arr2[i]);
			  }
			  			  printf("\n");

			  for(int i=0;i<50;i++)
			  {
			  	printf("%d ",arr[i]);
			  }
			  printf("\n");
			  }
	  		   printf("%lf\n",execution_time);
	  		break;
	  
	  		
			  }	
			  z++;	
			  printf("\n------------------------------------------------\n");
	  }
  

        return 0; 	
}
