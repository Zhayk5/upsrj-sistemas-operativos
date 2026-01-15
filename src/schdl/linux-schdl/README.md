# Práctica: Exploración del Scheduler Real en Linux (Ubuntu 22.04)

### Contexto académico

Hasta ahora has estudiado **algoritmos teóricos de planificación**:

* FCFS (First Come First Served)
* SJF (Shortest Job First)
* RR (Round Robin)

En esta práctica explorarás cómo estos conceptos se reflejan (o no) en un **sistema operativo real**: Linux Ubuntu 22.04.

Linux **no implementa literalmente FCFS, SJF o RR**, sino un scheduler moderno llamado **CFS (Completely Fair Scheduler)**. Tu objetivo será **localizar su código fuente**, analizarlo a alto nivel y documentar tus hallazgos.

---

## Objetivo

* Localizar el **código fuente del scheduler real de Linux** usando únicamente comandos básicos.
* Identificar el archivo donde se implementa el scheduler.
* Generar un **script en bash** que documente el proceso y muestre el código relevante con explicaciones.
* El resultado final del script debe ser un `cat` que muestre el código junto con comentarios explicativos.

---

## Restricciones

* **No se permite usar navegador web**
* **No se permite usar editores gráficos (VSCode, nano, vim, etc.)**
* Solo se pueden usar comandos básicos como:

  * `ls`
  * `cd`
  * `cat`
  * `pwd`
  * `echo`
* El análisis debe quedar documentado **dentro del script**, mediante comentarios.

---

## Entregable final

Un archivo script llamado:

```
scheduler_discovery.sh
```

Al ejecutarse, el script debe:

1. Mostrar información contextual (qué se está buscando).
2. Mostrar el **código fuente real del scheduler** mediante `cat`.
3. Incluir **comentarios explicativos** dentro del propio script que expliquen:

   * Qué archivo se está mostrando
   * Qué scheduler implementa
   * Cómo se relaciona con los algoritmos vistos en clase

---

## Guía de exploración (sin comandos explícitos)

### Paso 1 – Identificar dónde vive el kernel

Explora el sistema de archivos hasta localizar el directorio que contiene el **código fuente del kernel Linux** instalado en tu sistema.

Pista: el código del kernel **no está en `/home`**.

---

### Paso 2 – Navegar la estructura del kernel

Una vez dentro del código fuente del kernel:

* Identifica el directorio relacionado con **process scheduling**
* Observa nombres de carpetas que sugieran planificación, tareas o procesos

---

### Paso 3 – Localizar el scheduler principal

Dentro del directorio correcto:

* Busca el archivo que implementa el scheduler por defecto de Linux
* El nombre del archivo es una pista directa del tipo de scheduler utilizado

---

### Paso 4 – Analizar el código

Observa el contenido del archivo:

* Identifica comentarios del propio kernel
* Detecta referencias a fairness, virtual runtime o time slices
* Relaciona estos conceptos con FCFS, SJF y RR

No se espera que entiendas todo el código, sino **qué tipo de estrategia usa Linux para planificar procesos**.

---

### Paso 5 – Crear el script de documentación

Crea un script que:

* Explique en comentarios qué es el CFS
* Indique dónde se encuentra el archivo del scheduler
* Use `cat` para mostrar el código real
* Sea reproducible en cualquier Ubuntu 22.04

---

## Criterios de evaluación

| Criterio                            | Puntos |
| ----------------------------------- | ------ |
| Uso correcto de comandos básicos    | 20     |
| Localización correcta del scheduler | 30     |
| Script funcional                    | 20     |
| Comentarios explicativos claros     | 20     |
| Relación con teoría vista en clase  | 10     |

---

## Pregunta de reflexión (obligatoria)

Responder dentro del script como comentario:

> ¿Por qué Linux no implementa directamente FCFS, SJF o RR como se ven en los libros?

---

## Resultado esperado

Al ejecutar:

```bash
./scheduler_discovery.sh
```

El sistema debe mostrar:

* Explicación del hallazgo
* Ruta del archivo del scheduler
* Código fuente real del scheduler de Linux
