#include <iostream>
#include <algorithm>
using namespace std;


void SelectionSort(int A[], int n)
{
	for (int i=0; i<n-1; i++){
		int iMin = i;
		for (int j=i+1; j<n; j++)
		{
			if (A[j] < A[iMin])
				iMin = j;
		}
		swap(A[i], A[iMin]);
	}

}

void BubbleSort(int A[], int n){
	for (int i=0; i<n-1; i++)
	{
		bool flagged = false;
		for (int j=0; j<n-i-1; j++){
			if (A[j] > A[j+1]){
				swap(A[j], A[j+1]);
				flagged = true;
			}
		}
	//in the case that no two elements were swapped in loop
	if (flagged ==false)
		break;
	}
}

void InsertionSort(int A[], int n){
	for (int i=1; i<n; i++)
	{
	  int value = A[i];
	  int j = i-1;
	  /*move elements of A[0..i-1], that are 
 	    greater than value, to one position ahead
	    of their current position*/
	  while (j >= 0 && A[j] > value){
	    A[j+1] = A[j];
	    j = j-1;
	  }
	  A[j+1] = value;
	}
}

void Merge(int A[], int l, int m, int r){
	int i, j ,k;
	int nL=m-l+1;
	int nR=r-m;
	int L[nL],R[nR];

	for (i=0;i<nL;i++){
		L[i] = A[l+i];
	}
	for(j=0;j<nR;j++){
		R[j]=A[m+j+1];
	}
	
	i=0;
	j=0;
	k=l;
	while(i<nL && j<nR){
		if(L[i]<R[j]){
		  A[k] = L[i];
		  i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < nL){
		A[k] = L[i];
		k++;
		i++;
	}
	while(j<nR){
		A[k] = R[j];

		k++;
		j++;
	}
}
void MergeSort(int A[], int l, int r){
	int mid;
	if (l<r){
		mid = l+(r-l)/2;
		
		MergeSort(A,l,mid);
		MergeSort(A,mid+1,r);
		
		Merge(A,l,mid,r);
	}
}
int Partition(int A[], int start, int end){
	//pivot to be placed at end
	int pivot = A[end];

	int pIndex = (start-1);

	for(int i=start; i <= end-1; i++){
	       
		if(A[i] <= pivot){
	       		
			pIndex++;
			swap(A[pIndex],A[i]);
	       }
	}	
	swap(A[pIndex+1],A[end]);
	return (pIndex+1);
	
}	
void QuickSort(int A[], int start, int end){
	if(start < end){
		int pIndex = Partition(A, start, end);
		
		QuickSort(A, start, pIndex-1);
		QuickSort(A, pIndex+1, end);
	}
		
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    cout << "Selection Sorting..." << endl;
    SelectionSort(A, 6);
    for (int i=0; i<6; i++)
        cout << A[i] << " ";
    cout << endl << endl;
    
    int B[] = {12, 17, 14, 11, 15, 13};
    cout << "Bubble Sorting..." << endl;
    BubbleSort(B, 6);
    for (int i=0; i<6; i++)
        cout << B[i] << " ";
    cout << endl << endl;
    
    cout << "Insertion Sorting..." << endl;
    int C[] = {22, 27, 24, 21, 25, 23};
    InsertionSort(C, 6);
    for (int i=0; i<6; i++)
        cout << C[i] << " ";
    cout << endl << endl;
    //for mergesort
    //use on array: sizeof sizeof(A)/sizeof(A[0])
    //
    cout << "Merge Sorting..." << endl;
    int D[] = {22, 27, 24, 21, 25, 23, 26, 28};
    MergeSort(D, 0, 7);
    for (int i=0; i<8; i++)
        cout << D[i] << " ";
    cout << endl << endl;
    
    cout << "Quick Sorting..." << endl;
    int E[] = {32, 37, 34, 31, 35, 33, 36, 38};
    QuickSort(E, 0, 7);
    for (int i=0; i<8; i++)
        cout << E[i] << " ";
    cout << endl << endl;
    
    return 0;
}
