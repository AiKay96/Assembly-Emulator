int fibonacci(int x){
    if(x <= 1)
        return x;
    int a = fibonacci(x-1);
    int b = fibonacci(x-2)
    return a + b;
}

int main(){
    int i = fibonacci(10);
    int j = fibonacci(5);
}