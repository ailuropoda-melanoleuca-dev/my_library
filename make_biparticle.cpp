
//makeBiparticle
//makeBiparticle bi(N) 
//bi.build(G)
struct makeBiparticle{
    public:

    bool isBiParticle ; 
    vector<int> color ; 
    int N ; 
    makeBiparticle(int n_): N(n_) , isBiParticle(true),color(n_,-1) {}

    void build(vector<vector<int> > G ){
        for(int i = 0 ; i < N ; i++){
            if(color.at(i) != -1) continue ; 
            deque<int > q ; 
            color.at(i) = 0 ; 
            q.push_back(i) ; 
            while(!q.empty()){
                int now = q.front() ; 
                q.pop_front() ; 

                for(int nx : G.at(now)){
                    if(color.at(nx) != -1){
                        if(color.at(nx) == color.at(now)){
                            isBiParticle = false ;
                        }
                        continue ; 
                    }
                    color.at(nx) = 1 - color.at(now) ; 
                    q.push_back(nx) ; 
                }
            }
        }
    }
};
