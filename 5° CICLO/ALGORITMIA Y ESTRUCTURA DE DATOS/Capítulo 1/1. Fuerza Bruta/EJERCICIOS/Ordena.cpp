
#include <iostream>

using namespace std;

void ord_burbuja(int *arr,int largo)
{	int temp;

	for(int i=0;i<=largo-2;i++)
	{	
		for(int j=0;j<=largo-2-i;j++)	
		{
			if(arr[j+1]<arr[j])
			{	temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}
		}	
	}	
}


int main(){
	int i,n=4;
	int arreglo[]={3,2,1,7}; /*valores en duro*/
	
	ord_burbuja(arreglo,n);
	
	for(i=0;i<n;i++)
		cout<<arreglo[i] << " ";
	
	return 0;
}

