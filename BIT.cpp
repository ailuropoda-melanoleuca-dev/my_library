// 0-indexed BIT
template <typename T>
class BIT {
    
    int n;          // 配列の要素数(数列の要素数+1)
    public:
    vector<T> bit;  // データの格納先(初期値は0)
    BIT(int n_) : n(n_), bit(n+1, 0) {}

    // a_i += x 
    void add(int i, T x) { 
        i++ ; 
        if(i == 0) return ; 
        for (int idx = i; idx <= n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    // a_0 + a_1 + ... + a_(i-1) を計算する
    T sum(int i){
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }

    // a_l + a_1 + ... + a_(r-1) を計算する
    T range_sum(T l , T r){
        return sum(r) - sum(l) ; 
    }

    // a_0 + a_1 + ... + a_(i) >= x となる最初のiを計算する
    T lower_bound(T x){
        if(x <= 0 ) return 0 ; 
        else{
            T i = 0 ; 
            T r = 1 ; 
            while(r < n) r = r<<1 ; 

            for(int len = r ; len > 0 ; len = len>>1){
                if(i + len < n && bit[i + len] < x){
                    x -= bit[i+len] ; 
                    i += len ; 
                }
            }
            return i ; 
        }
    }


};

