#ifndef MINI_H
#define MINI_H

#include <Vehicle.h>


class Mini : public Vehicle
{
        private:
        string culoare;
    public:
        Mini();
        virtual ~Mini();
        Mini(const Mini& other);
        Mini& operator=(const Mini& other);

        string Getculoare() { return culoare; }
        void Setculoare(string val) { culoare = val; }

        virtual void afisare();


        friend istream& operator>> (istream& in, Mini& mi);
        friend ostream& operator<< (ostream& out, Mini& mi);

};

#endif // MINI_H
