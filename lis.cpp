template <typename T>
deque<T> LIS(vector<T> x){
    deque<T> res ; 
    for(int i = 0 ; i < x.size() ; i++){
        T c = x.at(i) ;
        int itr = lower_bound(res.begin() , res.end() , c) - res.begin() ;
        if( itr == res.size() ) res.push_back(c);
        else res.at(itr ) = c ;
    }
    return res;
}
