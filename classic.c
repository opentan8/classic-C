# include <stdio.h>

void c001(){
// 有 1、2、3、4 个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
  int a, b, c;
  int col=8, n=0;
  for(a=1;a<=4;a++)
    for(b=1;b<=4;b++){
      if(a==b) continue;
      for(c=1;c<=4;c++){
        if(a!=c && b!=c){
          n++;
          printf("%d%d%d", a, b, c);
          if(n%8!=0) printf("\t");
          else printf("\n");
        }
      }
    }
}

void c002(){
/*
  企业发放的奖金根据利润提成。
  利润(I)低于或等于10万元时，奖金可提10%；
    利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可可提成7.5%；
    20万到40万之间时，高于20万元的部分，可提成5%；
    40万到60万之间时高于40万元的部分，可提成3%；
    60万到100万之间时，高于60万元的部分，可提成1.5%，
    高于100万元时，超过100万元的部分按1%提成，
  从键盘输入当月利润I，求应发放奖金总数？
*/
  const int n = 6;
  long benift, base=100;
  long b[6] = {0, 10, 20, 40, 60, 100};
  double r[6] = {0.1, 0.075, 0.05, 0.03, 0.015, 0.01};
  double bonus, x;
  printf("Input Value:");
  scanf("%ld", &benift);
  for(int i=1;i<=n;i++){
    if(i==n||benift<b[i]*base){
      bonus = x*base+(benift-b[i-1]*base)*r[i-1];
      break;
    }
    x += (b[i]-b[i-1])*r[i-1];
  }
  printf("Result is %.2f !\n", bonus);
}

void main(){
  c002();
}
