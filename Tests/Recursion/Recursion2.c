int factorial(int x){
    if(x <= 1)
        return 1;
    return x * factorial(x-1);
}
int main(){
    int i = factorial(10);
}