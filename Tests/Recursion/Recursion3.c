int fastPow(int x, int n){
    if(n == 0)
        return 1;
    int y = n / 2;
    if(2*y == n){
        int tmp = fastPow(x, y);
        return tmp*tmp;
    }
    return x * fastPow(x, n-1);
}
int main(){
    int i = fastPow(5, 4);
}