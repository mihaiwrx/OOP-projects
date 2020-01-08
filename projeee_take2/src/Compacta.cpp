#include "Compacta.h"

Compacta::Compacta()
{
    nume = "NULL";
    tip = "NULL";
}

Compacta::~Compacta()
{
    nume = "NULL";
    tip = "NULL";
}

Compacta::Compacta(const Compacta& other)
{
    cout<<"Afisare compacta: " << endl<< nume<<"\t"<<tip<<endl;
    Vehicle::afisare();
}

Compacta& Compacta::operator=(const Compacta& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Compacta::afisare()
{
    cout<<"Afisare compacta: " << endl<< nume<<"\t"<<tip<<endl;
    Vehicle::afisare();
}

istream& operator>> (istream& in, Compacta& mi)
{
    cout<<"Citire Compacta: \n";
    cout<<"Nume: ";
    in >> mi.nume;
    in >> mi.tip;
    in >> *(dynamic_cast<Vehicle*>(&mi));
}
ostream& operator<< (ostream& out, Compacta& mi)
{
    out << "Compacta:\t";
    out << mi.nume << "\t";
    out << mi.tip << "\t";
    out << *(dynamic_cast<Vehicle*>(&mi));
}
