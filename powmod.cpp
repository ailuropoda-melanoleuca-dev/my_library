//powmod
//const long long mod = 1000000007 ;
const int mod = 998244353;

long long powmod(long long x,long long y){
    long long  res=1;
    for(long long  i=0;i<y;i++){
        res=res*x%mod;
    }
    return res%mod;
}

