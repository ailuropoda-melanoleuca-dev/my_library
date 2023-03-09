

vector<int> max_lcp(vector<pair<string , int> > S){
    sort(S.begin() , S.end()) ; 
    int N = S.size() ; 
    vector<int> ans(N) ; 

    for(int i = 0 ; i < N-1; i++){
        auto [a , ai] = S.at(i) ; 
        auto [b , bi] = S.at(i+1) ; 
        int now = 0 ; 
        while(now < a.size() && now < b.size()){
            if(a.at(now) != b.at(now)) break ; 
            now++ ; 
        }

        ans.at(ai) = max(ans.at(ai) , now) ; 
        ans.at(bi) = max(ans.at(bi) , now) ;
    }
    return ans ; 
}