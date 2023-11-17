/*Modulo properties
    (a + b) mod m = (a mod m + b mod m) mod m
    (a − b) mod m = (a mod m − b mod m) mod m
    (a · b) mod m = (a mod m · b mod m) mod m
*/

typedef long long lli;
 
const lli mod = 1e9 + 7;
 
lli sum(lli a, lli b){
    return ((a%mod) + (b%mod))%mod;
}
 
lli mul(lli a, lli b){
    return ((a % mod) * (b % mod)) % mod;
}
 
lli sub(lli a, lli b){
    return ((a - b)+mod)%mod;
}

// x^n%mod
lli modpow(lli x, lli n){
    if(n == 1) return x%mod;
    if(n == 0) return 1%mod;
    lli u = modpow(x, n/2);
    u = mul(u, u);
    if(n%2 == 1) u = mul(u, x);
    return u;
}
lli inv(lli a){
    return modpow(a, mod-2);
}
 
lli division(lli a, lli b){
    return mul(a, inv(b));
}
 
lli fpow(lli b, lli e){
    if(e == 0) return 1LL;
    if(e == 1) return b;
    lli r = fpow(b, e/2);
    r = mult(r, r);
    if(e % 2) r = mult(r, b);
    return r;
}
 
 
vector<int> fact(1e6+5), ifact(1e6+5);
 
void init(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 1e6; i++){
        fact[i] = mult(fact[i-1], i);
    }
    ifact[int(1e6)] = inv(int(1e6));
    for(int i = 1e6-1; i>=0; i--){
        ifact[i] = mult(ifact[i+1], i+1);
    }

