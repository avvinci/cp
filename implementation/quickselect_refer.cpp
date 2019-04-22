class Solution {
public:
    int partition(vector<int> & a , int x , int y ,int val){
        int i = x-1 , j = 0 ;
        for(j = x ; j < y ;j++ ){
            if(a[j] <= val )
            {
                swap(a[i+1] , a[j]) ; 
                i++ ; 
            }
        }
        swap(a[i+1],a[y]) ; 
        return i+1; 
    }
    int fun(vector<int> &a, int x ,int y , int k ){
        int len = y-x+1; 
        int ind = x + rand()%len;
        swap(a[ind] , a[y]) ; 
        int pind = partition(a,x,y,a[y]);
        if(pind == k) return a[pind] ; 
        else if(pind > k  ) 
            return fun(a,x,pind-1,k) ; 
        else 
            return fun(a,pind+1,y,k) ; 
    }
    int findKthLargest(vector<int>& a, int k) {
       int n = a.size() ; 
        k = n-k ; 
        // k--;
        return fun(a, 0,n-1, k);  
    }
};