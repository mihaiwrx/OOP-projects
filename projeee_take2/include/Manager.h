#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <Vehicle.h>
using namespace std;

template <class T>
class Manager
{
    vector<T> elemente;
    public:
        Manager();
        virtual ~Manager();
};

#endif // MANAGER_H
