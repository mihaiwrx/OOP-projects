#include "Vehicle.h"

Vehicle::Vehicle()
{
    capacitate = 0;
    nr_locuri = 1;
    lungime = 0;
    pret = 0;
    an_vechime = 0;
}

Vehicle::~Vehicle()
{
    capacitate = 0;
    nr_locuri = 1;
    lungime = 0;
    pret = 0;
    an_vechime = 0;
}

Vehicle::Vehicle(const Vehicle& other)
{
    this->capacitate = other.capacitate;
    this->nr_locuri = other.nr_locuri;
    this->lungime = other.lungime;
    this->pret = other.pret;
    this->an_vechime = other.an_vechime;
}

Vehicle& Vehicle::operator=(const Vehicle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


void Vehicle::afisare()
{
    cout<<capacitate<<endl<<nr_locuri<<endl<<lungime<<endl;
    cout<<pret<<endl<<an_vechime<<endl;
}


istream& operator>> (istream& in, Vehicle& ve)
{
    cout << "Capacitate: ";
    in >> ve.capacitate;
    cout << "Nr locuri: ";
    in >> ve.nr_locuri;
    cout << "Lungime: ";
    in >> ve.lungime;
    cout << "Pret: ";
    in >> ve.pret;
    cout << "An: ";
    in >> ve.an_vechime;
}

ostream& operator<< (ostream& out, Vehicle& ve)
{
    out << ve.capacitate << "\t" << ve.nr_locuri << "\n";
    out << ve.lungime << "\t" << ve.pret << "\t" << ve.an_vechime<<endl;
}
