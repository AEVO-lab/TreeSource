//
// Created by Manuel on 2018-11-21.
//

#ifndef DIV_OBJECTPOOL_H
#define DIV_OBJECTPOOL_H


#include <vector>

using namespace std;

template<class T>
class FixedObjectPool {

public:

    FixedObjectPool<T>();

    T GetObject(int n);
private:



    vector<T> objects;

};


#endif //DIV_OBJECTPOOL_H
