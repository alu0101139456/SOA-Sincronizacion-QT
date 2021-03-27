#ifndef GENERADOR_CLIENTES_T_H
#define GENERADOR_CLIENTES_T_H

#include <cliente_t.h>
#include <QThread>
#include <cola_t.h>
#include <QRandomGenerator>
#include <QDebug>


class generador_clientes_t : public QThread {

 private:
    cola_t<Cliente_t>* cola_ = nullptr;

public:
    generador_clientes_t(cola_t<Cliente_t>* cola): cola_(cola) {}

 private:
    void run() override;

};

#endif // GENERADOR_CLIENTES_T_H
