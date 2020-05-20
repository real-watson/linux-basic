#include <stdio.h>

void swap_number(int *x, int *y)
{
	int it;/*临时量作为交换*/
	it = *x;
	*x = *y;
	*y = it;
}

void bubble_sort (int *a,int n)
{
	int i,j,temp;

	for(i=0;i<n;i++){
		for(j=1;j<n-i;j++){
			if(a[j]<a[j-1]){
				swap_number(&a[j],&a[j-1]);
			}
		}//end j for
	}//end i for
}

