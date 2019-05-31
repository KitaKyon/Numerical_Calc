/***************************************************/
/*     堀之内の数値積分公式による計算   cheby.c    */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define    FNF(x)  (1.0 - x) * exp(-x)
#define    PI      3.141592653589793
#define    N       50
int main(void)
{   int     i, j, k, n, m;
    double  cs[N], e[N], h[N], a, b, s, x, t, s1;
    char    z, zz;
    while( 1 ) {
        printf("堀之内の公式による積分計算\n\n");
        printf(" f(x) = (1.0 - x) * exp(-x)\n\n");
        printf("チェビシェフ補間の次数   n = ");    
        scanf("%d%c",&n,&zz);
        printf("積分区間 [a , b] の a = ");
        scanf("%lf%c",&a,&zz);
        printf("積分区間 [a , b] の b = ");
        scanf("%lf%c",&b,&zz);
        printf("\n正しく入力しましたか？(y/n) ");  
        scanf("%c%c",&z,&zz);
        if(z == 'y')   break;  
    }
    m = n + 1;
    /***  零点の計算  ***/
    for(i=0; i<=n; i++) {
        t = (2 * i + 1) * PI / (2 * m);
        e[i] = t;       cs[i] = cos(t);
    }
    /***  重みの計算  ***/
    for(i=0; i<=n; i++) {
        s1 = 0.0;      t = e[i];
        for(j=2; j<=n; j+=2) {
            s1 += cos(j * t) / (j * j - 1);
        }
        h[i] = (1 - 2 * s1) / m;
    }
    /***  積分値の計算  ***/
    s = 0.0;
    for(k=0; k<=n; k++) {
        x = ((b - a) * cs[k] + (b + a)) / 2.0;
        s += FNF(x) * h[k];
    }
    s = (b - a) * s;
    printf("\n定積分の値 = %10.6lf\n",s);
    return 0;
}
