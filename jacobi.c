/***************************************************/
/*    �Ώ̍s��̌ŗL�l�C�ŗL�x�N�g���i���R�r�@�j   */
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
        printf("�Ώ̍s��̌ŗL�l�C�ŗL�x�N�g��");
        printf("�i���R�r�@�j\n\n");
        printf(" �s��̎�������� (1<n<10) n = ");    
        scanf("%d%c",&n,&zz );
        if((n <= 1) || (10 <= n))    continue; 
        printf("\n�Ώ̍s��̏�O�p�����̓���\n\n");
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
        printf("\n���������͂��܂������H(y/n) ");   
        scanf("%c%c",&qq,&zz);
        if(qq == 'y')   break; 
    }
    printf("���͂����s��\n");   output(n,a);
    printf("\n�G���^�[�L�[�������ΑΊp���v�Z��");
    printf("�J�n���܂��D\n");  
    scanf("%c",&zz);
    for(l=1; l<=100; l++) {
    /* ��Ίp�����̒������Βl�̍ő�̐�����T�� */
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
        /***   �Ƃ����߂�  ***/
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
        printf("\n������ = %d���\n",l);   
        output(n,a);
        /**  ��Ίp���������ׂė�ɋ߂Â������𒲂ׂ�  **/
        /**  �����𔻒肷��D **/
        check = 0;
        for(i=1; i<=n; i++) {
            for(j=i+1; j<=n; j++) {
                if(fabs(a[i][j]) < 0.000001) 
                       check += 1;
            }
        }
        if(check == (n * n - n) / 2)  break; 
        if(l % 3 == 0) {
        printf("\n�G���^�[�L�[�������Ύ��ɐi�݂܂��D");   
        scanf("%c",&zz);   
        }
    }
    printf("\n\n�Ίp�����I�����܂����D");
    printf("�G���^�[�L�[�������Ă��������D\n");  
    scanf("%c",&zz);
    printf("       �v�Z���ʂ̏o��\n");
    printf("\n���͂����s��̏o��\n");        
    output(n,b);
    printf("\n�ŗL�l�̏o��\n");
    for(i=1; i<=n; i++)
        printf(" %10.6lf",a[i][i]);    
    printf("\n\n");
    printf("�ŗL�x�N�g���̏o��");
    printf("�i��̌ŗL�l�ɍ����珇�ɑΉ��j\n");    
    output(n,t0);
    return 0;
}