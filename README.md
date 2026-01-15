# Repositorio de Prácticas – Sistemas Operativos

## Propósito del repositorio

Este repositorio contiene las prácticas del curso de Sistemas Operativos.
Cada práctica está diseñada para que el alumno:

* Implemente funcionalidades en C y/o scripts en Linux
* Valide su solución mediante unit testing
* Entregue su trabajo usando GitHub y GitHub Actions
* Experimente un flujo de trabajo similar al usado en la industria

---

## Organización general del repositorio

```
.
├── src/
│   ├── schdl/          # Prácticas de scheduling (FCFS, RR, SJF, etc.)
│   └── ...             # Otras prácticas futuras
│
├── test/
│   ├── Makefile        # Compilación y ejecución de unit tests
│   ├── test_*.c        # Unit tests asociados a las prácticas
│
├── .github/
│   └── workflows/
│       └── *.yml       # Workflows de GitHub Actions (CI)
│
└── README.md           # Este archivo
```

Cada subdirectorio dentro de `src/` puede contener su propio `README.md` con instrucciones específicas de la práctica.

---

## Flujo de trabajo esperado

### 1. Sincronizar tu fork con el tag del profesor

Para cada práctica, el profesor indicará un **tag específico** que debes usar como base:

1. Clona tu fork (si no lo has hecho):

```bash
git clone <tu-fork-url>
cd <nombre-del-repo>
```

2. Agrega el repositorio del profesor como remoto (solo si no lo tienes aún):

```bash
git remote add os-base <repo-del-profesor-os-base>
```

3. Trae el tag correspondiente:

```bash
git fetch os-base tag <TAG_DE_LA_PRACTICA>
```

4. Haz checkout de ese tag en tu branch local de trabajo:

```bash
git checkout -b practica-X FETCH_HEAD
```

5. Mergea los contenidos del tag con tus cambios actuales (si los hay):

```bash
git merge practica-X
```

> Esto asegura que siempre trabajas sobre la **base correcta** indicada para la práctica.

---

### 2. Leer las instrucciones de la práctica

* Cada práctica tiene un `README.md` dentro de su carpeta correspondiente en `src/`
* Lee cuidadosamente los objetivos y restricciones
* Respeta qué archivos se pueden modificar y cuáles no

---

### 3. Implementar la solución

* Trabaja únicamente en los archivos indicados para el alumno
* No modifiques:

  * Infraestructura común (`process.h`, `process.c`)
  * Unit tests
  * Workflows de GitHub Actions
* Sigue buenas prácticas de programación en C y Linux

---

### 4. Validar localmente con unit tests

Antes de hacer cualquier commit, valida tu solución localmente:

```bash
cd test
make clean
make
make run
```

* Todos los tests deben pasar
* Si algún test falla, corrígelo antes de continuar

---

### 5. Commit y push a GitHub

Una vez que los tests pasen localmente:

```bash
git add .
git commit -m "Entrega práctica X"
git push
```

Puedes trabajar en cualquier branch.

---

### 6. Activar y validar GitHub Actions

1. Si es la primera vez en tu fork, asegúrate de **activar GitHub Actions** en tu repositorio.
2. Después del push:

   * Ve a la pestaña **Actions**
   * Revisa el workflow correspondiente
3. El resultado esperado:

```
✔ Workflow completed successfully
```

Si el workflow falla, la práctica no se considera aprobada.

---

## Evaluación automática (CI)

* Cada commit dispara automáticamente el workflow
* El código se compila en Ubuntu 22.04
* Se ejecutan los unit tests oficiales
* Un solo test fallido implica entrega fallida

Esto garantiza:

* Evaluación justa
* Resultados reproducibles
* Condiciones iguales para todos los alumnos

---

## Reglas importantes

* No modifiques los unit tests
* No modifiques los workflows
* No elimines asserts o validaciones
* No fuerces resultados para pasar el test
* Implementa los algoritmos correctamente

---

## Recomendaciones

* Trabaja en branches
* Haz commits pequeños y descriptivos
* Lee los mensajes de error de los tests
* Usa `assert` como herramienta de aprendizaje
* Pregunta si algo no queda claro

---

## Criterio de aprobación

Una práctica se considera aprobada cuando:

* Compila sin warnings
* Pasa todos los unit tests localmente
* El workflow de GitHub Actions termina exitosamente
* El commit correspondiente queda registrado

---

## Nota final

Este flujo de trabajo refleja prácticas reales de desarrollo profesional:

* Integración continua (CI)
* Validación automática
* Control de versiones
* Trabajo reproducible
