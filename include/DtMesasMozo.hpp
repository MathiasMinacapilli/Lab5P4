#ifndef _DTMESASMOZO_HPP
#define _DTMESASMOZO_HPP

#include <set>
using namespace std;

class DtMesasMozo {
private:
    int codigoMozo;
    set<integer> mesas;
public:
    DtMesasMozo(int codigoMozo, set<int> mesas);
    int getCodigoMozo();
    set<int> getMesas();
    ~DtMesasMozo();
};

#endif