Juego de la vida
================

Juego escrito en C desarrollado durante el curso de C moderno ofrecido por la Universidad de Sevilla, curso 2018/2019.

#¿Qué es el juego de la vida?

El juego de la vida es un juego de lógica bastante popular del cual hay implementaciones hechas en prácticamente todos los lenguajes de programación. Más información en este artículo de Wikipedia: https://es.wikipedia.org/wiki/Juego_de_la_vida


#Requisitos

Tener el paquete build-essential instalado (Debian & Ubuntu).
```
sudo apt-get install build-essential
```

#Compilar & Ejecutar

Desde el directorio, lanzar el siguiente comando para compilar:
```
make
```
a continuación, ejecutar con:
```
./exec
```
o con
```
make run
```

#Tests

Para realizar un test de memoria con valgrind, ejecutar:
```
make test
```