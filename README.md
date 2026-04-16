# INTEGRADORA-4
TAREA PROGRAMACION ESTRUCTURA / TAREA INTEGRADORA / 2DO SEMESTRE / BLOQUE 1

# SIG-Conecta — Sistema de Gestión de Sala de Cómputo

> Sistema de monitoreo y bitácora para laboratorios de cómputo desarrollado en C++.  
> Proyecto académico — UNRC
> LINK MANUAL DIDACTICO: https://sites.google.com/view/integradora-2-do-semestre/integradora-2do-semestre


---

## Descripción

**SIG-Conecta** es una aplicación de consola escrita en C++ que permite al personal encargado de una sala de cómputo gestionar el estado de los equipos y llevar un registro detallado de incidentes. Los datos de la bitácora se persisten en un archivo de texto plano (`bitacora.txt`) para mantener el historial entre sesiones.

---

## Características

- Monitoreo del estado de **20 equipos** (libre / ocupada / mantenimiento)
- Modificación individual del estado de cualquier equipo
- Registro de incidentes con hora, tipo y descripción
- Consulta del historial completo de la bitácora
- Guardado y carga automática desde archivo (`bitacora.txt`)

---

## Estructura del proyecto

```
SIG-Conecta/
├── main.cpp          # Código fuente principal
├── bitacora.txt      # Archivo de persistencia (se genera al guardar)
└── README.md
```

---

## Requisitos

- Compilador C++ compatible con **C++11** o superior (g++, clang++, MSVC)
- Sistema operativo: Windows, Linux o macOS

---

## Compilación y ejecución

### Linux / macOS

```bash
g++ -std=c++11 -o sig_conecta main.cpp
./sig_conecta
```

### Windows (MinGW / MSYS2)

```bash
g++ -std=c++11 -o sig_conecta.exe main.cpp
sig_conecta.exe
```

### Windows (MSVC desde Developer Command Prompt)

```bash
cl /EHsc main.cpp /Fe:sig_conecta.exe
sig_conecta.exe
```

---

## Uso

Al iniciar el programa cargará automáticamente la bitácora previa si existe el archivo `bitacora.txt`. El menú principal ofrece las siguientes opciones:

```
1. Consultar estado de equipos     → Muestra el estado actual de los 20 equipos
2. Modificar estado de equipo      → Cambia el estado de un equipo específico
3. Registrar incidente             → Agrega un nuevo registro a la bitácora
4. Consultar historial             → Muestra todos los incidentes registrados
5. Guardar y salir                 → Guarda la bitácora y cierra el programa
```

### Ejemplo de flujo

```
Selecciona una opcion: 3

ID del equipo: 5
Hora (ej. 10:30): 14:25
Tipo de incidente (falla / uso / mantenimiento): falla
Descripcion: La PC no enciende, revisar fuente de poder

Incidente registrado correctamente.
```

---

## Formato del archivo de persistencia

Los registros se guardan en `bitacora.txt` usando `|` como separador de campos:

```
5|14:25|falla|La PC no enciende, revisar fuente de poder
12|09:00|mantenimiento|Limpieza de ventiladores y actualización de software
```

---

## Limitaciones actuales

- Capacidad máxima de **100 registros** en la bitácora por sesión
- Los estados de los equipos **no se persisten** entre sesiones (solo la bitácora)
- No hay validación de formato de hora
- Sin interfaz gráfica (aplicación de consola)

---

## Posibles mejoras futuras

- [ ] Persistencia del estado de los equipos entre sesiones
- [ ] Búsqueda y filtrado en la bitácora por equipo o tipo de incidente
- [ ] Validación de formato de hora (HH:MM)
- [ ] Exportación de reportes en CSV
- [ ] Interfaz gráfica con Qt o similar

---

## Tecnologías

| Elemento | Detalle |
|---|---|
| Lenguaje | C++11 |
| Entrada/Salida | `<iostream>`, `<fstream>` |
| Estructuras de datos | Arrays estáticos, structs |
| Persistencia | Archivo de texto plano |

---

## 👨‍💻 Autor

**Marvin Valdez**
Ingeniero en Sistemas, Electronica y Electromecanica | Redes | Ciberseguridad | IA

---
---

## Tecnologías

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![File I/O](https://img.shields.io/badge/File_I/O-fstream-green?style=flat)
![Arrays](https://img.shields.io/badge/Estructuras-Arreglos_estáticos-orange?style=flat)

