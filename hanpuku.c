/******************************************************/
/*     �����@�ɂ���Ĉ�̌ŗL�l�����߂�v���O����   */
/*                                      hanpuku.c     */
/******************************************************/
#include <stdio.h>
#include <math.h>
#define     N       10
int main(void)
{   int     i, j, m, n, k, ff;
    static double  min, max, s, w, f1, a[N][N], x[N]; 
    static double  ax[N], e[N], f[N];
    char    z, zz;
    /* a[][]:���͍s�� x[]:�ŗL�x�N�g�� e[]:�ŗL�l */
    while( 1 ){
        printf("�����@�ɂ���ČŗL�l������߂܂��D\n");
        printf("\n �s��̎����́D(1<n<10) n= ");
        scanf("%d%c",&n,&zz);  printf("\n");
        if((n <= 1) || (10 <= n))   continue;
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                printf("a( %1d , %1d ) = ",i,j);   
                scanf("%lf%c",&a[i][j],&zz);
            }
            printf("\n");
        }
        printf("\n���������͂��܂������H(y/n) ");   
        scanf("%c%c",&z,&zz);
       if(z == 'y')   break; 
    }
    for(i=1; i<=n; i++)   x[i] = 1.0; 
    ff = 100;
    while( 1 ){
        for(m=1;  m<=100;  m++){
            for(i=1; i<=n; i++){ 
                s = 0.0;
                for(j=1; j<=n; j++)  s += a[i][j]*x[j];
                ax[i] = s;
            }
            for(j=1; j<=n; j++) { 
                if(fabs(x[j])>1.0e-6)  e[j]=ax[j]/x[j]; 
            }
            for(j=1; j<=n-1; j++){  
                if(fabs(e[j]-e[j+1])<1.0e-6)  f[j]=1.0; 
            }
            if(fabs(e[n]-e[1])<1.0e-6)  f[n] = 1.0; 
            f1 = 1.0;
            for(i=1; i<=n; i++)   f1 = f1 * f[i];  
            if(f1 == 1.0)   break;  
            s = 0.0;
            for(k=1; k<=n; k++)  s += ax[k] * ax[k];
            w = sqrt(s);
            for(i=1; i<=n; i++)  x[i] = ax[i] / w; 
        }   
        if(ff == 1)  e[1] += 1.0;  
        if(f1 == 1.0){
            printf("��̌ŗL�l  %10.6lf",e[1]);
            printf("�i������ %2d ��j\n",m);
            break;
        }else
            printf("������ %3d��Ŏ������܂���D\n",m); 
        if(ff == 1)   return(-1);
        printf("�Ίp�������������炵�Ă���ɔ������܂��D\n");
        printf("�G���^�[�L�[�������Ă��������D\n\n");  
        scanf("%c",&zz);
        for(i=1; i<=n; i++)  a[i][i] = a[i][i] - 1.0; 
        ff = 1;
    }
    /***  �ŗL�x�N�g���̐����̍ő�l�����߂�  ***/
    max = 0.0;
    for(i=1; i<=n; i++){
        if(max < fabs(x[i]))  max = fabs(x[i]);   
    }
    if(max == 0.0){   
        printf("\n�ŗL�x�N�g���͋��߂��܂���D\n");  
        return(-1);
    }
    /***  �ŗL�x�N�g���̐����̍ŏ��l�����߂� ***/
    min = max;
    for(i=1; i<=n; i++){
        if(fabs(x[i]) == 0 )   continue; 
        if(min > fabs(x[i]))   min = fabs(x[i]); 
    }
    printf("\n�Ή������̌ŗL�x�N�g��\n");
    for(i=1; i<=n; i++){
        x[i] = x[i] / min;
        printf("     %10.6lf\n",x[i]);
    }
    return 0;
}
