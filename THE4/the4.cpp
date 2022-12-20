#include "the4.h"


int dp_sln(char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int**& mem){ //dynamic programming
    char harf;
    int harf_sayisi=0 ,gelen1=0, gelen2=0,gelen3=0,delet=0, replace,harf1=0,harf2=0,z=1,reorder=0;
    mem[0][0]=0;
    for(int i=0;i<ncol2;i++){
        for(int j=0;j<nrow;j++){
            
            if(arr2[j][i]!='-') harf_sayisi++;
            
            
        }
        mem[0][i+1]=harf_sayisi;
    }
    harf_sayisi=0;
    
    for(int i=0;i<ncol1;i++){
        for(int j=0;j<nrow;j++){
            
            if(arr1[j][i]!='-') harf_sayisi++;
            
            
        }
        mem[i+1][0]=harf_sayisi;
    }
    
    
    for(int i=1;i<=ncol1;i++){
        for(int j=1;j<=ncol2;j++){
            harf_sayisi=0;
            for(int k=0;k<nrow;k++){
                if(arr2[k][j-1]!='-') harf_sayisi++;
                
                
            }
            replace=0;
            for(int k=0;k<nrow;k++){
                
                if (arr1[k][i-1]!=arr2[k][j-1]){
                    if(arr1[k][i-1]=='-' || arr2[k][j-1]=='-'){
                        replace+=2;
                    }
                    else{ replace++;}
                    
                }
                
            }
            z=1;
            for(int k=0;k<nrow;k++){
                harf=arr1[k][i-1];
                harf1=0; harf2=0;
                for(int q=0;q<nrow;q++)
                {
                    if(arr1[q][i-1]==harf) harf1++;
                    if(arr2[q][j-1]==harf) harf2++;
                    
                }
                if(harf1!=harf2) z=0;
            }
            reorder=0;
            if(z){
                for(int q=0;q<nrow;q++){
                    if(arr1[q][i-1]!=arr2[q][j-1]) reorder++;
                    
                    
                    
                }
                

                
            }

            if(reorder<replace && z==1) replace=reorder;
            
            delet=0;
            for(int o=0;o<nrow;o++){
                if(arr1[o][i-1]!='-') delet++;
                
                
                
            }
            
            
            
            gelen3=mem[i-1][j]+delet;//delete sayisi
            gelen1=mem[i-1][j-1]+replace ; //4 taneden biri
            
            gelen2=mem[i][j-1] + harf_sayisi;//insertion sayısı
            if(gelen1<gelen2)
            {
                if(gelen1<gelen3) mem[i][j]=gelen1;
                else mem[i][j]=gelen3;
            
            }
            else{
                if(gelen2<gelen3) mem[i][j]=gelen2;
                else mem[i][j]=gelen3;
                
                
                
            }    
            
            
            
            
            
            
            
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    return mem[ncol1][ncol2]; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}

