# 🎮 Jeu de Nim – Version Console (C)

Petit jeu en **langage C** basé sur le célèbre **jeu de Nim**.
Le principe est simple : des bâtonnets sont posés sur la table et chaque joueur en retire **1, 2 ou 3** à son tour.

⚠️ **Attention : celui qui prend le dernier bâtonnet perd la partie.**

Dans cette version, vous jouez contre une **IA** qui essaie d’appliquer une stratégie pour gagner.

---

# 🧠 Principe du jeu

1. Le jeu commence avec **20 bâtonnets**.
2. Le joueur et l’IA jouent chacun leur tour.
3. À chaque tour, on peut retirer **1, 2 ou 3 bâtonnets**.
4. Le joueur qui **prend le dernier bâtonnet perd**.
5. À la fin de la partie, le joueur peut choisir de **rejouer**.

---

# 📂 Fichiers du projet

```text
projet/
│
├── jeux.c
├── run.bat
└── README.md
```

### `jeux.c`

Contient **le code source du jeu de Nim**.

Fonctionnalités principales :

* affichage visuel des bâtonnets dans le terminal
* gestion des tours (joueur / IA)
* vérification des actions autorisées
* stratégie simple pour l’IA
* possibilité de rejouer une partie

---

### `run.bat`

Script Windows permettant de **compiler et lancer automatiquement le programme**.

Contenu du script :

```bat
gcc %1.c -o %1
if %errorlevel%==0 (
    %1.exe
)
```

Ce script :

1. compile le fichier `.c`
2. crée le fichier `.exe`
3. exécute le programme si la compilation réussit

---

# ⚙️ Prérequis

Installer un compilateur C sur Windows.

Par exemple **GCC avec MinGW ou MinGW-w64**.

Pour vérifier l’installation :

```bash
gcc --version
```

Si une version s’affiche dans le terminal, le compilateur est correctement installé.

---

# ▶️ Lancer le jeu

Ouvrir un **terminal** dans le dossier du projet puis exécuter :

```bash
run jeux
```

Le script va :

1. compiler `jeux.c`
2. créer `jeux.exe`
3. lancer le jeu

---

# 🎮 Exemple de partie

```
==================================
      JEU DE NIM (BATONNETS)
==================================
Regle : Ne prenez pas le dernier !

Stock : | | | | | | | | | | | | | | | | | | | | (20 restants)

Combien de batonnets (1, 2 ou 3) ? 2

L'IA reflechit...
L'IA retire 1 batonnet(s).
```

Le jeu continue jusqu’à ce qu’il ne reste plus de bâtonnets.

---

# 🤖 Fonctionnement de l’IA

L’IA utilise une petite stratégie mathématique :

```c
choix = (batonnets - 1) % 4;
```

Cette formule essaie de laisser **4n + 1 bâtonnets** à l’adversaire.

Pourquoi ?
Parce que dans le jeu de Nim avec des retraits de **1 à 3**, cette position est mathématiquement **désavantageuse pour le joueur qui joue ensuite**.

Quand l’IA ne peut pas garantir une victoire, elle retire simplement **1 bâtonnet**.

---

# 🔧 Fonctionnement du programme

Le programme utilise plusieurs concepts fondamentaux du langage C :

* génération aléatoire avec `srand(time(NULL))`
* boucles `while` et `do...while`
* conditions `if / else`
* interaction utilisateur avec `scanf`
* affichage dynamique des bâtonnets

---

# 💡 Améliorations possibles

Quelques idées pour améliorer le projet :

* ajouter **plusieurs niveaux de difficulté pour l’IA**
* permettre au joueur de **choisir le nombre de bâtonnets au départ**
* ajouter un **mode joueur vs joueur**
* ajouter un **compteur de tours**
* créer une **interface graphique**

---

# 📜 Licence

Projet libre pour apprendre la programmation en **langage C** et découvrir la logique du **jeu de Nim**.
