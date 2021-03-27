#ifndef COLA_T_H
#define COLA_T_H
#include <memory>
#include <iostream>
#include <QWaitCondition>
#include <QMutex>
#include <cliente_t.h>
#include <QDebug>
#include <unistd.h>
#include <QVector>



template<typename T>
class cola_t
{
 private:
    friend class trabajador_t;
    QMutex mutex_;
    QWaitCondition condition_;

    QVector<T> cola_;
    int limit_=-1;
    int clientes_en_cola_ = 0;


public:
    cola_t() = default;

    cola_t(int limit): limit_(limit){ }

    bool isEmpty() { return cola_.empty(); }

    bool push( const T& data) {
        QMutexLocker lock(&mutex_);

        if( cola_.size() > limit_ ) {
            condition_.wakeAll();
            std::cout << "Cola llena, esperamos un segundo";
            sleep(5);
        }

        if ( cola_.size() < limit_ ){
//        else {
            cola_.push_back(data);
            std::cout << "Entra cliente, ahora hay: " << cola_.size() << "\n";
            condition_.wakeAll();
            return true;
        }


    }

    T pop() {

        QMutexLocker lock(&mutex_);
        if ( !cola_.empty() ) {
            T aux = cola_.front();
            cola_.pop_front();
            return aux;
        }
        if(cola_.empty()){
            std::cout << "Cola vacia, trabajador a descansar\n";
            condition_.wait(&mutex_);
        }

    }


};

#endif // COLA_T_H
