/***************************************************/
/*      ラグランジュの補間多項式       laghkn.c    */
/***************************************************/
#include <stdio.h>
#define    N      11
int main(void) 
{   int     i, j, k, n;
    double  seki, xx, s, x[N], y[N];
    char    z, zz;
    while( 1 ){
        printf("ラグランジュの補間多項式 \n");
        printf("補間点の個数を入力してください(1<n<10)n=");
        scanf("%d%c",&n,&zz);
        if((n<=1) || (10<=n))  continue;
        printf("\n補間点の座標を入力してください．\n");
        for(i=1; i<=n; i++) {
            printf(" x(%d)= ",i); 
            scanf("%lf%c",&x[i],&zz);
            printf(" y(%d)= ",i); 
            scanf("%lf%c",&y[i],&zz);
        }
        printf("\n正しく入力しましたか？(y/n) ");  
        scanf("%c%c",&z,&zz);
        if(z == 'y')   break;
    }
    printf("\n指定する点は？ x =");  
    scanf("%lf%c",&xx,&zz);
    s = 0.0;
    /***  ΣLk(x)の計算  ***/
    for(k=1; k<=n; k++) {
        seki = 1.0;
        /*** Lk(x)の計算 ***/
        for(j=1; j<=n; j++) {
            if(j != k) {
                seki *= (xx-x[j]) / (x[k]-x[j]);
            }
        }
        s += seki * y[k];   
    }
    printf("\nx=%10.6lfにおける値 y=%10.6lf\n",xx,s);
    return 0;
}
