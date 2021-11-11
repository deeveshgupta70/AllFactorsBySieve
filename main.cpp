#include<bits/stdc++.h>

using namespace std;
#define m 100001

int se[m];

void sieve(){
    
    memset(se, 0 , sizeof(se));
    
    for( int i = 0 ; i < m;  i++) se[i] = i;
    
    
    for( int i = 2; i*i <= m ; i++){
        
        if( se[i] == i){
            
            for( int j = i*i ; j < m; j+= i){
                
                if( se[j] == j) se[j] = i;
            }
        }
    }
}


int solve( int n){
    
    vector<int> ans;
    
    int temp = n;
    while(temp != 1){
        
         ans.push_back(se[temp]);
        
        temp = temp/se[temp];
    }
    
    int count = 1;
    int result = 1;
    
    for( int i = 1; i < ans.size() ; i++){   
        if( ans[i] == ans[i-1]) count++;
        
        else {
            
            result *= (count+1);
            count = 1;
        }
        
    }
    result *= (count+1);
    
    return result;
}

int main(){
    
    int t;
    cin>>t;
    sieve();
    
    while(t--){
        
        int n;
        cin>>n;
        
        cout<<(n == 1? 1: solve(n))<<"\n";
    }
    
    return 0;
}




