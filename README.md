# Virus Compagnon

## Description
Virus de type compagnon réalisé dans le cadre d'un projet d'étude à l'Université de La Rochelle.

Le fichier MediaPlayer.exe infecte tous les exécutables du même répertoire à son lancement en se dupliquant. Puis à chaque lancement d'un programme infecté, une nouvelle infection se lance sur les nouveaux exe non infectés du répertoire.

Le tout se déroulant en arrière-plan pour ne pas éveiller les soupçons de l'utilisateur.

## Contenu
Ce projet contient : 
- le virus/lecteur de médias principal 'MediaPlayer.exe'
- 5 programmes de test
- plusieurs images d'extension différents pour tester le lecteur de médias
- Un fichier de compilation "cmp.sh" pour compiler tous les programmes utilisant GTK


## Programmes

5 programmes sont présents pour tester ce virus : 

1. MonPG1 : Calculatrice fonctionnel avec une interface grapghique réalisé avec GTK
2. MonPG2 : Color picker avec une interface graphique réalisé avec GTK
3. MonPG3 : Utilitaire pour calculer le théorème de Pythagore et sa réciproque
4. MonPG4 : Mini-jeu style Juste Prix 
5. MonPG5 : Utilitaire permettant de calculer tous les nombres premiers entre 2 et la valeur entrée par l'utilisateur


## Installation & lancement

Utilisation du virus préférable sous Linux
Pour installer le virus :
- Installez GTK :
  ```bash
  apt-get install libgtk-3-dev
  ```
- Pour compiler les 6 programmes :
  ```bash
  ./cmp.sh
  ```
- Puis, pour lancer un programme, entrer la commande suivante :
  ```bash
  ./'nomProgramme'
  ```

## Ajouts possibles
- Réaliser des programmes plus avancés et avec plus d'interfaces graphiques.
- Réaliser une version obfusquée et assombrie du code pour masquer la partie virale.

## Auteurs
Ce projet à été réalisé avec l'aide de [Stefan EVEN](https://github.com/seven0001)
