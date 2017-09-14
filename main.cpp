#include <iostream>
#include "matrix.h"
#include "matrix.cpp"


using namespace std;

int main()
{
    // Para no generar los mismos números aleatorios
    srand(time(NULL));

    cout << "Hello world!" << endl;

    matrix<int> a(3, 3);
    //a.entrada_aleatoria();
    a.entrada_por_usuario();
    a.imprimir_matriz();

    srand(time(NULL));
    matrix<int> b(3, 3);
    //b.entrada_aleatoria();
    b.entrada_por_usuario();
    b.imprimir_matriz();


    matrix<int> c(3, 3);
    c = a - b;
    c.imprimir_matriz();


    return 0;
}
