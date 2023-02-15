//dijkstra
#include<bits/stdc++.h>
using namespace std ;
const long long INF = 100100100100100100;
struct edge{long long  to, cost;};

struct graph{
  long long  V;
  vector<vector<edge> > G;
  vector<long long> d;
  vector<int> prev ; 
  vector<int> path;

  graph(long long n){
    init(n);
  }

  void init(long long n){
    V = n;
    G.resize(V);
    d.resize(V);
    prev.resize(V,-1) ; 
    for(int i = 0 ; i < V ; i++){
      d[i] = INF;
    }
  }

  void add_edge(long long s, long long t, long long cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(long long s){
    for(int i = 0 ; i < V; i++){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<pair<long long , long long >,vector<pair<long long, long long> >, greater<pair<long long , long long > > > que;
    que.push(make_pair(0,s));
    while(!que.empty()){
      pair<long long , long long> p = que.top(); 
      que.pop();
      long long v = p.second;

      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          prev.at(e.to) = v ;
          que.push(make_pair(d[e.to],e.to));
        }
      }
    }
  }

    void get_path(const vector<int> prev, int t) {
        for (int cur = t; cur != -1; cur = prev[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    }
};

// graph g(n) -> n頂点のグラフ生成
// g.add_edge(a,b ,cost) 
// g.dijkstra(s) -> sからの最短経路探索
// int dist = g.d[i]: が距離に格納される
// vector<int> path = get_path(g.prev, t) ;// t = mokutekiti
// g.prev(i) ある頂点iへ至る頂点
