/***************************************************/
/*    対称行列の固有値，固有ベクトル（ヤコビ法）   */
/*                                    jacobi.c     */
/***************************************************/
#include <stdio.h>
#include <math.h>
#define    N       11
void output(int n, double a[][N])
{   int i,j;
    for(i=1; i<=n; i++) {
       for(j=1; j<=n; j++) 
          {  printf(" %10.6lf",a[i][j]); }
       printf("\n");
    }
}
int main(void)
{   int     i, j, k, n, l, p, q, check;
    double  aa, a7, a8, a9, x, y, z, w, t, c, s;
    static double  c2, s2, bb, mx, a[N][N], b[N][N];
    static double  t0[N][N], t1[N][N], a1[N], a2[N];
    char    qq, zz;
    while( 1 ){
        printf("対称行列の固有値，固有ベクトル");
        printf("（ヤコビ法）\n\n");
        printf(" 行列の次数を入力 (1<n<10) n = ");    
        scanf("%d%c",&n,&zz );
        if((n <= 1) || (10 <= n))    continue; 
        printf("\n対称行列の上三角成分の入力\n\n");
        for(i=1; i<=n; i++){
            for(j=i; j<=n; j++){
                printf("a( %1d , %1d )=",i,j);     
                scanf("%lf%c",&aa,&zz );
                a[i][j]  = aa;    b[i][j] = aa;
                a[j][i]  = aa;    b[j][i] = aa;
                t0[i][j] = 0.0;
                if(i == j)  t0[i][j] = 1.0; 
            }
            printf("\n");
        }
        printf("\n正しく入力しましたか？(y/n) ");   
        scanf("%c%c",&qq,&zz);
        if(qq == 'y')   break; 
    }
    printf("入力した行列\n");   output(n,a);
    printf("\nエンターキーを押せば対角化計算を");
    printf("開始します．\n");  
    scanf("%c",&zz);
    for(l=1; l<=100; l++) {
    /* 非対角成分の中から絶対値の最大の成分を探す */
        mx = fabs(a[1][2]);
        p  = 1;     q  = 2;
        for(j=2; j<=n; j++) {
            for(i=1; i<=j-1; i++) {
                if(fabs(a[i][j]) <= mx)  continue; 
                mx = fabs(a[i][j]);
                p  = i;     q  = j;
            }
        }
        x = a[p][p];   y = a[p][q];   z = a[q][q];
        /***   θを求める  ***/
        w = 2.0 * y / (x - z);
        t = atan(w) / 2.0;  c = cos(t);   s = sin(t);
        c2 = c * c;         s2 = s * s;   bb = c * s;
        for(k=1; k<=n; k++) {
            a1[k] =  a[p][k] * c + a[q][k] * s;
            a2[k] = -a[p][k] * s + a[q][k] * c;
        }
        for(k=1; k<=n; k++) {
            a7 = a1[k];  a[p][k] = a7;  a[k][p] = a7;
            a8 = a2[k];  a[q][k] = a8;  a[k][q] = a8;
        }
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(i == j)   t1[i][j] = 1.0;	
                else         t1[i][j] = 0.0;	
            }
        }
        t1[p][p] = c;   t1[p][q] = -s;   
        t1[q][p] = s;   t1[q][q] = c;
        a[p][p]  = x * c2 + 2 * y * bb + z * s2;
        a9       = y * (c2 - s2) - (x - z) * bb;
        a[p][q]  = a9;   a[q][p]  = a9;
        a[q][q]  = x * s2 - 2 * y * bb + z * c2;
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                s = 0.0;
                for(k=1; k<=n; k++) 
                   {  s += t0[i][k] * t1[k][j];  }
                a1[j] = s;
            }
            for( j=1; j<=n; j++ )  t0[i][j] = a1[j];
        }
        printf("\n反復回数 = %d回目\n",l);   
        output(n,a);
        /**  非対角成分がすべて零に近づいたかを調べて  **/
        /**  収束を判定する． **/
        check = 0;
        for(i=1; i<=n; i++) {
            for(j=i+1; j<=n; j++) {
                if(fabs(a[i][j]) < 0.000001) 
                       check += 1;
            }
        }
        if(check == (n * n - n) / 2)  break; 
        if(l % 3 == 0) {
        printf("\nエンターキーを押せば次に進みます．");   
        scanf("%c",&zz);   
        }
    }
    printf("\n\n対角化を終了しました．");
    printf("エンターキーを押してください．\n");  
    scanf("%c",&zz);
    printf("       計算結果の出力\n");
    printf("\n入力した行列の出力\n");        
    output(n,b);
    printf("\n固有値の出力\n");
    for(i=1; i<=n; i++)
        printf(" %10.6lf",a[i][i]);    
    printf("\n\n");
    printf("固有ベクトルの出力");
    printf("（上の固有値に左から順に対応）\n");    
    output(n,t0);
    return 0;
}