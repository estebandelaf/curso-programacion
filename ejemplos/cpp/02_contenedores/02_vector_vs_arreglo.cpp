/**
 * Comparación de rendimiento entre un vector y un arreglo
 * 
 * @author Esteban De La Fuente Rubio
 * @version 2014-09-25
 */

#include <time.h>
#include <iostream>
#include <vector>
#include <array>

#define N 1000000

using namespace std;

int main()
{

    int i;
    clock_t t1, t2;
    
    cout << "Tiempo que toma cargar " << N << " enteros en: " << endl;

    // rellenar con datos el vector
    vector<int> v;
    t1 = clock();
    for (i=0; i<N; ++i) {
        v.push_back(i);
    }
    t2 = clock();
    cout << "\tvector<int> v   => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;

    // rellenar con datos el vector
    vector<int> v2(N);
    t1 = clock();
    for (i=0; i<N; ++i) {
        v2[i] = i;
    }
    t2 = clock();
    cout << "\tvector<int> v2  => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;

    // rellenar con datos el arreglo a1
    int a1[N];
    t1 = clock();
    for (i=0; i<N; ++i) {
        a1[i] = i;
    }
    t2 = clock();
    cout << "\tint a1[N]       => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;

    // rellenar con datos el arreglo a2
    array<int,N> a2;
    t1 = clock();
    for (i=0; i<N; ++i) {
        a2[i] = i;
    }
    t2 = clock();
    cout << "\tarray<int,N> a2 => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;

    // todo ok
    return 0;

}
