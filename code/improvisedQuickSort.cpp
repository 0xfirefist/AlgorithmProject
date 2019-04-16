#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int k;
void printarray(int a[]){
	for(int i=0;i<k;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void sortDesc(int low,int high,int a[]){
	int i=low;
	while(i<(low+high)/2+1){
		int temp = a[i];
		a[i] = a[high-i];
		a[high-i] = temp;
		i++;
	}
}
int checkDesc(int low,int high,int a[]){
	int i = 0;
	int k = low+1;
	while(k<=high){
		if(a[k-1]>=a[k])
			i++;
		k++;
	}
	if(i==(high-low)){
		sortDesc(low,high,a);
		return 1;
	}
	return 0;
}
int checkAsc(int low,int high,int a[]){
	int i = 0;
	int k = low+1;
	while(k<=high){
		if(a[k-1]<=a[k])
			i++;
		k++;
	}
	if(i==(high-low))
		return 1;
	return 0;
}

int partition_wmb(int low,int high,int a[]){
	int key,i,j,temp;
	key=a[low];
	i=low;
	j=high+1;
	while(i<=j){ 
		do{
  			i++;
 		}
   		while(key>=a[i]&&i<high+1);
    	
		do{
    			j--;
    		}
    		while(key<a[j]);
	
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
    	} 
	if((j==high)&&(i==high+1)){
	 	if(checkDesc(low,high,a))
			return -1;
	}
	else if((i==1)&&(j==0)){
		if(checkAsc(low,high,a))
			return -1;
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}
void insertionSort(int low,int high,int arr[]){
	int i, key, j; 
	for (i = low; i <=high; i++) { 
		key = arr[i]; 
		j = i - 1; 
		while (j >= low && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
	arr[j + 1] = key; 
	} 
}
void quicksort_wmb(int low,int high,int a[])
{
	if(checkAsc(low,high,a))
		return;
	//if(checkDesc(low,high,a))
	//	return;
	if((high-low)<=20){
		insertionSort(low,high,a);
		return;
	}
	int j;
	if(low<high){ 
		j=partition_wmb(low,high,a);
		if(j == -1)
			return;	
		//cout<<"ho rhi he"<<endl;
		quicksort_wmb(low,j-1,a);
		quicksort_wmb(j+1,high,a);
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	k=n;
	auto start = high_resolution_clock::now();
	quicksort_wmb(0,n-1,a);
	auto stop =  high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<duration.count()<<endl;
	return 0;
}
