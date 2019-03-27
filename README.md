# Get Next Line

## Subject
Vous commencez maintenant à vous rendre compte qu’à chaque fois que vous retrouvez dans la situation de lire des données depuis un file descriptor et que cette donnée
n’est pas d’une taille connue à l’avance, c’est compliqué. Quelle taille de buffer choisir ?
Combien de fois lire sur le file descriptor pour retrouver la donnée ?
Il est parfaitement naturel et commun en programmation de vouloir lire une “ligne”
terminée par un retour à la ligne depuis un file descriptor. Par exemple chaque commande
que vous tapez dans votre shell ou bien chaque ligne lue depuis un fichier plat.
Grâce au projet get_next_line, vous allez pouvoir écrire une bonne fois pour toute
une fonction vous permettant de lire une ligne terminée par un retour à la ligne depuis
un file descriptor, l’ajouter à votre libft si le coeur vous en dit, et surtout l’utiliser dans
tous vos projets suivants qui en auront besoin.

106/100
