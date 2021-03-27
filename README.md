# Problemas de sincronización

### Práctica 1 Sistemas Operativos Avanzados
### Alumno: Ángel Julián Bolaño Campos

## Cómo compilar/probar

Para  ejecutar el programa simplemente debe clonarse el repositorio

~~~
    $ git clone https://github.com/ull-esit-sistemas-operativos/soa-1920-sincronizacion-alu0101139456.git ~/P1_Sincro_alu0101139456
    $ make
    $ ./p1
~~~

## Requisitos adicionales

Tener instalado [Qt Creator](https://www.qt.io/download)

## Implementaciones

Se hace uso de:
1. std::shared_ptr<T>
2. std::atomic_compare_exchange_weak
3. QThread
4. QMutex
5. QWaitCondition



