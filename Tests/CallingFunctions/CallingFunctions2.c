struct fraction {
  int numerator;
  int denominator;
};
void Binky(struct fraction param){
  struct fraction local;
  local.denominator = 1;
  param.denominator = 2;
}
int main(){
  struct fraction actual;
  Binky(actual);
}