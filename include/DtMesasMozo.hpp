#ifndef _DTMESASMOZO_HPP
#define _DTMESASMOZO_HPP

#include <set>
using namespace std;

class DtMesasMozo {
private:
    int codigoMozo;
    set<int> mesas;
public:
    //Constructor
    DtMesasMozo(int codigoMozo, set<int> mesas);

    //Destructor
    ~DtMesasMozo();

    //Getters
    int getCodigoMozo();
    set<int> getMesas();
};

#endif
