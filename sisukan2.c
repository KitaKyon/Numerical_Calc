/*****************************************************/
/*    2重指数関数型積分公式による積分    sisukan2.c  */
/*****************************************************/
#include <stdio.h>
#include <math.h>
#define  PI           3.141592653589793
#define  FNF(x)       pow(x , 50.0)
#define  FNTAU(a,b,x) (b-a)*x/2.0+(b+a)/2.0
#define  FSINH(x)     (exp(x)-exp(-x))/2.0
#define  FCOSH(x)     (exp(x)+exp(-x))/2.0
#define  FTANH(x)    (exp(x)-exp(-x))/(exp(x)+exp(-x))
int main(void ) 
{   int     i, n;                                     
    double  a, b, h;                                  
    double  t1, t2, u, v, p, q, u1, v1, c, d, s, ss;  
    char    z, zz;
    /***  n:総和範囲  a,b:積分区間  ss:積分値　***/
    while( 1 ) {
        printf("2重指数関数型積分公式による積分\n\n");
        printf("    f(x) = x ^ 50\n\n");
        printf("積分区間 [ a , b ] の a = ");    
        scanf("%lf%c",&a,&zz);
        printf("積分区間 [ a , b ] の b = ");    
        scanf("%lf%c",&b,&zz);
        printf("刻み幅 ( 0.1程度 )    h = ");    
        scanf("%lf%c",&h,&zz);
        printf("総和範囲（ 50以下 ）  n = ");    
        scanf("%d%c",&n,&zz);
        printf("\n正しく入力しましたか？(y/n) ");
        scanf("%c%c",&z,&zz);
        if(z == 'y')    break;
    }
    printf("\n   計算中です．\n\n");
    s = 0.0;
    for( i=-n; i<=n-1; i++ ) {
        t1 = i * h;            t2 = t1 + h;
        u  = FTANH(PI / 2.0 * FSINH(t1));
        v  = FTANH(PI / 2.0 * FSINH(t2));
        p  = PI*FCOSH(t1)/(1+FCOSH(PI*FSINH(t1)));
        q  = PI*FCOSH(t2)/(1+FCOSH(PI*FSINH(t2)));
        u1 = FNTAU(a,b,u);    v1 = FNTAU(a,b,v);
        c  = FNF(u1) * p;     d  = FNF(v1) * q;
        s  += (c + d);
    }
    ss = s * h / 2.0 * (b - a) / 2.0;
    printf("積分値 = %10.6lf\n",ss); 
    return 0;
}
