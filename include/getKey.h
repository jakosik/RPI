#include <termios.h>
#include <stdio.h>
static struct termios sauvegarde, nouvelleConfig;
/*
 https://man7.org/linux/man-pages/man3/termios.3.html
*/

/* permet de sauvegarder la configuration actuelle du terminal*/
void sauvegarderConfigTerminal() {
  tcgetattr(0, &sauvegarde); //permet de sauvegarder les paramètre du terminal et de les stcoker dans la structure termios sauvegarde. */
  nouvelleConfig = sauvegarde; /* on se base sur les configurations de l'ancienne configuration pour créer la nouvelle */
  nouvelleConfig.c_lflag &= ~ICANON; //enlève le mode canonical, permet d'éviter d'avoir à appuyer sur la touche entrée.
  nouvelleConfig.c_lflag &= ~ECHO; /* permet de supprimer la sortie lorsque l'on tape un caractère. Il ne sera plus affiché à l'écran  */
  tcsetattr(0, TCSANOW, &nouvelleConfig); /* application de la nouvelle configuration, TSCANOW permet d'appliquer le changement immédiatement. */
  //0 car il s'agit du stdin.
}

void restaurerConfigTerminal() 
{
  tcsetattr(0, TCSANOW, &sauvegarde);
}
