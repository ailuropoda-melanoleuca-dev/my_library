//画像が一致するかどうか(平行移動のみ)
bool isIncludeString2D(vector<string> A, vector<string> B){
    int Nw = A.at(0).size() ; 
    int Nh = A.size() ; 
    int Mw = B.at(0).size() ; 
    int Mh = B.size() ; 
    bool ret = false ; 
    for(int i = 0 ; i < Nh - Mh + 1; i++){
        for(int j = 0 ; j < Nw - Mw + 1; j++){
            int cnt = 0 ; 
            for(int k = 0 ; k  < Mh; k++){
                for(int l = 0 ; l < Mw ; l++){
                    if(A.at(i+k).at(j+l) == B.at(k).at(l)) cnt++ ; 
                }
            }
            if(cnt == Mw*Mh) ret = true ; 
            

        }
    }
    
    return ret ;
}
