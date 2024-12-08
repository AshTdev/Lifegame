# ❗"Lifegame" - Projet POO en C++ ❗

## 🧑🏻‍🦰👨🏻 **Binôme**
Ce projet a été réalisé en binôme ( Yanis B. | Virgil G.) dans un cadre scolaire (CESI - Ecole d'Ingenieurs | Bloc Conception & Programmation Objet)

## 📜 **Sommaire**

- I/ Introduction du jeu de la vie
      
- II/ Règles du jeu de la vie
      
- III/ Fonctionnalité du programme
      
   -  A / Lecture du fichier
   -  B / Mode console ou mode graphique ? | Paramètres de la simulation

-  IV. Légende
      
-  V. Extensions présentes
      
-  VI. Comment lancer le jeu

----------------------
##  **🪴I/ Introduction du jeu de la vie**

Le "Jeu de la vie" est un automate cellulaire (un modèle où l'état d'une entité conduit à un nouvel état en se fixant sur des règles) qui a été imaginé par M.Conway, un mathématicien britannique en 1970. Notre projet consiste donc à développer le jeu de la vie en appliquant les notions de la POO avec le langage de programmation C++.

Le jeu consiste à placer des cellules dans une grille et de les caractériser par deux états qui sont :
-  **Cellule morte**
-  **Cellule vivante**

Ainsi, lorsque les cellules vivantes sont placées, on lance une simulation et on observe les changements d'état, et plus globalement, l'évolution de nos cellules.

----------------------

## **📏 II/ Règles du jeu de la vie**

Une cellule possède huit cellules voisines (2 cellules horizontales, 2 cellules verticales, 4 cellules diagonales) :
- ◼️◼️◼️ 
- ◼️◻️◼️ 
- ◼️◼️◼️

A chaque itération, on définit l'état d'une cellule en fonction de l'état de ses huit cellules voisines, avec les règles suivantes :

-  Une cellule *morte* (0) qui possède *exactement* trois cellules voisines vivantes devient vivante (1).
-  Une cellule *vivante* (1) qui ne possède pas *exactement* deux/trois cellules voisines vivantes devient une cellule morte (0).

<p align="center">
  <img src="https://github.com/user-attachments/assets/a8637444-208c-466c-8484-63e368080606" alt="Game of Life">
</p>

--------------------

## **⚙️ III/ Fonctionnalités du programme**

### **A/ Lecture du fichier (création de la grille)**

Avant le démarrage de la simulation, le programme demande à l'utilisateur un fichier qui comprend les dimensions de la grille, ainsi que la matrice (0 ou 1) afin de définir les cellules vivantes dans celle-ci.

Note : Le fichier doit être un .txt

### **B/ Mode console ou mode graphique ? 🤔**

Lorsqu'on envoie le fichier, le programme demande à l'utilisateur de faire le choix entre le mode graphique et le mode console :

### Mode Console
----------
-  Le programme reçoit le fichier contenant la matrice et les dimensions.
-  L'utilisateur initialise les paramètres.
-  Le programme Demande à l'utilisateur de donner un nom de dossier afin d'enregistrer à chaque itération la nouvelle matrice.
-  Le dossier est ensuite stocké avec les "logs" de la simulation en fonction du nombre d'itérations qui a été demandé.

<p align="center">
  <img src="https://github.com/user-attachments/assets/4bbc5515-5c11-48ca-8ba9-2b40fa3003cc" alt="Mode Console">
</p>

Exemple : 5 Itérations demandées --> 5 fichiers logs produits
----------

### Mode Graphique (bibliothèque SFML)

----------
-  Le programme reçoit le fichier contenant la matrice et les dimensions.
-  L'utilisateur initialise les paramètres.
-  Le programme utilise la bibliothèque SFML afin de représenter en direct l'évolution de la simulation.
-  La simulation s'arrête lorsque le nombre d'itérations a été atteint ou lorsqu'il n'y a plus d'évolution possible des cellules.

<p align="center">
  <img src="https://github.com/user-attachments/assets/2413162c-b371-4722-b7dd-43a7a410892b" alt="Mode Graphique">
</p>

----------
## **💻 IV/ L'initialisation des paramètres**

L'utilisateur **initialise les paramètres** de la simulation :

-  Le nombre d'itérations (1 à x) 
-  Le temps entre chaque itération (en ms)
-  La taille d'une cellule (minimum 2)

Enfin, le tour est joué ! la simulation démarre.
------------------

##  **📚 V/ Langages et bibliothèques**

-  C++ standard
-  Bibliothèque graphique "SFML" pour afficher notre jeu.

## **🚧 VI/ Présentation des fonctions dans la structure de notre programme**

Notre programme contient quatre classes, quatre fichiers c++ ainsi que le main.cpp :

- ```main.cpp``` : Gère l'interface utilisateur et les itérations de la grille (console | graphique)    

- ```AliveCell.cpp | AliveCell.h``` : Représente une cellule vivante, elle vérifie ses voisins à chaque itération

- ```DeadCell.cpp | DeadCell.h``` : Représente une cellule morte, elle vérifie ses voisins à chaque itération

- ```cell.cpp | cell.h``` : Représente une cellule avec les méthodes de base

- ```grid.cpp | grid.h``` : Représente la grille de cellules et s'occupe des itérations

- ```Matrice.txt``` : Un fichier texte qui sert d'exemple, elle décrit notamment les dimensions de la grille ainsi que les différentes cellules présentes + obstacles

## **🧭 VII/ Légende**

- **1** : Correspond à une cellule **vivante** --> la couleur d'une cellule vivante est en **blanc**  
- **0** : Correspond à une cellule **morte** --> la couleur d'une cellule vivante est en **noir**  
- **3** : Correspond à un obstacle **vivant** --> la couleur de cet obstacle est en **vert**  
- **2** : Correspond à un obstacle **mort** --> la couleur de cet obstacle est en **rouge**  

## **🌻 VIII/ Extensions présentes**

✅ Gestion d’une grille torique. Les cellules placées aux extrémités de la grille sont adjacentes.  

✅ Introduction de cellules obstacle. L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant ou mort. Modifiez votre code, sans altérer le fonctionnement de base.  


## **✈️ IX/ Comment lancer le jeu**

1. **Ouvrez votre terminal** (Sur Linux - Ubuntu)  
2. **Accédez aux fichiers** grâce à la commande `cd` :  
   ```bash
   cd chemin/vers/le/dossier 
3 **Compiler le jeu**
- Lorsque vous serez dans le dossier contenant le programme, compilez le script grace à cette commande dans le terminal :
```bash
g++ -o main main.cpp AliveCell.cpp DeadCell.cpp cell.cpp grid.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
-Puis, une fois le code compilé, utilisez cette commande dans le même dossier :
```bash
./main
```
(Note, vous pouvez remplacer le main dans ```-o main``` et ```./main``` par le nom que vous voulez si vous voulez avoir un nom de fichier différent, mais cela n'est pas nécessaire. 😉)

4. **Enjoy!**
