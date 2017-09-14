#include <iostream>
#include <stdlib.h>
using namespace std;

class matriz{
public:
    //Atributos
    int A[][100];
    int fil;
    int col;

    //Metodos
    matriz(int [][100], int, int); //Costructor de la clase
    matriz(int, int);
    matriz();
    void sumar();
    void restar();
    void multiplicar();
    void gausjordan();
};
//Contructor, el cual sirve para inicializar los atributos
matriz::matriz(int B[100][100], int _fil, int _col)
{//Inicialización de variables
    this->A[100][100] = B[100][100];
    this->fil = _fil;
    this->col = _col;
}

matriz::matriz(int _fil, int _col)
{//Inicialización de variables
    this->fil = _fil;
    this->col = _col;
}

matriz::matriz()
{//Inicialización de variables
    fil = 50;
    col = 50;
}

matriz operator +(const matriz mA, const matriz mB){
    matriz resul;

    for(int i = 0; i < mA.fil; i++){
        for(int j = 0; j < mA.col; j++){
            resul.A[i][j] = mA.A[i][j] + mB.A[i][j];
        }
    }

    return resul;
}
/*void matriz::sumar(int ){

for(i=0;i<fil;i++)
{
    for(j=o;j<col;j++)
    {
        sumM[i][j] = A[i][j] + B[i][j]
    }
}

}
*/

