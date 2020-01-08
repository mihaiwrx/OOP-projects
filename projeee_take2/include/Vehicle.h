#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{

    private:
        float capacitate;
        int nr_locuri;
        float lungime;
        float pret;
        int an_vechime;

    public:
        Vehicle();
        virtual ~Vehicle();
        Vehicle(const Vehicle& other);
        Vehicle& operator=(const Vehicle& other);

        float get_capacitate() { return capacitate; }
        void set_capacitate(float val) { capacitate = val; }
        int get_nr_locuri() { return nr_locuri; }
        void set_nr_locuri(int val) { nr_locuri = val; }
        float get_lungime() { return lungime; }
        void set_lungime(float val) { lungime = val; }
        float get_pret() { return pret; }
        void set_pret(float val) { pret = val; }
        int get_an_vechime() { return an_vechime; }
        void set_an_vechime(int val) { an_vechime = val; }

        virtual void afisare();
        friend istream& operator>> (istream& in, Vehicle& ve);
        friend ostream& operator<< (ostream& out, Vehicle& ve);

};

#endif // VEHICLE_H
