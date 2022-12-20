#include "the1.h"
#include <climits>
#include <stdio.h>

struct item{
    int value,gelen,index,kez;
    
    
    
};

void swapp(item& a, item& b){
    item temp;
    
    temp=a;
    a=b;
    b=temp;
    

    
    
}

   
   
void heapify(item arr[], int N, int i, long& comparison, long& swap)
{
    int smallest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

    
  
        if (l < N && arr[l].value==INT_MAX)  comparison--;

    if (l < N &&  (comparison++||1) && arr[l].value < arr[smallest].value )
        {smallest = l;
        
            
        }
    if (r < N && arr[r].value==INT_MAX)  comparison--;
    if (r < N &&  (comparison++ || 1) && arr[r].value < arr[smallest].value)
{        smallest = r;
    
    
    
}
    if (smallest != i) {
        swapp(arr[i], arr[smallest]);
        swap++;

        heapify(arr, N, smallest,comparison,swap);
    }
}
 
void buildHeap(item arr[], int N, long& comparison, long& swap)
{
    int startIdx = (N / 2) - 1;
 
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i,comparison,swap);
    }
        comparison-=2;

}





void insertionSort(int* arr, long &comparison, long & swap, int size) 
{
    
    int i=1,j;
    int x;
    while(i<size){
        x=arr[i];
        j=i-1;
        while((j>=0)&&(++comparison||1)&&(arr[j]>x)){
            arr[j+1]=arr[j];
            j=j-1;
           swap++;
            
        }
        arr[j+1]=x;
        i=i+1;

        
    }

}


void birlestir(int* arr, int K, int size, long& comparison, long& swap ){
    
    item mHeap[K],temp;
    int arr1[K*size];
    int j,sayi=0,i;
    for( i=0;i<K;i++){
        mHeap[i].value= *(arr+size*i);
        mHeap[i].index=i;
        mHeap[i].gelen=i;
        mHeap[i].kez=1;
    }
    


    buildHeap(mHeap,K,comparison,swap);


    
    
    
    
    
    j=0;
        while(1){
    i=0;
    
    
            heapify(mHeap, K, 0,comparison,swap);

    



    if(mHeap[0].kez>size-1){


        arr1[j++]=mHeap[0].value;
        mHeap[0].value=INT_MAX;
        sayi++;
        
        
    }
    
    else{


        
            arr1[j++]=mHeap[0].value;
    mHeap[0].value=*(arr+size*mHeap[0].gelen+mHeap[0].kez);
    mHeap[0].kez++;
        
    }

    
    
    if(sayi==K){break;}
    
    }
    
    
    
    
    
    
    
    for(int y=0;y<K*size;y++){
        arr[y]=arr1[y];
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}










void ayir(int* arr, int K, int size, int& number_of_calls,long& comparison, long& swap)
{
    if(size<K){
        insertionSort(arr,comparison,swap,size);
        
        
        
    }
    
    else{
        size=size/K;
        for(int i=0;i<K;i++){
            number_of_calls++;
        ayir((arr+i*size),K,size,number_of_calls,comparison,swap);
        }
        
        birlestir(arr,K,size,comparison,swap);
        
        
        
    }
    
    
    
}








int kWayMergeSortWithHeap(int* arr, int K, int size, long& comparison, long& swap){
  
 
	       int number_of_calls=1;
	       
            ayir(arr,K,size,number_of_calls,comparison,swap);

	
	
	//Your code here
	return number_of_calls;
}