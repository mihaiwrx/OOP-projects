#include "Manager.h"

template <class T>
Manager::Manager()
{
    elemente.resize(0);
}

Manager::~Manager()
{
    elemente.clear();
}
