#include<bits/stdc++.h>
using namespace std;
class Robofactory{ 
	public : int reveal(vector <int> query, vector <string> answer);
    };
     int Robofactory:: reveal(vector <int> a, vector <string> s) {
         int mrk[1003] ,i ;
            int cnt = 1; int ind =-1;
         for(i=0;i<a.size();i++)
         {
             mrk[i]= 0;
             
         }
         string h  = "Even";
         for(i = 1;i < a.size();i++){
         	if(a[i-1]%2 != 0){
                if(a[i]%2 == 0 ){
                	if( h.compare(s[i])== 0){
                		mrk[i] = 1;
                	}
                	else{
                        	return i ;
                       
}
                	
                	
                }
                else{
                	 if(h.compare(s[i])== 0){                		
                         return(i);
                	}
           

                }
                
            
            }
             else { cnt++;
        
}
                
       
    
            
            if(cnt ==  1){
            	return 0;
            }
            else
            	return -1;

         }
         
         return 0 ;    
     }