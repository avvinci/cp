class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty() ) return 0 ; 
        string s = needle + "$" + haystack ; 
        
        int n = needle.size() ; 
        int m = s.size() ; 
        vector<int > p(m,0);
        int  j ;
        for(int i = 1 ; i < s.size() ;i++){
            j = p[i-1] ; 
            while(j > 0 && s[j] != s[i] ){
                j = p[j-1] ; 
            }
            if(s[i] == s[j] ) j++; 

            p[i] = j;
            if(p[i] == n) return i-n-1-n+1 ; 
        }
        return -1;
        
     }
};