#ifndef TRABAJADOR_T_H
#define TRABAJADOR_T_H

#include <QDebug>
#include <cola_t.h>
#include <QThread>
#include <cliente_t.h>
#include <unistd.h>
#include <QMutex>
#include <QWaitCondition>



class trabajador_t : public QThread {
private:
    cola_t<Cliente_t>* cola_;
    int id_=-1;
    Cliente_t vacio;

public:
    trabajador_t() = default;

    trabajador_t(cola_t<Cliente_t>* cola, int id): cola_(cola), id_(id) {}




    virtual void run () override {
        while (true) {

            Cliente_t a = cola_->pop();
            qDebug() << "Trabajador " << id_ << " atendiendo";
            qDebug() << "Tiempo de tramite: " << a.get_time();
            sleep(a.get_time());

        }
    }
};

#endif // TRABAJADOR_T_H
