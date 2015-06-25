/**
 * Ejemplo contenedor set
 * 
 * Un set es un contenedor ordenado por los valores que contiene (versus un map
 * que está ordenado por sus claves).
 * 
 * Si se requieren claves diplicadas usar: multiset
 * 
 * En caso que no se requiera que esté ordenado usar: unordered_set 
 * 
 * @author Esteban De La Fuente Rubio
 * @version 2014-09-25
 */

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{

    // ejemplo de set
    set<int> s1;
    cout << "s1.size() = " << s1.size() << endl;
    s1.insert(20);
    s1.insert(30);
    s1.insert(25);
    s1.insert(10);
    s1.insert(15);
    s1.insert(5);
    s1.insert(5);
    s1.insert(15);
    s1.insert(25);
    cout << "s1.size() = " << s1.size() << endl;
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << "\tElem = " << *it << endl;
    }

    // ejemplo de multiset
    multiset<int> s2;
    s2.insert(20);
    s2.insert(30);
    s2.insert(25);
    s2.insert(10);
    s2.insert(15);
    s2.insert(5);
    s2.insert(5);
    s2.insert(15);
    s2.insert(25);
    cout << "s2.size() = " << s2.size() << endl;
    for (set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << "\tElem = " << *it << endl;
    }
    
    // ejemplo de unordered_set
    unordered_set<int> s3;
    s3.insert(20);
    s3.insert(30);
    s3.insert(25);
    s3.insert(10);
    s3.insert(15);
    s3.insert(5);
    s3.insert(5);
    s3.insert(15);
    s3.insert(25);
    cout << "s3.size() = " << s3.size() << endl;
    for (unordered_set<int>::iterator it = s3.begin(); it != s3.end(); it++) {
        cout << "\tElem = " << *it << endl;
    }
    
    // ejemplo de unordered_multiset
    unordered_multiset<int> s4;
    s4.insert(20);
    s4.insert(30);
    s4.insert(25);
    s4.insert(10);
    s4.insert(15);
    s4.insert(5);
    s4.insert(5);
    s4.insert(15);
    s4.insert(25);
    cout << "s4.size() = " << s4.size() << endl;
    for (unordered_multiset<int>::iterator it = s4.begin(); it != s4.end(); it++) {
        cout << "\tElem = " << *it << endl;
    }

    // todo ok
    return 0;

}
