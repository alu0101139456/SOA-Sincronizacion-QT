#include <QCoreApplication>
#include <QRandomGenerator>
#include <iostream>

#include <cola_t.h>
#include <cliente_t.h>

#include <QDebug>
#include <QThread>
#include <generador_clientes_t.h>
#include <trabajador_t.h>




int main(void) {
    std::cout << "TEST\n";

    cola_t<Cliente_t> cola_(15);

    generador_clientes_t gen1(&cola_);

    trabajador_t tr1(&cola_,1);
    trabajador_t tr2(&cola_,2);
    trabajador_t tr3(&cola_,3);



    gen1.start();

    tr1.start();
    tr2.start();
    tr3.start();



    gen1.wait();
    tr1.wait();
    tr2.wait();
    tr3.wait();




}
