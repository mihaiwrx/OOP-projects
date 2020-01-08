#ifndef MONOVOLUM_H
#define MONOVOLUM_H

#include <Vehicle.h>


class Monovolum : public Vehicle
{
    private:
        string nume;
    public:
        Monovolum();
        virtual ~Monovolum();
        Monovolum(const Monovolum& other);
        Monovolum& operator=(const Monovolum& other);

        string Getnume() { return nume; }
        void Setnume(string val) { nume = val; }

        virtual void afisare();

        friend istream& operator>> (istream& in, Monovolum& mi);
        friend ostream& operator<< (ostream& out, Monovolum& mi);
};

#endif // MONOVOLUM_H
