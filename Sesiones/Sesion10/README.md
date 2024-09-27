
# Dentro de esta sección se presenta el apartado para la sesión # 10 del curso IE0217.


## Interfaces Gráficas en C++ con FLTK y WxWidgets

### Introducción a las Interfaces Gráficas (GUI)
- **Definición**: Las interfaces gráficas (GUI) permiten a los usuarios interactuar con programas a través de elementos visuales como botones, menús y ventanas.
- **Interfaz de Usuario (UI)**: Se refiere al diseño visual y funcional de los elementos de interacción.
- **Experiencia de Usuario (UX)**: Se enfoca en cómo los usuarios perciben e interactúan con un producto, considerando tanto aspectos prácticos como emocionales.

## WxWidgets
- **Descripción**: Una biblioteca de C++ para crear aplicaciones multiplataforma con una única base de código. Soporta Windows, macOS, Linux y más.
- **Características**:
  - Apariencia nativa en cada plataforma.
  - Extenso conjunto de widgets y amplia documentación.
  - Licencia múltiple (compatible con GPL).
  - Comunidad grande y activa.
  - Integración con C++ y otros lenguajes como Python.
  - Conjunto variado de estilos visuales predefinidos.

## FLTK
- **Descripción**: Un kit de herramientas GUI ligero y multiplataforma. Soporta Windows, macOS y Linux, con soporte para gráficos 3D mediante OpenGL.
- **Características**:
  - Biblioteca pequeña y modular.
  - Conjunto limitado de widgets.
  - Integración sencilla con C++.
  - Menor comunidad y documentación menos extensa en comparación con WxWidgets.
  - Estilos predeterminados simples.

## Comparativa WxWidgets vs FLTK
- **WxWidgets**:
  - Soporte para más plataformas.
  - Conjunto de widgets más amplio.
  - Documentación más extensa.
  - Licencia GPL compatible.
- **FLTK**:
  - Biblioteca más ligera y simple.
  - Menos widgets y documentación, pero más fácil de integrar y utilizar en proyectos pequeños.


- Ejecucion de WxWidgets:

![alt text](../../Pruebas/PruebaEjec1Sesion10.jpg)

- Hellow World en VS:

![alt text](../../Pruebas/Prueba2Sesion.jpg)


- Ventana Basica en VS:


![alt text](../../Pruebas/Prueba2Sesion.jpg)



- Controles: 

![alt text](../../Pruebas/Prueba4EjecSesion10.jpg)

- Estilo: 

![alt text](../../Pruebas/Prueba5Sesion10.png)


## Eventos en WxWidgets
- **Eventos Estáticos y Dinámicos**: 
  - Manejo estático: los eventos están predefinidos y asignados de manera rígida.
  - Manejo dinámico (Binding): permite una mayor flexibilidad, asociando eventos a controladores de manera programática.

- Eventos en la pantalla Manejo Estatico: 

![alt text](../../Pruebas/Prueba6Sesion10.jpg)

- Eventos en la pantalla Manejo Dinamico:

![alt text](../../Pruebas/Pureba7Sesion10.jpg)

  
## Eventos del Mouse y Teclado
- **Eventos del Mouse**: 
  - Detección del movimiento y clics del ratón mediante eventos específicos como `wxEVT_MOTION`.

- Posición del mouse: 

![alt text](../../Pruebas/Prueba11Sesion10.jpg)


- **Eventos del Teclado**: 
  - Captura de eventos de teclas dependiendo de dónde esté enfocada la interfaz en cada momento.

- Presiona cualquier tecla del teclado: 

![alt text](../../Pruebas/Prueba12Sesion10.jpg)


- Presion en lugar especifico con el teclado: 

![alt text](../../Pruebas/Prueba13Sesion10.jpg)


## Propagación de Eventos
- **Descripción**: Los eventos pueden propagarse a través de una jerarquía de elementos, permitiendo que varios componentes respondan a la misma acción.

- Click en un boton: 

![alt text](../../Pruebas/Prueba8Sesion10.jpg)


- Dos botones:

![alt text](../../Pruebas/Prueba9Sesion10.jpg)


- Dice que boton se tocó:

![alt text](../../Pruebas/Prueba10Sesion10.jpg)

