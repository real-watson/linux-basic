#include <stdio.h>

void bubble_sort (int *a,int n)
{
	int i,j,temp;

	for(i=0;i<n;i++){
		for(j=1;j<n-i;j++){
			if(a[j]<a[j-1]){
				temp=a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}//end j for
	}//end i for
}

