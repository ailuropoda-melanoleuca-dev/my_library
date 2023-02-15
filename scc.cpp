// scc

#include<bits/stdc++.h>
using namespace std ;

int V ; // Vertex size
vector<vector<int > >  G ; // Graph
vector<vector<int > > rG ; // reverse Graph
vector<int> vs ;  // post order 
vector<bool> used; // used[i] == true -> checked
vector<int> cmp ; 
//Topological order of strongly connected components to which vertices belong
// cmp[i] := i の所属するグループ(トポロジカル順)

vector<vector<int> > scc_graph ; //topological order graph

void add_edge(int from , int to){
    G.at(from).push_back(to);  
    rG.at(to).push_back(from) ; 
}

void dfs(int v){
    used.at(v) = true ;
    for(int i = 0 ; i < G.at(v).size(); i++){
        if(!used.at(G.at(v).at(i))) dfs(G.at(v).at(i));
    }
    vs.push_back(v); 
}

void rdfs(int v, int k ){
    used.at(v) = true ;
    cmp.at(v) = k ; 
    for(int i = 0 ; i < rG.at(v).size(); i++){
        if(!used.at(rG.at(v).at(i))) rdfs(rG.at(v).at(i),k);
    }
}


int scc(){

    vs.clear();
    for(int v = 0 ; v < V ; v++){
        if(!used.at(v)) dfs(v); 
    }

    for(int i = 0 ; i < V ; i++) used.at(i) = false ; 
    int k = 0 ; 
    for(int i = vs.size() - 1 ; i >=0 ; i--){
        if(!used.at(vs.at(i))) rdfs(vs.at(i), k++); 
    }
    return k ; 
}

void build_scc_graph(){
    map<int ,int> M ; 
    for(int i = 0 ; i < V ; i++) M[cmp.at(i)]++ ; 
    int l = M.size() ; 
    scc_graph.assign(l , vector<int>()); 

    for(int i = 0 ; i < cmp.size(); i++){
        scc_graph.at(cmp.at(i)).push_back(i) ; 
    }
}

void scc_init(int num){
    V = num ; 
    G.assign(V, vector<int>()) ; 
    rG.assign(V, vector<int>()) ; 
    vs.resize(V) ; 
    used.resize(V) ; 
    cmp.resize(V) ; 
}

int main(){
    int N , M ; 
    cin >> N >> M ; 
    vector<int> A(M), B(M) ; 
    vector<vector<int> > to(N, vector<int>()); 
    scc_init(N) ; 
    for(int i = 0 ; i < M ; i++){
        int a, b ; 
        cin >> a >> b ; 
        a-- ; 
        b-- ; 
        A.at(i) = a ; 
        B.at(i) = b ; 
        add_edge(a,b) ; 
        to.at(a).push_back(b);
    }
    scc();  

    build_scc_graph(); 
    map<long long ,long long> mp ; 
    for(int i = 0 ; i < N ; i++){
        mp[cmp.at(i)]++ ; 
        cout << cmp.at(i) << endl;
    }

    long long ans = 0 ; 
    for(auto p : mp){
        ans += p.second*(p.second-1)/2 ; 
    }
    cout << ans << endl;

}


