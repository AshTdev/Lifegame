# "Lifegame" - Projet POO en C++ 

###  Ce projet a été réalisé en binôme ( Yanis B. | Virgil G.) dans un cadre scolaire (CESI - Ecole d'Ingenieurs)

----------------------
## Principe du jeu de la vie

Le "Jeu de la vie" est un automate cellulaire (un modèle où l'état d'une entité conduit à un nouvel état en se fixant sur des règles) qui a été imaginé par M.Conway, un mathématicien britannique en 1970.

Le jeu consiste à placer des cellules dans une grille et de les caractériser par deux états qui sont :
-  **Cellule morte**
-  **Cellule vivante**

Ainsi, lorsque les cellules vivantes sont placées, on lance une simulation et on observe les changements d'état, et plus globalement l'évolution de nos cellules.

----------------------

## Règle du jeu de la vie

Une cellule possède huit voisines (2 cellules horizontales, 2 cellules verticales, 4 cellules diagonales)

A chaque itération, on définit l'état d'une cellule en fonction de l'état de ses huit cellules voisines, avec les règles suivantes :

-  Une cellule *morte* (0) qui possède *exactement* trois cellules voisines vivantes devient vivante (1).
-  Une cellule *vivante* (1) qui ne possède pas *exactement* deux/trois cellules voisines vivantes devient une cellule morte (0).

 ![image](https://github.com/user-attachments/assets/a8637444-208c-466c-8484-63e368080606)

--------------------
## Langages et bibliothèques

-  C++ standard
-  Bibliothèque graphique "SFML" pour afficher notre jeu.^^

## Fonctionnalités du programme

### I / Lecture du fichier (création de la grille)

Avant le démarrage de la simulation, le programme demande à l'utilisateur un fichier qui comprend les dimensions de la grille, ainsi que la matrice (0 ou 1) afin de définir les cellules vivantes dans celle-ci.

Note : Le fichier doit être un .txt

### II / Mode console ou mode graphique ? | Paramètres de la simulation

Lorsqu'on envoie le fichier, le programme demande à l'utilisateur de faire le choix entre le mode graphique et le mode console.

Ensuite, l'utilisateur **initialise les paramètres** de la simulation :

-  Le nombre d'itérations
-  Le temps entre chaque itération
-  La taille d'une cellule

Enfin, le tour est joué ! la simulation démarre.
------------------

## Légende

- 1 : Correspond à une cellule **vivante** --> la couleur d'une cellule vivante est en **blanc**
- 0 : Correspond à une cellule **morte** --> la couleur d'une cellule vivante est en **noir**

- 3 : Correspond à un obstacle **vivant** --> la couleur de cet obstacle est en **vert**
- 2 : Correpond à un obstacle **mort** --> la couleur de cet obstacle est en **rouge**


## Extensions présentes 

✅ Gestion d’une grille torique. Les cellules placées aux extrémités de la grille sont adjacentes.

✅ Introduction de cellules obstacle. L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières
possèdent un état vivant ou mort. Modifiez votre code, sans altérer le fonctionnement de base.

❌ Placement de constructions pré-programmées sur la grille. Utiliser les touches du clavier pour intégrer de nouveaux motifs sur la grille lors de l’exécution.

❌ Paralléliser la génération des cellules. Modifiez votre algorithme pour paralléliser le traitement requis pour mettre à jour l’état des cellules sur la grille.











