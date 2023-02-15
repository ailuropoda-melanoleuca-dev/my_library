// enumPrimeFactor_Or_Less
// N以下の整数に対して、素因数の種類数計算する
// enumPrimeFactor[i] := iの素因数の種類数

#include<bits/stdc++.h>
using namespace std ;


template<typename T> 
vector<T> enumPrimeFactor_Or_Less(T N){
    vector<T> enumPrimeFactor(N+1) ; 
    for(int i = 2 ; i <= N ; i++){
        if(enumPrimeFactor.at(i) != 0 ) continue ; 
        for(int j = i ; j <= N ; j += i){
            enumPrimeFactor.at(j) += 1 ; 
        }
    }
    return enumPrimeFactor ; 
}