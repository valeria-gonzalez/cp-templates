#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

struct Seg{
    // Node props
    Seg *left, *right; // child nodes
    int l, r; // segment range
    lli sum; // property

    // build
    Seg(int arr[], int tl, int tr) : l(tl), r(tr), sum(0) {
        if(tl == tr){ // if leaf
            sum = arr[l];
        } else {
            int tm = (tl + tr) >> 1;
            left = new Seg(arr, tl, tm);
            right = new Seg(arr, tm + 1, tr);
            sum = left->sum + right->sum;
        } 
    }

    void update(int pos, lli val){
        if(l == r){
            sum = val;
        } else {
            int m = (l + r) >> 1;
            if(pos <= m) left->update(pos, val);
            else right->update(pos, val);
            sum = left->sum + right->sum;
        }
    }

    lli query(int tl, int tr){
        if(tr < l or tl > r) return 0;
        if(tl <= l and r <= tr) return sum;
        return left->query(tl, tr) + right->query(tl, tr);
    }
};

int main(){
    int a[5] = {1, 3, -2, 8, -7};
    Seg st(a, 0, 4);

    st.update(2, 3);
    cout << st.query(2, 4) << endl;


    return 0;
}
