#include "the2.h"
#include <cmath>




void ascending_sort(int* arr, int arraySize, int groupSize, int maxDigitLength, long& numberOfIterations){
    int binsize, sayi, y=0,a ;
    binsize = pow(10,groupSize);
    int head[binsize],arr1[arraySize] ;
    

    
    
    for(int w=0; w<int((maxDigitLength)/groupSize) ;w++)
    {
            for(int i=0;i<binsize;i++)
            {   head[i]=0;
                //numberOfIterations++;
            }
        
            for(int i=0; i<arraySize; i++){

                sayi=int(arr[i]/pow(10,(groupSize*w)))%(int(pow(10,(groupSize))));
                head[sayi]++;
                numberOfIterations++;

            }
            
            for(int i=1; i < binsize; i++){
                head[i]+=head[i-1];
                numberOfIterations++;

                
            }

            for(int i=arraySize-1 ; i >= 0; i--){
                sayi=int(arr[i]/pow(10,(groupSize*w)))%(int(pow(10,(groupSize))));
                arr1[head[sayi]-1]=arr[i];
                head[sayi]--;
                numberOfIterations++;
            }
            for(int i=0; i<arraySize;i++){
                arr[i]=arr1[i];
                numberOfIterations++;
                
            }
    }
    
     if(maxDigitLength%groupSize!=0){
         a=int((maxDigitLength)/groupSize)-1;
        int digitsayi;
        digitsayi = maxDigitLength%groupSize;
        binsize= pow(10,digitsayi);
        
                    for(int i=0;i<binsize;i++)
            {   head[i]=0;
                //numberOfIterations++;
            }
        
            for(int i=0; i<arraySize; i++){

                sayi=int(arr[i]/pow(10,(groupSize*(a+1))))%(int(pow(10,(digitsayi))));
                head[sayi]++;
                numberOfIterations++;

            }
            
            for(int i=1;i < binsize; i++){
                head[i]+=head[i-1];
                numberOfIterations++;

                
            }

            for(int i=arraySize-1 ; i >= 0; i--){
                sayi=int(arr[i]/pow(10,(groupSize*(a+1))))%(int(pow(10,(digitsayi))));
                arr1[head[sayi]-1]=arr[i];
                head[sayi]--;
                numberOfIterations++;
            }
            for(int i=0; i<arraySize;i++){
                arr[i]=arr1[i];
                numberOfIterations++;
                
            }
        
        
        
        
        
        
        
    }
    
}









void descending_sort(int* arr, int arraySize, int groupSize, int maxDigitLength, long& numberOfIterations){
    
 int binsize, sayi, y=0,a ;
    binsize = pow(10,groupSize);
    int head[binsize],arr1[arraySize],arr2[arraySize] ;
    

    
    
    for(int w=0; w<int((maxDigitLength)/groupSize) ;w++)
    {
            for(int i=0;i<binsize;i++)
            {   head[i]=0;
                //numberOfIterations++;
            }
        
            for(int i=0; i<arraySize; i++){

                sayi=int(arr[i]/pow(10,(groupSize*w)))%(int(pow(10,(groupSize))));
                head[sayi]++;
                numberOfIterations++;

            }
            
            for(int i=1; i < binsize; i++){
                head[i]+=head[i-1];
                numberOfIterations++;

                
            }

            for(int i=arraySize-1 ; i >= 0; i--){
                sayi=int(arr[i]/pow(10,(groupSize*w)))%(int(pow(10,(groupSize))));
                arr1[head[sayi]-1]=arr[i];
                head[sayi]--;
                numberOfIterations++;
            }
            for(int i=0; i<arraySize;i++){
                arr[i]=arr1[i];
                numberOfIterations++;
                
            }
    }
    
     if(maxDigitLength%groupSize!=0){
         a=int((maxDigitLength)/groupSize)-1;
        int digitsayi;
        digitsayi = maxDigitLength%groupSize;
        binsize= pow(10,digitsayi);
        
                    for(int i=0;i<binsize;i++)
            {   head[i]=0;
                //numberOfIterations++;
            }
        
            for(int i=0; i<arraySize; i++){

                sayi=int(arr[i]/pow(10,(groupSize*(a+1))))%(int(pow(10,(digitsayi))));
                head[sayi]++;
                numberOfIterations++;

            }
            
            for(int i=1;i < binsize; i++){
                head[i]+=head[i-1];
                numberOfIterations++;

                
            }

            for(int i=arraySize-1 ; i >= 0; i--){
                sayi=int(arr[i]/pow(10,(groupSize*(a+1))))%(int(pow(10,(digitsayi))));
                arr1[head[sayi]-1]=arr[i];
                head[sayi]--;
                numberOfIterations++;
            }
            for(int i=0; i<arraySize;i++){
                arr[arraySize-i-1]=arr1[i];
                numberOfIterations++;
                
            } 
                
                
            }
            
                        else{
                           for(int i=0; i<arraySize;i++){
                arr[arraySize-i-1]=arr1[i];
            
                
            } }
            
            
         
         
    

        
        
        
        
        
    }
    
    
    
    
    



long multiDigitRadixSort(int* arr, bool ascending, int arraySize, int groupSize, int maxDigitLength){
    long numberOfIterations = 0;
    
    if(ascending){ ascending_sort(arr, arraySize, groupSize, maxDigitLength, numberOfIterations);}
    else {descending_sort(arr, arraySize, groupSize, maxDigitLength, numberOfIterations);}
    
    
    
    return numberOfIterations;
}