#include "diff_eq.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    N = 100
};

int main (int argc, char *argv[]) {
    
    system("rm -f *output");
    
    if (argc < 2) {
        printf("1 argument needed\n");
        return 0;
    }
    
    if (strcmp(argv[1], "--help") == 0) {
        printf("One arguments needed:\n");
        printf("Task number (one of implemented)\n");
        printf("Now implemented: 9, 10\n");
        return 0;
    }
    
    long double sigma1, sigma2, gamma1, gamma2, delta1, delta2, x0, xn;
    long double (*p) (long double);
    long double (*q) (long double);
    long double (*f) (long double);
    
    if (strtol(argv[1], NULL, 10) == 9) {
        var_9 (&sigma1,
            &sigma2,
            &gamma1,
            &gamma2,
            &delta1,
            &delta2,
            &x0,
            &xn,
            &p,
            &q,
            &f);
    } else if (strtol(argv[1], NULL, 10) == 10) {
        var_10 (&sigma1,
            &sigma2,
            &gamma1,
            &gamma2,
            &delta1,
            &delta2,
            &x0,
            &xn,
            &p,
            &q,
            &f);
    } else {
        printf("Invalid function number\n");
        return 0;
    }
    
    long double h = (xn - x0) / N;
    
    matrix *A = new_matrix(N + 1, N + 1);
    matrix *fm = new_matrix(N + 1, 1);
    
    A->elem[0][0] = (sigma1 * h) - gamma1;
    A->elem[1][0] = gamma1;
    fm->elem[0][0] = delta1 * h;
    
    A->elem[N - 1][N] = -gamma2;
    A->elem[N][N] = (sigma2 * h) + gamma2;
    fm->elem[0][N] = delta2 * h;
    
    for (int i = 1; i < N; ++i) {
        A->elem[i - 1][i] = 1 - p(x0 + i * h) * h * 0.5;
        A->elem[i][i] = -2 + q(x0 + i * h) * h * h;
        A->elem[i + 1][i] = 1 + p(x0 + i * h) * h * 0.5;
        fm->elem[0][i] = f(x0 + i * h) * h * h;
    }
    
    long double *ans;
    ans = gauss_method(A, fm, 1);
    
    printf("Started making plot...\n");
    
    FILE *xoutput = fopen("xoutput", "w");
    for (int i = 0; i <= N; ++i) {
        fprintf(xoutput, "%Lf\n", x0 + h * i);
    }
    fclose(xoutput);
    
    FILE *youtput = fopen("youtput", "w");
    for (int i = 0; i <= N; ++i) {
        fprintf(youtput, "%Lf\n", ans[i]);
    }
    fclose(youtput);
    
    system("python3 graph.py");
    
    delete_matrix(A);
    delete_matrix(fm);
    free(ans);
    
    return 0;
}
