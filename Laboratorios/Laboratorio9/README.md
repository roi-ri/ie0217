wdawd





Para el ejercicio 1 se comienza agregando breakpoints en las lineas 5 y se empieza a correr el codigo copn el comando next para poder pasar a la linea del for. Dentro de esta se observa que, el indice i empieza en 1 y se espera que llegue a tener valor igual al ``numeros.size()`` para que termine el for, pero al hacer esto estaria fuera del rango del arreglo, deberia ser hasta 5, por eso que cambia el for de la siguiente manera: ``for (int i = 0; i < numeros.size(); i++)``.



Se ocupa que el programa devuelva numeros tipo double, pero por ejemplo, en la primera funcion se tiene que, ``suma`` es un entero y ``numeros.size()`` tambien, por consiguiente el elemento que devuelve la funcion es tipo entero, y no hace nada declarandolo por fuera como un double. 



Para la funcion de la mediana, se tiene que dividir entre un 2.0 para que el numero sea tipo double. 