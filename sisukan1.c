/***************************************************/
/*      1重指数関数型変換による積分    sisukan1.c  */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define  PI             3.141592653589793
#define  FNF(x)         pow(x, 50.0) 
#define  FNFTAU(a,b,x)  (b-a)/2.0*x+(b+a)/2.0
#define  FNG(x)         2.0/PI*atan(exp(x)-exp(-x))
int main(void) 
{   int     i, n;             /* n   :総和範囲  */
    double  h, t, u, a, b;    /* a,b :積分区間  */
    double  g1, x, s, ss;     /* ss  :積分値    */
    char    z, zz;
    while( 1 ){
        printf("1重指数関数型変換による積分");
        printf("\n\n   f(x) = x^50\n\n");
        printf("積分区間 [a , b] の  a = ");   
        scanf("%lf%c",&a,&zz);
        printf("積分区間 [a , b] の  b = ");   
        scanf("%lf%c",&b,&zz);
        printf("総和の範囲( -n ～ n-1) n = ");   
        scanf("%d%c",&n,&zz);
        printf("\n正しく入力しましたか？(y/n) ");
        scanf("%c%c",&z,&zz);
       if(z == 'y')    break;  
    }
    h = 0.1;    s = 0.0;
    printf("\n   計算中です．\n\n");
    for(i = -n; i<=n-1; i++) {
        t = h * i;
        u = FNG(t);
        g1 = 2.0/PI*(exp(t)+exp(-t)) / 
                    (1+pow(exp(t)-exp(-t),2.0));
        x = FNFTAU(a,b,u);
        s += FNF(x) * g1 * h;
    }
    ss = s * (b - a) / 2.0;
    printf("積分値 = %10.6lf\n",ss);
    return 0;
}
