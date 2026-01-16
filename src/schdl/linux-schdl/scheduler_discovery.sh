pwd
#muestra el directorio actual
ls /
#lista los directorios principales del sistema
cd /usr/src
ls
#cd cambia directorio y ls muestra contenido
cd linux-headers-5.15.0*/
#accede al arbol de kernel
include kernel arch
#ahi vive el scheduler
cd kernel
#exploras kernel
cd shced
ls
#lista los archivos
cat fair.c 
#muestra el codigo completo del scheduler

#Por que linux no implementa directamente FCFS, SJF o RR como se ven en los libros?
#Los algoritmos  porque no pueden cargar bien en el sistema