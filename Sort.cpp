#include <iostream>


using namespace std;

void Show(int array[],int len){
	for(int j=0;j<len;j++){		
		cout<<array[j]<<" ";
	}
	cout<<endl;
}

void swap(int i,int j){
	int temp;
	temp = i;
	i = j;
	j = temp;
}

void InsertSort(int array[]){
	int temp;
	for(int i=1;i<10;i++){
		for(int j=0; j <= i-1; j++){			
			if(array[i] < array[j]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

void ShellSort(int a[],int len){
	int gap = len / 2 ;
	int insertNum;
	while(gap >= 1){
//		InsertSort();	
		for(int i=gap;i<len;i++){
			insertNum = a[i];   // save insertnum
            unsigned j = i;
            while (j >= gap && insertNum < a[j-gap])  // if >insertnum change
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
		}	
		gap = gap / 2 ;
	}
	
}
void BubbleSort(int a[],int len){
	int temp;	
	for(int i=len;i>=0;i--){
		// - last e    repeat		 
		for(int j=0;j<10;j++){
			if(a[j] > a[j+1]){
				//exchange
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			
			}			
		}		
	}		
}

void SelectSort(int a[],int len){
	int min,temp;
	
	for(int i=0;i<=len;i++){
		min = i;
		for(int j=i+1;j<=len;j++){
			
			if(a[min] > a[j]){
				temp = a[min];
				a[min] = a[j];
				a[j] = temp;
			}
		}
		a[i] = a[min];
	}
	
}


void QuickSort_first(int a[],int begin,int end){
	//save the original index
	// loe and high is pointer
	int low = begin;
	int high = end;
	
	int div_index;			// find the div_index
	int div_value = a[begin]; // store the mid value	 
	// move low and high	
	
	while(low < high){
		// 1. the last
		while(  low < high && a[high] >= div_value){
			high--;	
		}
		if(low < high){
			
			a[low++] = a[high];
		}			
		// 2. the frist
		while(  low < high &&   a[low] <= div_value){
			low++;	
		}
		if(low < high){
			a[high--] = a[low];	
		}	
			
		div_index = low;
		a[div_index] = div_value;
				
		QuickSort_first(a,begin,div_index-1);
		QuickSort_first(a,div_index+1,end);				
	}
				
}

void QuickSort_last(int a[],int begin,int end){
	int div_index;
	int div_value = a[end];
	
	if(begin < end){		
		int low = begin;
		int high = end;		
		while(low < high){
			while(low<high && a[low] <= div_value)		low++;
			if(low < high)	a[high--] = a[low];					
			while(low<high && a[high] >= div_value)		high--;		
			if(low < high)		a[low++] = a[high];					
		}		
		div_index = low;	//  get the div_index 		
		a[div_index] = div_value;	
		QuickSort_last(a,begin,div_index-1);
		QuickSort_last(a,div_index+1,end);	
	}	
}
void QuickSort(int a[],int begin,int end){
	int div_index;
	int div_value = a[begin];
	
	if(begin < end){
		int low = begin;
		int high = end;
		while(low < high ){
			while(low < high && a[high] >= div_value)	high--;
//			if(low < high)		a[low++] = a[high];			
			while(low < high && a[low] <= div_value)    low++;
//			if(low < high)      a[high--] = a[low];
			if(low < high)	swap(a[low],a[high]);
		}
		
		div_index = low;
//		a[begin] = a[div_index];
		a[div_index] = div_value;
		
		QuickSort(a,begin,div_index-1);
		QuickSort(a,div_index+1,end); 
		
	}
	
}

int main(){
	
	cout<<"H"<<endl;
	int len = 20;
	int A[len];
	
	
	for(int i=0;i<len;i++){
		A[i] = rand()%100;
	}	
	
//	int lenth = A.length;
//	cout<<lenth<<endl;
	
	cout<<"Befor Sort:"<<endl;
	Show(A,len);
////////////////////////////////sort	
//	InsertSort(A);
//	BubbleSort(A,len);
//	SelectSort(A,len);
//	QuickSort_last(A,0,len);
	ShellSort(A,len);
	
	cout<<"After sort:"<<endl;
	Show(A,len);

	return 0;
}


