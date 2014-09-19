#include"Algorithm.h"

void my_swap(int &a,int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void quickSort2(int a[],int left,int right)
{
	int i = left,j = right;
	int tmp = a[left];
	if(i >= j) return;
	while(i < j)
	{
		while(i < j && tmp <= a[j])
			j--;
		a[i] = a[j];
		while(i < j && a[i] <= tmp)
			i++;
		a[j] = a[i];
	}
	a[i] = tmp;
	quickSort2(a,left,i-1);
	quickSort2(a,i+1,right);
}

void quickSort1(int a[],int n)
{
	quickSort2(a,0,n-1);
}

void insertSort1(int a[],int n)
{
	for(int i = 1;i < n;i++)
	{
		int tmp = a[i];
		for(int j = i-1;j >= 0 && a[j] > tmp;j--)
			a[j+1] = a[j];
		a[j+1] = tmp;
	}
}

void selectSort1(int a[],int n)
{
	for(int i = 0;i < n;i++)
	{
		int min = i;
		for(int j = i+1;j < n;j++)
			if(a[j] < a[min])
				min = j;	
		my_swap(a[i],a[min]);
	}
}

void bubbleSort1(int a[],int n)
{
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
			if(a[j] < a[j-1])
				my_swap(a[j-1],a[j]);
}

void shellSort1(int a[],int n)
{
	int i,j,tmp,gap;
	for(gap = n/2;gap > 0;gap /= 2)
		for( i = gap;i < n;i++)
		{
			tmp = a[i];
			for( j = i - gap;j >= 0 && a[j] > tmp;j -= gap)
				a[j+gap] = a[j];
			a[j+gap] = tmp;
		}
}


//堆排序
void fixDown(int a[],int i,int n)
{
	int j = i * 2 + 1;
	int tmp = a[i];
	for(;j < n && a[j] > tmp;j = j * 2 +1)
	{
		if(j != n-1 && a[j+1] > a[j])
			j++;
		a[(j - 1) / 2] = a[j];
	}
	a[(j - 1) / 2] = tmp;
}

void heapSort1(int a[],int n)
{
	int i;
	for(i = n/2;i >= 0;i--)
		fixDown(a,i,n);
	for(i = n-1;i > 0;i--)
	{
		my_swap(a[0],a[i]);
		fixDown(a,0,i);
	}
}


void mergeArray(int a[],int left,int right,int mid,int temp[])
{
	int i = left,n = mid,j = mid+1,m = right,k = 0;
	while(i <= n && j <= m)
	{
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else 
			temp[k++] = a[j++];
	}
	while(i <= n)
		temp[k++]  = a[i++];
	while(j <= m)
		temp[k++] = a[j++];
	for(i = 0;i < k;i++)
		a[left + i] = temp[i];
}

void mergeSort2(int a[],int left,int right,int temp[])
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort2(a,left,mid,temp);
		mergeSort2(a,mid+1,right,temp);
		mergeArray(a,left,right,mid,temp);
	}
}

void  mergeSort1(int a[],int n)
{
	int *p = new int [n];
	if(p == NULL) 
		cout << "out of space" << endl;
	mergeSort2(a,0,n-1,p);
	delete[] p;
}
