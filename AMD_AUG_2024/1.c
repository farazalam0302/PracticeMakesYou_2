#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isvowel(char a) {
  if ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ||
      (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'))
    return 1;
  return 0;
}

char *cocncatWithoutVowels(char *s1, char *s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);

  printf("%s\n", s1);
  printf("%s\n", s2);
  char *r = (char *)malloc((l1 + l2) * sizeof(char));

  int i = 0;
  int j = 0;
  int ri = 0;
  while (i < l1 && s1[i] != '\0') {
    if (isvowel(s1[i])) {
      i++;
      continue;
    }
    if (s1[i] != '\0')
      r[ri] = s1[i];
    ri++;
    i++;
  }

  // for (int i = 0; i < ri; i++) {
  //   printf("%c", r[i]);
  // }
  j = 0;
  //   //   ri--;
  while (j < l2 && s2[j] != '\0') {
    if (isvowel(s2[j])) {
      j++;
      continue;
    }
    if (s2[j] != '\0')
      r[ri] = s2[j];
    ri++;
    j++;
  }
  r[ri] = '\0';

  // for (int i = 0; i < ri; i++) {
  //   printf("%c", r[i]);
  // }
  return r;
}

int main(int argc, char const *argv[]) {

  char *s1 = "bengaluru";
  char *s2 = "mumbai";

  char *r = cocncatWithoutVowels(s1, s2);

  printf("%s\n", r);

  free(r);
  return 0;
}
