#include "expr.h"
#include "stdlib.h"
#include "stdio.h"



struct Expr *mk_plus(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = PLUS;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_minus(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = MINUS;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_times(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret =  malloc(sizeof(struct Expr));
    ret->type = TIMES;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_div(struct Expr *e1, struct Expr *e2) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = DIV;
    ret->subexprs.e1 = e1;
    ret->subexprs.e2 = e2;

    return ret;
}

struct Expr *mk_float(float f) {
    struct Expr *ret = malloc(sizeof(struct Expr));
    ret->type = FLOAT;
    ret->literal = f;

    return ret;
}

/* This function should create the expr (1 + (4 * 5))
 * using the above constructors.
 */
struct Expr *mk_expr1() {
    /* TODO: Your code here */
    struct Expr *e1 = mk_float(1);
    struct Expr *e2 = mk_float(4);
    struct Expr *e3 = mk_float(5);

    struct Expr *mul = mk_times(e2, e3);
    struct Expr *add = mk_plus(e1, mul);

    return add;
}

/* This function should create the expr (1 + (7 / 8))
 * using the above constructors.
 */
struct Expr *mk_expr2() {
    /* TODO: Your code here */
    struct Expr *e1 = mk_float(1);
    struct Expr *e2 = mk_float(7);
    struct Expr *e3 = mk_float(8);

    struct Expr *div = mk_div(e2, e3);
    struct Expr *add = mk_plus(e1,div);

    return add;
}

/* This function should create the expr ((1 / 3) - (4 / (2 + 3)))
 * using the above constructors.
 */
struct Expr *mk_expr3() {
    /* TODO: Your code here */
    struct Expr *e1 = mk_float(1);
    struct Expr *e2 = mk_float(3);
    struct Expr *e3 = mk_float(4);
    struct Expr *e4 = mk_float(2);

    struct Expr *div1 = mk_div(e1,e2);
    struct Expr *add = mk_plus(e4,e2);
    struct Expr *div2 = mk_div(e3,add);
    struct Expr *sub = mk_minus(div1,div2);

    return sub;
}


/*
 * This function should free all memory associated 
 * with the given AST.
*/
void free_expr(struct Expr* e) {
    /* TODO: Your code here */

    if(!e) return;
    if(e->type != FLOAT){
        free_expr(e->subexprs.e1);
        free_expr(e->subexprs.e2);
    }
    
    free(e);
}

/*
 * This function should evaluate the given AST and
 * return the floating-point result.
*/
float eval(struct Expr* e) {
    /* TODO: Your code here */
    if(e==NULL){
        return 0.0;
    }
    if(e->type==FLOAT){
        return e->literal;
    }
    else if(e->type==PLUS){
        return eval(e->subexprs.e1) + eval(e->subexprs.e2);
    }
    else if(e->type==MINUS){
        return eval(e->subexprs.e1) - eval(e->subexprs.e2);
    }
    else if(e->type==TIMES){
        return eval(e->subexprs.e1) * eval(e->subexprs.e2);
    }
    else if(e->type==DIV){
        return eval(e->subexprs.e1) / eval(e->subexprs.e2);
    }
    return 0.0;
}




