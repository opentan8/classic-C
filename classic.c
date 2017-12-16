# include <stdio.h>
# include <stdbool.h>
# include <math.h>

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

void c003(){
  // 一个整数，它加上 100 后是一个完全平方数，再加上 168 又是一个完全平方数，请问该数是多少？
  long start, end;
  int s, e, a=100, b=168;
  int min = sqrt(a), max = (b-1)/2+1;
  for(s=min; s<=max; s++){
    start = s * s; end = start + b; e = sqrt(end);
    if(e*e==end){
      printf("%ld,%ld,%ld,%d,%d\n", start-a, start, end, s, e);
    }
  }
}

void c004(){
  // 输入某年某月某日，判断这一天是这一年的第几天？
  int year=0, month=0, day=0, days=0;
  while(year<=0){ printf("Input Year: "); scanf("%d", &year); }
  bool run = (year%4==0 && year%100!=0 || year%400==0);
  while(month<=0||month>12){ printf("Input Month: "); scanf("%d", &month);}
  while(day<=0 || day>31 || (month==2&&day>28+run) || 
        ((month==4||month==6||month==9||month==11)&&day>30)){ 
    printf("Input Day: "); scanf("%d", &day);
    days=0;
    for(int i=1;i<month;i++){
      if(i==2) days+=28+run;
      else if((i==4||i==6||i==9||i==11)&&day>30) days+=30;
      else days+=31;
    }
    days+=day;
  }
  printf("%d-%d-%d: %d\n", year, month, day, days);
}

void c005(){
  // 输入三个整数 x,y,z，请把这三个数由小到大输出。
  int a=0, b=0, c=0, t=0;
  printf("Input Three Numbers:");
  scanf("%d%d%d", &a, &b, &c);
  if(a>b) { t=a; a=b; b=t; };
  if(a>c) { t=a; a=c; c=t; };
  if(b>c) { t=b; b=c; c=t; };
  printf("%d,%d,%d\n", a, b, c);
}

void c006(){
  int height=10, width=10;
  int space=width*0.5;
  float per=0.3;
  int m_width = width*0.5/(height*per);
  for(int row=1;row<=height;row++){
    for(int i=1;i<space;i++) printf(" ");
    if(row==1||row==height){
      for(int i=1;i<width-space;i++) printf("*");
    }
    printf("*\n");
    if(row<=height*per) space-=m_width;
    else if(row>=height*(1-per)) space+=m_width;
  }
}

void c007(){
  char a=176,b=219;
  printf("%c%c%c%c%c\n",b,a,a,a,b);
  printf("%c%c%c%c%c\n",a,b,a,b,a);
  printf("%c%c%c%c%c\n",a,a,b,a,a);
  printf("%c%c%c%c%c\n",a,b,a,b,a);
  printf("%c%c%c%c%c\n",b,a,a,a,b);
}

void c008(){
  // 输出9*9口诀。
  for(int i=1;i<=9;i++){
    for(int j=1;j<=i;j++) printf("%d*%d=%-2d\t", j,i,i*j);
    printf("\n");
  }
}

void c009(){
  // 输出国际象棋棋盘。
  for(int i=1;i<=8;i++){
    for(int j=1;j<=8;j++){
      if((i+j)%2==0) printf("%c%c", 79,79);
      else printf("  ");
    }
    printf("\n");
  }
}

void c011(){
  // 古典问题：有一对兔子，从出生后第 3 个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？
  long a, b, n=30, t;
  for(int i=1;i<=n;i++){
    if(i<=2) { a=1; b=1; }
    else {t=a; a=b; b+=t; }
    printf("%ld\t", b);
  }
}

void c012(){
  // 判断 101-200 之间有多少个素数，并输出所有素数。
  int low=101, high=200, count;
  bool flag=true;
  for(int num=low;num<=high;num+=2){
    int max=sqrt(num);
    for(int i=2;i<=max;i++){
      if(num%i==0) break;
      flag=false;
    }
    if(!flag) { count++; printf("%d\t", num); };
  }
  printf("Total Prime Numbers: %d\n", count);
}

void c013(){
  // 打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身。例如：153 是一个“水仙花数”，因为 153=1 的三次方＋5 的三次方＋3 的三次方
  for(int num=100;num<=999;num++){
    int b=num/100, s=num/10%10, g=num%10;
    if(b*b*b+s*s*s+g*g*g==num) printf("%d\t", num); 
  }
  printf("\n");
}

void c014(){
  // 将一个正整数分解质因数。例如：输入 90,打印出 90=2*3*3*5。
  int num, mod=2;
  printf("Input Number: "); scanf("%d", &num);
  printf("%d=", num);
  if(num<-mod) { num=-num; printf("-1*"); };
  while(num>mod){
    if(num%mod==0) { num/=mod; printf("%d*", mod); } else mod++; 
  };
  printf("%d\n", num);
}

void c015(){
  /* 利用条件运算符的嵌套来完成此题：
     学习成绩〉=90 分的同学用 A 表示，
             60-89 分之间的用 B 表示，
                60 分以下的用 C 表示。
  */
  int score; char grade;
  printf("Input Score: "); scanf("%d", &score);
  grade = score>=90 ? 'A' : (score>=60 ? 'B' : 'C');
  printf("%c\n", grade);
}

void c016(){
  // 输入两个正整数 m 和 n，求其最大公约数和最小公倍数。
  int m, n, _m, _n, t;
  printf("Input Two Number: "); scanf("%d %d", &m, &n);
  if(m<=0||n<=0) { printf("Illegal Number.\n"); return; }
  _m = m; _n = n;
  if(_m<_n) { t=_m; _m=_n; _n=t; }
  while(_n!=0) { t=_m%_n; _m=_n; _n=t; }
  printf("GongYueShu: %d,\tGongBeiShu: %d.\n", _m, m*n/_m);
}

void c017(){
  // 输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
  int w=0, b=0, d=0, o=0;
  char c;
  printf("Input Any Characters: ");
  while((c=getchar())!='\n'){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) w++;
    else if(c==' ') b++;
    else if(c>='0'&&c<='9') d++;
    else o++;
  }
  printf("Statictis Infomations:\n");
  printf("\tLetters Count:%d\n", w);
  printf("\tBlanks  Count:%d\n", b);
  printf("\tDigests Count:%d\n", d);
  printf("\tOthers  Count:%d\n", o);
}

void main(){
  while(true) c017();
}
