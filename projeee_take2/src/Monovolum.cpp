#include "Monovolum.h"

Monovolum::Monovolum()
{
    nume = "NULL";
}

Monovolum::~Monovolum()
{
    nume = "NULL";
}

Monovolum::Monovolum(const Monovolum& other)
{
   this->nume = other.nume;
}

Monovolum& Monovolum::operator=(const Monovolum& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Monovolum::afisare()
{
    cout<<"Afisare Monovolum: " << endl<< nume<<endl;
    Vehicle::afisare();
}

istream& operator>> (istream& in, Monovolum& mi)
{
    cout<<"Citire Monovolum: \n";
    cout<<"Nume: ";
    in >> mi.nume;
    in >> *(dynamic_cast<Vehicle*>(&mi));
}
ostream& operator<< (ostream& out, Monovolum& mi)
{
    out << "Monovolum:\t";
    out << mi.nume << "\t";
    out << *(dynamic_cast<Vehicle*>(&mi));
}
