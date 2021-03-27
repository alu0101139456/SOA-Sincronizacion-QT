#include "generador_clientes_t.h"

void generador_clientes_t::run()
{
    int i=0;
    forever {
        Cliente_t nuevoCliente(i++);
        cola_->push(nuevoCliente);
        sleep(QRandomGenerator::global()->bounded(2));

  }
}


