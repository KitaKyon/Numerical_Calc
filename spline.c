/*****************************************************/
/*   �X�v���C���֐��̌��� (1���W���@)    spline.c    */
/*   �X�v���C���֐������߂�D����ɓ������݂�x�̒l�� */
/*   �΂���֐��l�����߂Č��ʂ𐔕\�̌`�ŏo�͂���D  */
/*****************************************************/
#include <stdio.h>
#include <math.h>
#define     N    10
int main(void) 
{   int     i, j, k, m, n, kz, z, lp;
    double  A[N], B[N], C[N+2], D[N], h[N], x[N];
    double  y[N], u[N], p[N+2][N+3]; 
    double  g, q, xw, s, f;
    char    qq, zz;
    /* h[]:hj  u[]:uj  A[],B[],C[],D[]:Aj,Bj,Cj,Dj */  
    /* p[][]:�A���������̌W���z��  */
    /* x, y �Ɋւ���f�[�^�̓���  */
    while( 1 ){
        printf("�X�v���C���֐��̌��� (1���W���@) \n\n");
        printf("�f�[�^�̌��͉��ł����H(2<m<10) m = ");  
        scanf("%d%c",&m,&zz);
        if((m <= 2) || (10 <= m))   continue;
        n = m - 1;
        for(i=0; i<=n; i++) {
            printf("x(%d)= ",i);  scanf("%lf%c",&x[i],&zz);
            printf("y(%d)= ",i);  scanf("%lf%c",&y[i],&zz);
        }
        printf("\n�S��Ԃ̍��[�_�ɂ�����1�������W���́H");
        scanf("%lf%c",&C[1],&zz);
        printf("\n�S��Ԃ̉E�[�_�ɂ�����1�������W���́H"); 
        scanf("%lf%c",&C[n+1],&zz);
        printf("\n���������͂��܂������H(y/n) ");   
        scanf("%c%c",&qq,&zz);
        if(qq == 'y')   break;
    }
    for(i=1; i<=n; i++) {
        D[i]  = y[i-1];
        h[i]  = x[i] - x[i-1];
        u[i]  = (y[i] - y[i-1]) / h[i];
    }
    for(i=1; i<=n+1; i++)
        for(j=1; j<=n+2; j++)
            p[i][j] = 0.0;
    /*  �Q�������瓾����A���������̌W���� */
    /*  �z�� p �ɓ����D*/
    p[1][1]    = 1.0;
    p[n+1][n+1]= 1.0;
    p[1][n+2]  = C[1];
    p[n+1][n+2]= C[n+1];
    for(j=2; j<=n; j++) {
        p[j][j-1] = h[j];
        p[j][j]   = 2*(h[j-1] + h[j]);
        p[j][j+1] = h[j-1];
        p[j][n+2] = 3*(h[j]*u[j-1] + h[j-1]*u[j]);
    }
    /*  �K�E�X�E�W�����_���i�|���o���j�@�ɂ�� */
    /*  �A�������������� */
    for(i=1; i<=n+1; i++) {
        q = p[i][i];
        for(j=1; j<=n+2; j++)
            p[i][j] = p[i][j] / q;
        for(k=1; k<=n+1; k++) {
            g = p[k][i];
            if(k != i) {
                for(j=1; j<=n+2; j++)
                    p[k][j] = p[k][j] - g * p[i][j];
            }
        }
    }
    /*  ��œ���ꂽ����z�� C �ɓ����D*/
    for(j=1; j<=n; j++)
        C[j] = p[j][n+2];
    /*  B1,B2,�E�E�E,Bn�����߂�D*/
    for(j=1; j<=n-1; j++)
        B[j] = (3*u[j]-2*C[j]-C[j+1]) / h[j];
    B[n] = -(3*u[n-1]-C[n-1]-2*C[n]) / h[n-1];
    /*  A1,A2,�E�E�E,An�����߂�D*/
    for(j=1; j<=n-1; j++)
        A[j] = (B[j+1] - B[j]) / (3 * h[j]);
    A[n] = (u[n] - h[n] * B[n] - C[n]) / (h[n] * h[n]);
    /*  ���ʂ��o�͂���  */	
    printf("�e��Ԃ̃X�v���C���֐��̌W�����o�͂��܂�\n");
    printf("(X-Xj)�̍~�ׂ��̏��i�W��Aj,Bj,Cj,Dj�̒l�j\n");
    for(i=1; i<=n; i++ ) {
        printf("S%d(x)=",i);
        printf("(%6.3lf)(x-%6.3lf)^3+",A[i],x[i-1]);
        printf("(%6.3lf)(x-%6.3lf)^2+",B[i],x[i-1]);
        printf("(%6.3lf)(x-%6.3lf)+",C[i],x[i-1]);
        printf("(%6.3lf)\n",D[i]);
    }
    /* ���߂��X�v���C���֐����g���ĕ�Ԓl�����߂� */
    printf("x���W�͈̔͂����������ĕ�Ԓl�����߂܂����H\n");
    scanf("%d",&kz);
    xw = ( x[n] - x[0] ) / kz;
    for(z=1, s=x[0], lp=0; lp <= kz; lp++  ){
        if(z >= m) z--;
        f = A[z] * pow((s-x[z-1]),3.0) + B[z] * 
            pow((s-x[z-1]),2.0)+C[z]*(s-x[z-1])+D[z];
        printf("%10.6lf  %10.6lf\n",s,f);
        s = s + xw;
        if(s > x[z])  z++;
    }
    return 0;
}
