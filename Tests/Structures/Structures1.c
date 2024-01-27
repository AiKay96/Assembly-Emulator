struct binky {
  int a;
  char b, c, d, e;
  short f;
};
int main(){
  struct binky x;
  x.e = 'A';
  x.a = 40000;
  x.f = x.a;
}