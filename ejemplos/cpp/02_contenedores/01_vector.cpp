/**
 * Ejemplo contenedor "vector"
 * Referencia: http://www.cplusplus.com/reference/vector/vector
 * 
 * Un vector básicamente es un arreglo (espacio contiguo en memoria) que puede 
 * cambiar de tamaño. Consume más memoria que una arreglo (ya que reserva 
 * memoria para crecimiento), pero tiene la ventaja de poder crecer.
 * 
 * Preguntas:
 *  1. ¿Cuál es la principal diferencia entre el vector v y w?
 * 
 * @author Esteban De La Fuente Rubio
 * @version 2014-09-25
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    unsigned int i, size;

    // crear vector
    vector<int> v, w(20);

    // consultar tamaño inicial y tamaño máximo que podría llegar a tener
    cout << "v.size() = " << v.size() << endl;
    cout << "v.max_size() = " << v.max_size() << endl;

    // agregar elementos al vector uno por uno al final del vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(5);
    v.push_back(25);
    v.push_back(15);

    // mostrar nuevo tamaño y elementos del vector
    cout << "v.size() = " << v.size() << endl;
    size = v.size();
    for (i=0; i<size; ++i)
        cout << "v["<< i << "] = " << v[i] << endl;

    // ¿por qué esto falla?
    /*size = v.size();
    for (i=size; i<(size+10); ++i)
        v[i] = i;*/

    // cambiar valores del vector w y mostrar
    size = w.size();
    for (i=0; i<size; ++i)
        w[i] = i;
    cout << "w.size() = " << w.size() << endl;

    // mostrar
    size = w.size(); // innecesario, pero para enfatizar
    for (i=0; i<size; ++i)
        cout << "w["<< i << "] = " << w[i] << endl;

    // todo ok
    return 0;

}
