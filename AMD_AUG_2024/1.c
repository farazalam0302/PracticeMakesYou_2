#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowel(char a) {
  if ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ||
      (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'))
    return 1;
  return 0;
}

char *cocncatWithoutVowels(char *s1, char *s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  char *r = (char *)malloc((l1 + l2) * sizeof(char));
  int i = 0;
  int j = 0;
  int ri = 0;
  while (i <= l1 - 1) {
    if (isVowel(s1[i])) {
      i++;
      continue;
    }
    r[ri] = s1[i];
    ri++;
    i++;
  }
  while (j < l2) {
    if (isVowel(s2[j])) {
      j++;
      continue;
    }
    r[ri] = s2[j];
    ri++;
    j++;
  }

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
