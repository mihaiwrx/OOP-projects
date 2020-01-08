#ifndef COMPACTA_H
#define COMPACTA_H

#include <Vehicle.h>


class Compacta : public Vehicle
{
    private:
        string nume;
        string tip;
    public:
        Compacta();
        virtual ~Compacta();
        Compacta(const Compacta& other);
        Compacta& operator=(const Compacta& other);

        string Getnume() { return nume; }
        void Setnume(string val) { nume = val; }
        string Gettip() { return tip; }
        void Settip(string val) { tip = val; }


        virtual void afisare();


        friend istream& operator>> (istream& in, Compacta& mi);
        friend ostream& operator<< (ostream& out, Compacta& mi);
};

#endif // COMPACTA_H
