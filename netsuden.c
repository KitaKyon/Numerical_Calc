/******************************************************/
/*   �M�`���������̐��l��@�i�N�����N�E�j�R���\���@�j */
/*                                       netsuden.c   */
/******************************************************/
#include <stdio.h>
#include <math.h>
/**  ���ɏ]���ċ��E���� Gn(t) ��ݒ肷�� **/
#define    G1(t)     0.0  
#define    G2(t)     0.0
/**  ���ɏ]���ď������� Fn(x) ��ݒ肷�� **/
#define    F1(x)     1.0   
#define    F2(x)     x
#define    F3(x)     -x + 2
#define    N         30
void  fgusj(int n, double b[][N+2], double e[][2*N+2])
{   int     i, j, k, l;
    double  d, e2;
    for(i=1; i<=n+1; i++) {
        for(j=1; j<=n+1; j++) {
           e[i][j] = b[i][j];
           if(i == j) {  e[i][n+1+j] = 1.0;  }
           else       {  e[i][n+1+j] = 0.0;  }
        }
    }
    for(i=1; i<=n+1; i++) {
        d = e[i][i];
        for(j=i; j<=2*n+2; j++)  
           {  e[i][j] = e[i][j] / d;  } 
        for(k=1; k<=n+1; k++) {
           if(k == i)   continue; 
           e2 = e[k][i];
           for(l=1; l<=2*n+2; l++)  
               {  e[k][l] = e[k][l] - e[i][l] * e2; }
        }
    }
}
int main(void)
{   int      i, j, k, kosu, m, n;
    double   c, b2, hx, ht, t, s, p, q, x;
    static double  a[5], z[N+2][N+2], b[N+2][N+2];
    static double  e[N+2][2*N+2];
    char     qq, zz;
    printf("���̃v���O�����́C�M�`��������\n\n");
    printf("  Zt = c Zxx      ( c �͒萔 )\n\n");
    printf("�����̋��E��������я��������F\n\n");
    printf("���E�����FZ(0,t)=g1(t), Z(a,t)=g2(t)\n");
    printf("���������FZ(x,0)=f(x)\n\n�̂��Ƃ�");
    printf("�N�����N�E�j�R���\���@�ŉ����܂��D");
    printf("\n\n���E���� G1(t), G2(t) �̓}�N����`");
    printf("�Őݒ�ς݂ł�\n\n");
    printf("���ɕK�v��������͂��܂��D"); 
    printf("�G���^�[�L�[�������Ă��������D\n");  
    scanf("%c",&zz);
    while( 1 ){
        printf("f(x)�͂����̕��}���琬�����܂����H");  
        printf("\n          (���}����3�ȉ��Ƃ���j\n");
        scanf("%d%c",&kosu,&zz);
        a[0] = 0.0;
        for(i=1; i<=kosu; i++) {
            printf("f%1d(x) = F%1d(x) �Ɛݒ�ς�",i,i);
            printf("  [%5.2lf , a ] �� a = ", a[i-1]); 
            scanf("%lf%c",&a[i],&zz);  
        }
        printf("\n�ȉ��̒l����͂��Ă��������D\n");
        printf("�M�`���������̒萔   c = ");  
        scanf("%lf%c",&c,&zz);
        printf("���Ԏ��̋��[0 , t]  t = ");    
        scanf("%lf%c",&b2,&zz);
        printf("x �̍��ݕ�          hx = ");    
        scanf("%lf%c",&hx,&zz);
        printf("t �̍��ݕ�          ht = ");         
        scanf("%lf%c",&ht,&zz);
        printf("\n���������͂��܂������H(y/n) ");  
        scanf("%c%c",&qq,&zz);
        if(qq == 'y')   break;
    }
    m = b2 / ht ;     n = a[kosu] / hx ;
    /**  ����������� t=0 �ɂ�����l�������� **/
    for(i=1; i<=n-1; i++) {
        x = a[0] + hx * i;
        if(x <= a[1]) { z[i][0] = F1(x); continue; }
        if(x <= a[2]) { z[i][0] = F2(x); continue; }
        if(x <= a[3]) { z[i][0] = F3(x); }
    }
    /**  ���E������� x=0,x=a �ɂ�����l�������� **/
    for(j=0; j<=m; j++) {
        t         = ht * j;
        z[0][j]   = G1(t);
        z[n+1][j] = G2(t);
    }
    s = (hx * hx) / (c * ht);
    p = 2 * (1 + s);    q = 2 * (1 - s);
    b[1][1] = 1.0;      b[n+1][n+1] = 1.0;
    for(i=2; i<=n; i++) {
        b[i][i-1] = 1.0;
        b[i][i]   =  -p;
        b[i][i+1] = 1.0;
    }
    fgusj(n, b, e);     /**  �֐����Ăяo�� **/
    /***  Z(x,t)  �̒l�����߂�  ***/
    for(j=1; j<=m; j++) {
        b[1][n+2] = z[0][j];
        b[n+1][n+2] = z[n+1][j];
        for(i=2; i<=n; i++) {
            b[i][n+2] = -z[i-2][j-1] + 
                        q * z[i-1][j-1] - z[i][j-1];
        }
        for(i=0; i<=n; i++) {
            s = 0.0;
            for(k=1; k<=n+1; k++) {
                s += e[i+1][n+1+k] * b[k][n+2];
            }
            z[i][j] = s;
        }
    }
    printf("\n�v�Z���I�����܂����D���ʂ��o�͂��܂��D\n"); 
    printf("\n�M�`���������@Zt�� %2.0lfZxx ��",c);
    printf("�N�����N�E�j�R���\���@�ɂ�鐔�l��\n\n");
    for(j=0; j<=m; j++) {
        for(i=0; i<=n; i++) {
            printf(" %7.4lf",z[i][j]);
        }
        printf("\n");
    }
    return 0;
}
