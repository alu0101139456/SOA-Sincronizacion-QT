#ifndef CLIENTE_T_H
#define CLIENTE_T_H

#include <QRandomGenerator>

class Cliente_t
{
 private:
    int numero_ = 0;
    int tramite_ = 0;
 public:

    Cliente_t() = default;
    Cliente_t(int n): numero_(n) {
       tramite_ = QRandomGenerator::global()->bounded(3);

    }
    ~Cliente_t() {}


    inline int get_number(void) { return numero_; }
    inline int get_time(void) {
        if( tramite_ > 3)
            return 1;
        else return tramite_;
    }
};



#endif // CLIENTE_T_H

