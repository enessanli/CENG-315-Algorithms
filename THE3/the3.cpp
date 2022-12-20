#include "the3.h"



int recursive_sln(int i, char**& arr, int*& len, int &number_of_calls) { //direct recursive
    char harf,harf1,harf2;
    int deger,maxim,maxim1=0,deger1=0,deger2=0,sonuc1=0,sonuc2=0;
    number_of_calls+=1;


    harf = arr[i][0];
    harf1=arr[i][1];
  
  
    //if(N==i)
        if(number_of_calls==1){
        for(int j=i-1;j>=0;j--){
            if( ((harf=='S')&&('S'==arr[j][1])) || ((harf=='O')&&('I'==arr[j][1])) || ((harf=='I')&&('O'==arr[j][1])) )
            {   deger=j;
                break;
            }
        }
        
        //maxim=fmax(recursive_sln(i-1,arr, len, number_of_calls),len[i]+recursive_sln(deger,arr, len, number_of_calls));
        for(int k=i-1;k>=0;k--)
        {
            maxim = recursive_sln(k,arr, len, number_of_calls);
            if(maxim>=maxim1){
                maxim1=maxim;
            }
        }
        maxim=fmax(len[i]+recursive_sln(deger,arr, len, number_of_calls),maxim1);
        return maxim;
    }
    
   // else if(i==0){return len[i];}
    
    
    else{
        
        

        for(int j=i-1;j>=0;j--){
            if( ((harf=='S')&&('S'==arr[j][1])) || ((harf=='O')&&('I'==arr[j][1])) || ((harf=='I')&&('O'==arr[j][1])) )
            {   deger1=j;
                sonuc1=len[i]+recursive_sln(deger1,arr, len, number_of_calls);
                break;
            }
            
            
        }

        for(int j=i-1;j>=0;j--){
            
            if( ((harf1=='S')&&('S'==arr[j][1])) || ((harf1=='O')&&('O'==arr[j][1])) || ((harf1=='I')&&('I'==arr[j][1])) )
            {   deger2=j;
                sonuc2=recursive_sln(deger2,arr, len, number_of_calls);
                break;
            }
            
        }
            if(sonuc1==0&&sonuc2==0) return len[i];
            if(sonuc1>sonuc2) return sonuc1;
            else return sonuc2;
                
                
            
            
    }
    
    //return 0;
}



int memoization_sln(int i, char**& arr, int*& len, int**& mem) { //memoization

    if(i>0){
        
        
     memoization_sln(i-1,arr,len,mem);   
        
        
    }
    
        if(mem[i][0]==-1){
     mem[i][0]=0; mem[i][1]=0; mem[i][2]=0; 
    }
    
    
    if(i==0){
        if(arr[0][1]=='I'){mem[0][0]=len[0]; mem[0][1]=0; mem[0][2]=0;} 
        if(arr[0][1]=='O'){mem[0][1]=len[0]; mem[0][0]=0; mem[0][2]=0;}
        if(arr[0][1]=='S'){mem[0][2]=len[0]; mem[0][1]=0; mem[0][0]=0;}
    }
    else{
        
        mem[i][0]=mem[i-1][0]; 
        mem[i][1]=mem[i-1][1];
        mem[i][2]=mem[i-1][2];
        if(arr[i][1]=='I'){
            
            if(arr[i][0]=='I'){ if(mem[i][0]<len[i]+mem[i-1][1]) mem[i][0]=len[i]+mem[i-1][1];}
            if(arr[i][0]=='O'){ if(mem[i][0]<len[i]+mem[i-1][0]) mem[i][0]=len[i]+mem[i-1][0];}
            if(arr[i][0]=='S'){ if(mem[i][0]<len[i]+mem[i-1][2]) mem[i][0]=len[i]+mem[i-1][2];}
            
        }
        
        if(arr[i][1]=='O'){
            
            if(arr[i][0]=='I'){ if(mem[i][1]<len[i]+mem[i-1][1]) mem[i][1]=len[i]+mem[i-1][1];}
            if(arr[i][0]=='O'){ if(mem[i][1]<len[i]+mem[i-1][0]) mem[i][1]=len[i]+mem[i-1][0];}
            if(arr[i][0]=='S'){ if(mem[i][1]<len[i]+mem[i-1][2]) mem[i][1]=len[i]+mem[i-1][2];}
            
        }
        
        
        
        
        if(arr[i][1]=='S'){
            
            if(arr[i][0]=='I'){ if(mem[i][2]<len[i]+mem[i-1][1]) mem[i][2]=len[i]+mem[i-1][1];}
            if(arr[i][0]=='O'){ if(mem[i][2]<len[i]+mem[i-1][0]) mem[i][2]=len[i]+mem[i-1][0];}
            if(arr[i][0]=='S'){ if(mem[i][2]<len[i]+mem[i-1][2]) mem[i][2]=len[i]+mem[i-1][2];}
            
        } 
        
        
        
        
        
    }
    
        if(mem[i][0]>mem[i][1]){ if(mem[i][0]>mem[i][2]) return mem[i][0]; else return mem[i][2];}
        else{                        if(mem[i][1]>mem[i][2]) return mem[i][1]; else return mem[i][2];   }
        
        
        
        
    
    return 0; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}



int dp_sln(int size, char**& arr, int*& len, int**& mem) { //dynamic programming
    int i=1,max=0;
    if(mem[0][0]==-1){
        if(arr[0][1]=='I'){mem[0][0]=len[0]; mem[0][1]=0; mem[0][2]=0;} 
        if(arr[0][1]=='O'){mem[0][1]=len[0]; mem[0][0]=0; mem[0][2]=0;}
        if(arr[0][1]=='S'){mem[0][2]=len[0]; mem[0][1]=0; mem[0][0]=0;}
    }
    for(;i<size;i++){
        mem[i][0]=mem[i-1][0]; 
        mem[i][1]=mem[i-1][1];
        mem[i][2]=mem[i-1][2];
        if(arr[i][1]=='I'){
            
            if(arr[i][0]=='I'){ if(mem[i][0]<len[i]+mem[i-1][1]) mem[i][0]=len[i]+mem[i-1][1];}
            if(arr[i][0]=='O'){ if(mem[i][0]<len[i]+mem[i-1][0]) mem[i][0]=len[i]+mem[i-1][0];}
            if(arr[i][0]=='S'){ if(mem[i][0]<len[i]+mem[i-1][2]) mem[i][0]=len[i]+mem[i-1][2];}
            
        }
        
        if(arr[i][1]=='O'){
            
            if(arr[i][0]=='I'){ if(mem[i][1]<len[i]+mem[i-1][1]) mem[i][1]=len[i]+mem[i-1][1];}
            if(arr[i][0]=='O'){ if(mem[i][1]<len[i]+mem[i-1][0]) mem[i][1]=len[i]+mem[i-1][0];}
            if(arr[i][0]=='S'){ if(mem[i][1]<len[i]+mem[i-1][2]) mem[i][1]=len[i]+mem[i-1][2];}
            
        }
        
        
        
        
        if(arr[i][1]=='S'){
            
            if(arr[i][0]=='I'){ if(mem[i][2]<len[i]+mem[i-1][1]) mem[i][2]=len[i]+mem[i-1][1];}
            if(arr[i][0]=='O'){ if(mem[i][2]<len[i]+mem[i-1][0]) mem[i][2]=len[i]+mem[i-1][0];}
            if(arr[i][0]=='S'){ if(mem[i][2]<len[i]+mem[i-1][2]) mem[i][2]=len[i]+mem[i-1][2];}
            
        }        
        
        


        

        
        
        
    }
    
            if(mem[i-1][0]>mem[i-1][1]){ if(mem[i-1][0]>mem[i-1][2]) return mem[i-1][0]; else return mem[i-1][2];}
        else{                        if(mem[i-1][1]>mem[i-1][2]) return mem[i-1][1]; else return mem[i-1][2];   }
    
    
    
    
      // this is a dummy return value. YOU SHOULD CHANGE THIS!
}

