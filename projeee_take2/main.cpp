#include <iostream>
#include <Vehicle.h>
#include <Mini.h>
#include <Mica.h>
#include <Compacta.h>
#include <Monovolum.h>
#include <vector>
using namespace std;

void meniu()
{
    cout<< "Tipul masinii:\n";
    cout<< "1.Vehicul\n";
    cout<< "2.Mini\n";
    cout<< "3.Mica\n";
    cout<< "4.Compacta\n";
    cout<< "5.Monovolum\n";
}

Vehicle* generator(int type){
    switch(type){
    case 1:
        return new Vehicle();
    case 2:
        return new Mini();
    case 3:
        return new Mica();
    case 4:
        return new Compacta();
    case 5:
        return new Monovolum();
    default:
        return new Vehicle();

        }
}

int main()
{

    vector<Vehicle*> cars;
    int n, opt;

    cout << "Numar de masini de introdus: ";
    cin >> n;
    cars.resize(n);

    for (int i = 0; i< n; i++){
        meniu();
        cin >> opt;
        cars[i]=generator(opt);
        cin >> *cars[i];
        cout << "\n\n";
    }

    return 0;
}
