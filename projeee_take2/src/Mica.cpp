#include "Mica.h"

Mica::Mica()
{
    nume = "NULL";
}

Mica::~Mica()
{
    nume = "NULL";
}

Mica::Mica(const Mica& other)
{
    this->nume = other.nume;
}

Mica& Mica::operator=(const Mica& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Mica::afisare()
{
    cout<<"Afisare mica: " << endl<< nume<<endl;
    Vehicle::afisare();
}

istream& operator>> (istream& in, Mica& mi)
{
    cout<<"Citire Mica: \n";
    cout<<"Nume: ";
    in >> mi.nume;
    in >> *(dynamic_cast<Vehicle*>(&mi));
}
ostream& operator<< (ostream& out, Mica& mi)
{
    out << "Mica:\t";
    out << mi.nume << "\t";
    out << *(dynamic_cast<Vehicle*>(&mi));
}
