#include "Mini.h"

Mini::Mini()
{
    culoare = "NULL";
}

Mini::~Mini()
{
    culoare = "NULL";
}

Mini::Mini(const Mini& other):Vehicle(other)
{
    this->culoare = other.culoare;
}

Mini& Mini::operator=(const Mini& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Mini::afisare()
{
    cout<<"Afisare mini: " << endl<< culoare<<endl;
    Vehicle::afisare();
}


istream& operator>> (istream& in, Mini& mi)
{
    cout<<"Citire mini: \n";
    cout<<"Culoare: ";
    in >> mi.culoare;
    in >> *(dynamic_cast<Vehicle*>(&mi));
}
ostream& operator<< (ostream& out, Mini& mi)
{
    out << "Mini:\t";
    out << mi.culoare << "\t";
    out << *(dynamic_cast<Vehicle*>(&mi));
}
