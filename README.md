# Programación Concurrente - UNLaM
Repositorio donde se encuentran los ejercicios correspondientes a los trabajos prácticos de la materia.

* Cuatrimestre: Segundo Cuatrimestre 2024
* Grupo: M4

## Docentes
* Adagio, Matías Ezequiel
* Carnuccio, Esteban
* Hirschfeldt, Darío
* Palomo, Maximo Facundo
* Volker, Mariano Leonardo

## Integrantes
| Nombre | DNI |
|--|--|
| Antonioli, Iván Oscar | 43.630.151 |
| Di Nicco, Luis Demetrio | 43.664.669 |
| Sandoval Vasquez, Juan Leandro | 41.548.235 |
| Tigani, Martin Sebastián | 32.788.835 |
| Villca, Luis Alberto | 35.277.730 |

## Links a Google Colab
### Trabajo Práctico 1
* Parte 1: Procesos
  * [C](https://colab.research.google.com/drive/1HI2BX2UqpVGj9xpQXm2FQORTsDcy4-78?usp=drive_copy)
  * [Java](https://colab.research.google.com/drive/1133X3S7irJ1Od0Diw2Frh1o-o_lFK1yQ?usp=sharing)
  * [Python](https://colab.research.google.com/drive/15BYDuVqsOOuq5t5jVRt4znZpDoHhjLmb?usp=sharing)
* Parte 2: Hilos
  * [C++](https://colab.research.google.com/drive/1NOf-a3MtG6HjaSbdcpi-LiRUN_wtAMBe?usp=sharing)
  * [Java](https://colab.research.google.com/drive/160u8T9y358jp8hcwyKtcP_mnDWh9Jw9U?usp=sharing)
  * [Python](https://colab.research.google.com/drive/1YPe_jf5sEFWy52j8VbI3utTVnUgqdJF1?usp=sharing)
* Parte 3: Comunicación y Sincronismo
  * [C++](https://colab.research.google.com/drive/1ja93oFt8rjT-mDRQUiUhEsE4kLBKgPww?usp=sharing)
  * [Java](https://colab.research.google.com/drive/1faaEzvc6sK45I9DQzRoJa2Sdl5pz8PM6?usp=sharing)
  * [Python](https://colab.research.google.com/drive/1kNpa11lwbl7ZA-eBlq7JP4FJlv1Xd-yQ?usp=sharing)

## Pasos para subir cambios al repositorio de la materia

Repositorio de la catedra: [CATEDRA de PROGRAMACION CONCURRENTE UNLAM](https://github.com/UNLAM-PROG-C)

1. Si no tenés bajado localmente el repositorio, tenés que abrirte la terminal, posicionarte en el directorio donde te lo querés bajar, y clonártelo con: `git clone https://github.com/UNLAM-PROG-C/2024-PROGC-Q2-M4.git`

2. Posicionarse en el repositorio: `cd 2024-PROGC-Q2-M4/`

3. Crear una nueva rama para subir los cambios: `git checkout -b nombreDeLaRama`

4. Luego de subir los archivos o las modificaciones: `git add .`

5. Commiteamos los archivos: `git commit -m "MensajeRelacionadoAlCommit"`

6. Pusheamos la rama: `git push` o `git push --set-upstream origin nombreDeLaRama`

7. En el repositorio de la catedra te va a aparecer un mensaje similar a este, y tenés que hacer clic en `Compare & pull request`

<p align="center">
  <img src="https://github.com/user-attachments/assets/84f13371-6ae0-4407-9df9-843e5f8cd827" alt="Compare & pull request"/>
</p>

8. Antes de crearlo, podes asignar los reviewers para que realicen comentarios sobre el código del PR

<p align="center">
  <img src="https://github.com/user-attachments/assets/4b24cb85-1f92-4169-bfe6-f412ae872203" alt="Assign reviewers"/>
</p>

9. Luego creamos el PR con `Create pull request`

<p align="center">
  <img src="https://github.com/user-attachments/assets/ad85a457-6d63-44ce-a4bd-375d89dc42dd" alt="Create pull request"/>
</p>

10. Después cuando se verifiquen los chequeos del Coding Standard debería habilitarse el botón `Merge pull request` y para finalizar ya podés eliminar la rama con `Delete branch`

<p align="center">
  <img src="https://user-images.githubusercontent.com/24505883/42899819-7c05a47a-8ac7-11e8-8be9-9e3888f1bedc.gif" alt="Merge pull request"/>
</p>

10.1 En caso de que alguno de los chequeos del Coding Standard no se aprueben, se debe cerrar el PR, realizar los cambios en el código de correcciones, es decir, repetir los pasos de 4 al 6, y luego reabrir el PR.

<p align="center">
  <img src="https://i.sstatic.net/IA4pH.png" alt="Close pull request"/>
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/35812641/192277071-e822eee6-e340-41a5-aafa-569f441bb65a.png" alt="Reopen pull request"/>
</p>

11. *(OPCIONAL)* Para finalizar, en la terminal, te podés posicionar nuevamente en la rama de develop, (`git checkout develop`) y bajarte los cambios del PR con `git pull`

12. *(OPCIONAL)* Si hiciste el paso 11 te habrás dado cuenta de que la rama que borraste todavía sigue apareciendo, eso es porque se eliminó remotamente, pero todavía se encuentra local, la podes ver con `git branch -a` y para eliminarla es con `git branch -d nombreDeLaRama`

### Aclaraciones
- Ante cualquier consulta de commits, cambios efectuados o saber la rama actual, se puede usar: `git status`
  
- Antes de hacer un commit es recomendable bajar los cambios que pudieron haberse producido con: `git pull`

- En caso de que estes trabajando en una rama y en este momento haya ocurrido algún PR en develop tenés que hacer lo siguiente:
  - `git checkout develop`
  - `git pull`
  - `git checkout nombreDeLaRamaEnLaQueEstabasTrabajando`
  - `git merge develop`
  Lo que estarías haciendo es bajarte los nuevos cambios aprobados del/los PR y tambien tenerlos en tu rama local que estás trabajando.

- Si querés ver todas las ramas que se encuentran: `git branch -a`
  
- Te podés posicionar en una rama con: `git checkout nombreDeLaRama`
