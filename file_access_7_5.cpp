
#include <stdio.h>

//! cat: concatenate (powi�za�) files



int main(int argc, char *argV[])
{
  FILE *fp; // FILE = structure declaration, pointer to the file
  void filecopy(FILE *, FILE *);
  fp = fopen("plik.txt", "r");

  if (argc == 1)
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argV, "r")) == NULL) {
      printf("cat:can't open %s\n", *argV);
      return 1;
      }
      else
      {
        filecopy(fp, stdout);
        fclose(fp);
      }
  return 0;
}

// filecopy: copy file ifp to file ofp
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}