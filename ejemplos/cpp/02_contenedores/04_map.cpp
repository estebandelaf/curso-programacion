/**
 * Ejemplo contenedor "map" y "multimap"
 * 
 * Map es un arreglo asociativo (indexado por clave), se define con:
 *   map <A, B>
 * donde A es el tipo de dato de la clave y B el tipo de dato del valor. Notar
 * que si el tipo de datos de la clave es string, entonces las claves serán
 * case-sensitive.
 * 
 * Se pueden hacer mapas de cualquier tipo de datos, incluyendo clases. Y se
 * pueden ir mezclando, ejemplo:
 *   map <string, vector<int>>
 * 
 * En caso que existan elementos repetidos en el mapa se puede usar: multimap
 * 
 * En caso que no sea necesario mantener ordenados los elementos de mapa se
 * puede utilizar: unordered_map
 * 
 * Ya sea map, multimap, unordered_map o unordered_multimap se recorren con
 * iteradores.
 * 
 * A diferencia de un vector, la memoria no es contigua para un contenedor map.
 * Por defecto se tiene un tamaño X, cuando se llena el contenedor crece, al
 * doble(?). Al crecer nada garantizará que es la memoria que fue solicitada sea
 * contigua (a diferencia de un vector), por lo cual la memoria del map queda
 * fragmentada.
 * 
 * @author Carlos Gómez-Pantoja
 * @version 2014-09-12
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{

    // crear dos map: a no permitirá duplicados, b permitirá duplicados
    map<string,int> a;
    multimap<string,int> b;
    
    // Agregamos elementos a map a, Carlos al ser clave única se reemplazará su
    // valor al asignar el valor 20
    a["Carlos"] = 10;
    a["Carlos"] = 20;
    a["Esteban"] = 30;
    
    // Agregamos elementos a map b
    // Se debe usar b.insert(), porque con la forma anterior (b["Carlos"]) no se
    // sabría si se quiere insertar uno nuevo valor o sobreescribir el anterior
    b.insert(pair<string,int>("Carlos", 10));
    b.insert(pair<string,int>("Carlos", 20));
    b.insert(pair<string,int>("Esteban", 30));
    b.insert(pair<string,int>("Juan", 40));
    
    // recorrer el map a
    cout << "a.size() = " << a.size() << endl;
    for (map<string,int>::iterator iter = a.begin();
                                                    iter != a.end(); iter++) {
        cout << "\tElem=" << (*iter).first << " " << (*iter).second << endl;
    }
    
    // recorrer el map b
    cout << "b.size() = " << b.size() << endl;
    for (multimap<string,int>::iterator iter = b.begin();
                                                    iter != b.end(); iter++) {
        cout << "\tElem=" << (*iter).first << " " << (*iter).second << endl;
    }

    // valor por defecto de inserción en el caso de enteros es 0, entonces si
    // se usa cout de algo que no existe se insertará con valor 0
    cout << "a[\"Juan\"] = " << a["Juan"] << endl;

    // si lo que se quiere es buscar si existe una clave utilizar count
    cout << "a.count(\"Juan\") = " << a.count("Juan") << endl;
    cout << "a.count(\"Pedro\") = " << a.count("Pedro") << endl;
    cout << "a.count(\"Carlos\") = " << a.count("Carlos") << endl;
    cout << "a.count(\"Esteban\") = " << a.count("Esteban") << endl;

    cout << "b.count(\"Juan\") = " << b.count("Juan") << endl;
    cout << "b.count(\"Pedro\") = " << b.count("Pedro") << endl;
    cout << "b.count(\"Carlos\") = " << b.count("Carlos") << endl;
    cout << "b.count(\"Esteban\") = " << b.count("Esteban") << endl;

    // claves son case-sensitive
    cout << "b.count(\"esteban\") = " << b.count("esteban") << endl;
    
    // en un map si queremos imprimir un valor solo si existe, basta verificar
    // que exista la clave, si existe se muestra el valor
    if (a.count("Carlos")) {
        cout << "a[\"Carlos\"] = " << a["Carlos"] << endl;
    }
    if (a.count("Pedro")) {
        cout << "a[\"Pedro\"] = " << a["Pedro"] << endl;
    }

    // en un multimap pueden haber varios valores, por lo cual (como se vió
    // antes) no sirve usar b["Carlos"], se debe iterar para mostrar todas las
    // claves con valor Carlos
    // se recorre todo el multimap, y se imprimen los que la clave sea Carlos
    for (multimap<string,int>::iterator iter = b.begin();
                                                    iter != b.end(); iter++) {
        if ((*iter).first == "Carlos") {
            cout << "\tElem=" << (*iter).first << " " << (*iter).second << endl;
        }
    }

    // se utiliza find para encontrar el primer Carlos (claves están ordenadas
    // en un multimap) y se imprime hasta encontrar algo distinto a Carlos
    multimap<string,int>::iterator it = b.find("Carlos");
    while (it != b.end() && (*it).first == "Carlos") {
        cout << "\tElem=" << (*it).first << " " << (*it).second << endl;
        it++;
    }

    // borrar clave en un map
    cout << "a.size() = " << a.size() << endl;
    a.erase("Esteban");
    cout << "a.size() = " << a.size() << endl;
    a.erase(a.begin(), a.end());
    cout << "a.size() = " << a.size() << endl;
    
    // para borrar en un rango se puede usar find
    // TODO: escribir ejemplo
    
    // borrar clave en multimap
    // TODO: escribir ejemplo
    
    return 0;

}
