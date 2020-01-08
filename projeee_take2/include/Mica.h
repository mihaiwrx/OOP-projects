#ifndef MICA_H
#define MICA_H

#include <Vehicle.h>


class Mica : public Vehicle
{
    private:
        string nume;
    public:
        Mica();
        virtual ~Mica();
        Mica(const Mica& other);
        Mica& operator=(const Mica& other);

        string Getnume() { return nume; }
        void Setnume(string val) { nume = val; }

        virtual void afisare();

        friend istream& operator>> (istream& in, Mica& mi);
        friend ostream& operator<< (ostream& out, Mica& mi);
};

#endif // MICA_H
