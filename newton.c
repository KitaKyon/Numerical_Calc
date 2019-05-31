/***************************************************/
/*       ニュートン法のプログラム     newton.c     */
/***************************************************/
#include <stdio.h>
#include <math.h>
/***  関数f(x)とf'(x)の定義 ***/
#define  FNF(x)   (x*x*x - 3*x*x + 9*x - 8)
#define  FNG(x)   (3*x*x - 6*x + 9)
int main(void) 
{   /**  x:第1次近似値, xn:漸化式による計算値  **/
    double  x, xn;   
    int     k;
    char    z, zz;
    printf("関数FNF(x) = x^3 - 3*x^2 + 9*x - 8\n");
    printf("の根をニュートン法で求めます．\n\n");
    printf("第1近似値を入力してください " );
    scanf("%lf%c",&x,&zz);
    k = 1;
    printf("回数     近似値  前の近似値との差\n");
    printf("   1 %10.6lf\n",x);
    while( 1 ) {
        k = k + 1;
        /***  漸化式による計算  ***/
        xn = x - FNF(x) / FNG(x);
        printf("%4d %10.6lf    %10.6lf\n",k, xn, xn-x);
        if(fabs(xn - x) < 0.000001)   break;
        x = xn;
        if(k % 10 != 0)   continue;
        printf("\n計算過程を表示しています．\n");
        printf("\n表示を継続しますか？ (y/n): ");  
        scanf("%c%c",&z,&zz);
        if(z == 'n') {
            printf("\n表示を終わります．\n");  break;
        }else  if(z == 'y')
           printf("回数     近似値  前の近似値との差\n");
               else {  z='n';  break;  }
    }
    if(z != 'n') {
        printf("\n %3d 回目で収束しました．\n",k);
        printf("\n収束値＝ %10.6lf\n",xn);
    }
    return 0;
}
