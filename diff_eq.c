#include <math.h>

long double func_p9 (long double x) {
    return 0.5;
}

long double func_q9 (long double x) {
    return 3.0;
}

long double func_f9 (long double x) {
    return 2 * x * x;
}

long double func_p10 (long double x) {
    return 1.5;
}

long double func_q10 (long double x) {
    return -x;
}

long double func_f10 (long double x) {
    return 0.5;
}

long double func_tp1 (long double x) {
    return 1;
}

long double func_tq1 (long double x) {
    return 0;
}

long double func_tf1 (long double x) {
    return 1;
}

long double func_tp2 (long double x) {
    return 1;
}

long double func_tq2 (long double x) {
    return 1;
}

long double func_tf2 (long double x) {
    return x * x + 2 * x + 2;
}

void var_9 (long double *sigma1,
            long double *sigma2,
            long double *gamma1,
            long double *gamma2,
            long double *delta1,
            long double *delta2,
            long double *x0,
            long double *xn,
            long double (**p) (long double),
            long double (**q) (long double),
            long double (**f) (long double)) {
    *sigma1 = 1;
    *sigma2 = 1;
    *gamma1 = -2;
    *gamma2 = 0;
    *delta1 = 0.6;
    *delta2 = 1;
    *x0 = 1;
    *xn = 1.3;
    *p = &func_p9;
    *q = &func_q9;
    *f = &func_f9;
}

void var_10 (long double *sigma1,
            long double *sigma2,
            long double *gamma1,
            long double *gamma2,
            long double *delta1,
            long double *delta2,
            long double *x0,
            long double *xn,
            long double (**p) (long double),
            long double (**q) (long double),
            long double (**f) (long double)) {
    *sigma1 = 2;
    *sigma2 = 1;
    *gamma1 = -1;
    *gamma2 = 0;
    *delta1 = 1;
    *delta2 = 3;
    *x0 = 1.3;
    *xn = 1.6;
    *p = &func_p10;
    *q = &func_q10;
    *f = &func_f10;
}

void var_t1 (long double *sigma1,
            long double *sigma2,
            long double *gamma1,
            long double *gamma2,
            long double *delta1,
            long double *delta2,
            long double *x0,
            long double *xn,
            long double (**p) (long double),
            long double (**q) (long double),
            long double (**f) (long double)) {
    *sigma1 = 1;
    *sigma2 = 0;
    *gamma1 = 0;
    *gamma2 = 1;
    *delta1 = 0;
    *delta2 = 1;
    *x0 = 0;
    *xn = 1;
    *p = &func_tp1;
    *q = &func_tq1;
    *f = &func_tf1;
}

void var_t2 (long double *sigma1,
            long double *sigma2,
            long double *gamma1,
            long double *gamma2,
            long double *delta1,
            long double *delta2,
            long double *x0,
            long double *xn,
            long double (**p) (long double),
            long double (**q) (long double),
            long double (**f) (long double)) {
    *sigma1 = 1;
    *sigma2 = 0;
    *gamma1 = 0;
    *gamma2 = 1;
    *delta1 = 0;
    *delta2 = 2;
    *x0 = 0;
    *xn = 1;
    *p = &func_tp2;
    *q = &func_tq2;
    *f = &func_tf2;
}

long double t1_real (long double x) {
    return x;
}

long double t2_real (long double x) {
    return x * x;
}

long double q_err (long double *res, long double x0, long long n, long double h, 
                    long double (*real) (long double)) {
    //функция среднеквадратичной ошибки
    long double err = 0;
    for (long long i = 0; i <= n; ++i) {
        err += powl(fabsl(real(x0) - res[i]), 2);
        x0 += h;
    }
    err /= n;
    return sqrtl(err);
}
    
