#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <time.h>
#include <stdlib.h>

//Declaracion de la clase
using namespace std;

template <class T>
class matrix{
    public:
        matrix();
        matrix(int, int);
        matrix(const matrix &m);
        ~matrix();

        matrix<T> operator +(const matrix &matrix_2);
        matrix<T> operator -(const matrix &matrix_2);
        matrix<T> operator *(const matrix &matrix_2);


        void imprimir_matriz();
        void multiplicar_por_escalar(T);
        void entrada_por_usuario();
        void entrada_aleatoria();

    private:
        T m_ele;
        T m_max;
        T m_min;
        T m_mode; //MMM
        T **m_matrix;

        int m_dim_matrix;
        int m_col;
        int m_fil;
};

#endif // MATRIX_H
