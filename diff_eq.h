long double func_p9 (long double x);
long double func_q9 (long double x);
long double func_f9 (long double x);

long double t1_real (long double x);
long double t2_real (long double x);

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
            long double (**f) (long double));
            
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
            long double (**f) (long double));
            
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
            long double (**f) (long double));
            
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
            long double (**f) (long double));
            
long double q_err (long double *res, long double x0, long long n, long double h, 
                    long double (*real) (long double));
