/***************************************************/
/*   �j���[�g���̍��������ɂ����    newhkn.c    */
/***************************************************/
#include <stdio.h>
#define   N   10
int main(void)
{   int     i, j, n;
    double  a[N][N], s, t, x;
    char    z, zz;
    while( 1 ){
        printf("�j���[�g���̍��������ɂ����\n");
        printf("��ԓ_�̌� n �́H(1<n<9) n=");
        scanf("%d%c",&n,&zz);
        if((n <= 1) || (9 <= n))   continue;
        printf("\n��ԓ_�̍��W����͂��Ă��������D\n");
        for(i=0; i<n; i++) {
            printf(" x(%d)=",i);
            scanf("%lf%c",&a[i][0],&zz);
            printf(" y(%d)=",i); 
            scanf("%lf%c",&a[i][1],&zz);
        }
        printf("\n���������͂��܂������H(y/n)"); 
        scanf("%c%c",&z,&zz);
        if(z == 'y')   break;
    }
    /***  �e�K�����̌v�Z  ***/
    /***  ��2�K������a[i][2]�֓����  ***/
    /***  ��3�K������a[i][3]�֓����  ***/
    for(j=1; j<=n; j++) {
        for(i=0; i<=n-j; i++) {
            a[i][j+1] = (a[i+1][j] - a[i][j]) /
                             (a[i+j][0] - a[i][0]);
        }
    }
    printf("\n�I������ɂ�CTRL+C�������Ă�������\n");
    while( 1 ) {
        printf("�w�肷��_�́H X= ");  
        scanf("%lf%c",&x,&zz);
        s = a[0][1];
        t = 1;
        /***  ���������ɂ��v�Z  ***/
        for(j=2; j<=n; j++) {
            t *= (x - a[j-2][0]);
            s += a[0][j] * t;
        }
        /***  ���̕\��  ***/
        printf("\n f( %10.6lf )= %10.6lf\n",x,s);
    }
    return 0;
}
