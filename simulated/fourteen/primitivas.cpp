#include<stdio.h>

#define DIF 0.000000001

typedef struct pto2D {
    double x;
    double y;
} Ponto2D;

typedef struct seg2D {
    Ponto2D a;
    Ponto2D b;
} Segmento2D;

inline double abs2(double a) {
	if (a < 0)
		return -a;
	return a;
}

/*
Compara dois valores double
Entrada:
    * Valores a, b
Saída:
    * 0 se a == b
    * 1 se a > b
    * -1 se a < b
Complexidade: O(1)
 */
inline int cmp(double a, double b) {
    if (abs2(a - b) < DIF) {
        return 0;
    } else if (a > b) {
        return 1;
    }
    return -1;
}

/* 
Retorna em que lado está o ponto C em relação ao segmento AB
Entrada: 
    * Pontos A, B, C 
Saída: 
    * -1 se C está à direita de AB
    * 1 se C está à esquerda de AB
    * 0 se C está alinhado com AB 
Complexidade: O(1) 
 */
int lado(Ponto2D a, Ponto2D b, Ponto2D c) {
    double s = a.x*c.y - a.y*c.x + a.y*b.x 
              - a.x*b.y + c.x*b.y - c.y*b.x; //Produto vetorial
    
    if (abs2(s) < DIF) {
        return 0;
    } else if (s < 0) {
        return -1;
    }
    return 1;
}

/* 
Retorna se dois pontos coincidem, ou seja, se um está sobre o outro
Entrada: 
    * Pontos A e B
Saída: 
    * 1 se coincidem
    * 0 se não coincidem
Complexidade: O(1) 
 */
int sobre(Ponto2D a, Ponto2D b) {
    return cmp(a.x, b.x) == 0 && cmp(a.y, b.y) == 0;
}

/* 
Retorna se um ponto P está dentro do segmento AB, mas não coincide com A ou B
Entrada: 
    * Ponto P e segmento AB
Saída: 
    * 1 se P está dentro do segmento AB
    * 0 se P está fora do segmento AB
Complexidade: O(1) 
 */
int emSegmento(Ponto2D p, Segmento2D ab) {
    if (lado(ab.a, ab.b, p) == 0) { //p pertence à reta ab
        if (cmp(ab.a.x, ab.b.x) != 0) { //se AB não for vertical, testa em x, senão testa em y
            return ((cmp(ab.a.x, p.x) < 0 && cmp(p.x, ab.b.x) < 0) ||
                (cmp(ab.a.x, p.x) > 0 && cmp(p.x, ab.b.x) > 0));
        } else {
            return ((cmp(ab.a.y, p.y) < 0 && cmp(p.y, ab.b.y) < 0) ||
                (cmp(ab.a.y, p.y) > 0 && cmp(p.y, ab.b.y) > 0));
        }
    }
    return 0; //se p não pertence à reta ab, certamente ele não estará dentro do segmento ab
}

/* 
Retorna se um ponto P coincide com um extremo do segmento AB
Entrada: 
    * Ponto P e segmento AB
Saída: 
    * 1 se P coincide com um extremo de AB
    * 0 se P não coincide com um extremo de AB
Complexidade: O(1) 
 */
int extremoSegmento(Ponto2D p, Segmento2D ab) {
    return sobre(p, ab.a) || sobre(p, ab.b);
}

int main() {
    Ponto2D a, b, c;
    Segmento2D ab;
    int k;

    scanf("%lf %lf %lf %lf %lf %lf ", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

    k = lado(a,b,c);

    if (k < 0) {
        printf("Direita\n");
    } else if (k > 0) {
        printf("Esquerda\n");
    } else {
        printf("Alinhado\n");
    }

    scanf("%lf %lf %lf %lf %lf %lf ", &ab.a.x, &ab.a.y, &ab.b.x, &ab.b.y, &c.x, &c.y);
    if (emSegmento(c, ab)) {
        printf("Pertence ao segmento\n");
    } else {
        printf("Não pertence ao segmento\n");
    }

    return 0;
}
