/**
 * Comparación de tiempo de inserción en:
 *   - set
 *   - unordered set
 *   - multiset
 *   - unordered multiset
 *   - map
 *   - unordered map
 *   - multimap
 *   - unordered multimap
 * 
 * @author Esteban De La Fuente Rubio
 * @version 2014-09-26
 */

#include <iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>

#define N 1000000

using namespace std;

int main()
{
    
    unsigned int i;
    clock_t t1, t2;

    // se necesitan números diferentes y no ordenados, pero no necesariamente
    // aleatorios, por esto es que se copiarán a un arreglo para poder usar los
    // mismos números en cada carga
    srand(time(NULL));
    int numeros[N]; // ¿por qué no usar un vector o array?
    for (i=0; i<N; ++i)
        numeros[i] = rand()%100 + 1;

    cout << "Tiempo que toma cargar " << N << " enteros pseudo-aleatorios en: " << endl;
    
    // caso para set
    set<int> s1;
    t1 = clock();
    for (i=0; i<N; ++i)
        s1.insert(numeros[i]);
    t2 = clock();
    cout << "\tset<int> s1                    => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para unordered_set
    unordered_set<int> s2;
    t1 = clock();
    for (i=0; i<N; ++i)
        s2.insert(numeros[i]);
    t2 = clock();
    cout << "\tunordered_set<int> s2          => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para multiset
    multiset<int> s3;
    t1 = clock();
    for (i=0; i<N; ++i)
        s3.insert(numeros[i]);
    t2 = clock();
    cout << "\tmultiset<int> s3               => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para unordered_multiset
    unordered_multiset<int> s4;
    t1 = clock();
    for (i=0; i<N; ++i)
        s4.insert(numeros[i]);
    t2 = clock();
    cout << "\tunordered_multiset<int> s4     => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para map
    map<int,int> m1;
    t1 = clock();
    for (i=0; i<N; ++i)
        m1[numeros[i]] = numeros[i];
    t2 = clock();
    cout << "\tmap<int,int> m1                => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para unordered_map
    unordered_map<int,int> m2;
    t1 = clock();
    for (i=0; i<N; ++i)
        m2[numeros[i]] = numeros[i];
    t2 = clock();
    cout << "\tunordered_map<int,int> m2      => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para multimap
    multimap<int,int> m3;
    t1 = clock();
    for (i=0; i<N; ++i)
        m3.insert(pair<int,int>(numeros[i], numeros[i]));
    t2 = clock();
    cout << "\tmultimap<int,int> m3           => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // caso para unordered_multimap
    unordered_multimap<int,int> m4;
    t1 = clock();
    for (i=0; i<N; ++i)
        m4.insert(pair<int,int>(numeros[i], numeros[i]));
    t2 = clock();
    cout << "\tunordered_multimap<int,int> m4 => " << ((((float)t2-(float)t1)/1000000.0F)*1000) << "[ms]" << endl;
    
    // todo ok
    return 0;

}
