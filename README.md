# Repositorio de prácticas de Informática Gráfica
Este repositorio contiene las prácticas realizadas en esta asignatura en el curso 2019/20 en el grupo A. 

## Idea de la escena 
(Luego no se cumple la mitad pero la esencia está)
"Para el proyecto de Informática Gráfica había pensado en una escena inspirada en el videojuego indie Untitled Goose Game. El contexto de este juego, básicamente es un ganso que se dedica a hacer destrozos por el vecindario, usando el pico para coger cosas o graznando sin parar.

Para ello, en la escena tendremos  un ganso, el cual sería un modelo jerárquico que se descompondría en cabeza, cuello, torso, alas, pata izquierda y pata derecha. El entorno se haría como si fuera una calle o plaza de un vecindario, con algunas casas, farolas... Habría elementos alrededor como balones de fútbol, cajas, piezas de bloques… 

La idea sería que el animal moviera la cabeza hacia adelante y hacia atrás, moviera las alas y las patas (¿que llegue a caminar quizá?) y que mantenga una cesta de picnic con naranjas (o bolas naranjas)

Para la luz, se podría hacer una fuera de las cámaras emulando al sol, o una encerrada que provenga de farolas. Las cámaras podrían ponerse desde postes, las propias farolas u otros elementos, algo que ya se irá definiendo más en detalle durante el transcurso de la realización de las prácticas."  

## Contenidos de las prácticas y donde encontrarlos.

### Práctica 1. Mallas y objetos 3D básicos
Implementación de dibujado de mallas y atributos : malla.cc
Datos para crear el cubo/tetraedro : cubo.cc / tetraedro.cc
Implementación de botones : escena.cc

### Práctica 2. Objetos de revolución y mallas PLY
Implementación de Objetos PLY: objply.cc
Implementación de mallas de revolución : objrevolucion.cc
Datos para crear mallas de revolución : cono/cilindro/esfera.cc

### Práctica 3. Luces
Implementación de luces : luz.cc
Implementación de tipos de luces : luzdireccional/luzposicional.cc

### Práctica 4. Modelo Jerárquico : Un Ganso
(Inspirado en Untitled Goose Game)
Implementación de modelo : jerarquico.cc
Animación: practicas.cc, escena.cc

### Práctica 5. Texturas
Implementación de texturas : textura.cc
Animación de luz puntual : escena.cc
Implementación de texturas por revolución : objrevolucion.cc (No está muy bien)

### Práctica 6. Cámaras
Implementación de cámara : camara.cc
Animación de cámaras : escena.cc

