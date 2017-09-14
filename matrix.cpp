#include "matrix.h"

//Definicion de la clase
//Constructor por defecto
template<typename T>
matrix<T>::matrix(){
    m_fil = 2;
    m_col = 2;
}

//Constructor para hacer copia (asignacion)
template<typename T>
matrix<T>::matrix(const matrix &m){
    *this = m;
}

//Constructor por parametro
template<typename T>
matrix<T>::matrix(int fil, int col){
    m_fil = fil;
    m_col = col;
    m_matrix = new T*[m_fil];


    for (int i = 0; i < m_fil; i++){
        m_matrix[i] = new T[m_col];
    }
}

//Destructor por parametro
template<typename T>
matrix<T>::~matrix(){
    //delete this;
}

//suma de matrices con sobrecarga de operadores
template<typename T>
matrix<T> matrix<T>::operator+ (const matrix &matrix_2){
    matrix matrix_result(m_fil, m_col);
    for (int i = 0; i < m_fil; i++) {
        for (int j = 0; j < m_col; j++) {
            matrix_result.m_matrix[i][j] = m_matrix[i][j] + matrix_2.m_matrix[i][j];
        }
    }
    return matrix_result;
}

// Resta de matrices con sobrecarga de operadores
template<typename T>
matrix<T> matrix<T>::operator- (const matrix &matrix_2){
    matrix matrix_result(m_fil, m_col);
    for (int i = 0; i < m_fil; i++) {
        for (int j = 0; j < m_col; j++) {
            matrix_result.m_matrix[i][j] = m_matrix[i][j] - matrix_2.m_matrix[i][j];
        }
    }
    return matrix_result;
}

//Multiplicación de matrices con sobrecarga de operadores
template<typename T>
matrix<T> matrix<T>::operator* (const matrix &matrix_2){
    matrix matrix_result(matrix_2.m_row, matrix_2.m_col);
    T total;

    for (int i = 0; i < m_fil; i++) {
        for (int j = 0; j < matrix_2.m_col; j++) {
            for (int k = 0; k < m_col; k++) {
                total += (m_matrix[i][k] * matrix_2.m_matrix[k][j]);
            }
            matrix_result.m_matrix[i][j] = total;

            // Limpiar el total sumado arriba
            total = 0;
        }
    }
    return matrix_result;
}

// Imprimir Matriz
template<typename T>
void matrix<T>::imprimir_matriz()
{
    for (int i = 0; i < m_fil; i++) {
        for (int j = 0; j < m_col; j++) {
            cout << m_matrix[i][j] << " ";
        }
        cout << endl << endl;
    }
    cout << endl << endl;
}

// Multiplicar a una Matriz por un escalar
template<typename T>
void matrix<T>::multiplicar_por_escalar(T scalar)
{
    for (int i = 0; i < m_fil; i++) {
        for (int j = 0; j < m_col; j++) {
            m_matrix[i][j] = m_matrix[i][j] * scalar;
        }
    }
    cout << "Se multiplicó a la Matriz por el escalar " << scalar << endl;
}


// Llenar una Matriz desde teclado
template<typename T>
void matrix<T>::entrada_por_usuario()
{
    for (int i = 0; i < m_fil; i++) {
        cout << "Fila " << i + 1 << endl;
        for (int j = 0; j < m_col; j++) {
            cout << "Ingresa el elemento " << j + 1 << endl;
            cin >> m_ele;
            m_matrix[i][j] = m_ele;
        }
        cout << endl;
    }
    m_max = m_matrix[0][0];
    m_min = m_matrix[0][0];
}

// Llenar aleatoriamente una Matriz
template<typename T>
void matrix<T>::entrada_aleatoria()
{
    srand(time(NULL));
    for (int i = 0; i < m_fil; i++) {
        for (int j = 0; j < m_col; j++) {
            m_matrix[i][j] = rand() % 30;
        }
    }

    m_max = m_matrix[0][0];
    m_min = m_matrix[0][0];
}
