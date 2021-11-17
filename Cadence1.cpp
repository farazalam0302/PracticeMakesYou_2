// char *p = "name=aa;name =   bb; city=Agra; name = ccccc; name=2222";

//#include<bits/stdc++.h>
// using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// char* preProcess(char p[]) {
//
//  printf("size = %d\n", l);
//}

int main() {
  char* p =
      "name=aa;namee                   =   bb; city=Agra; name = ccccc; "
      "name=2222";
  int charCount = 0;
  char* j = p;
  //  while (*j != NULL) {
  //    if (*j != ' ') charCount++;
  //    j++;
  //  }
  int n = strlen(p);
  char* temp = (char*)(malloc(sizeof(char) * (n)));

  while (*j != '\0') {
    if (*j != ' ') {
      temp[charCount++] = *j;
    }
    temp[charCount] = '\0';
    j++;
  }

  const char* f = "name=";
  char* t = temp;
  char* iter = (char*)f;
  while (t = strstr(t, iter)) {
    t = t + 5;
    while (*t != ';' && *t != NULL) {
      printf("%c", *t);
      t++;
    }
    printf("\n");
    //    temp = t;
  }
  printf("%s\n", p);
  printf("%s\n", temp);

  return 0;
}

//  bool stateN = false;
//  bool stateA = false;
//  bool stateM = false;
//  bool stateE = false;
//  bool state_eq = false;
//
//  for (; *p != NULL; p++) {
//    if (!state_eq && *p == 'n')
//      stateN = true;
//    else if (!state_eq && stateN && *p == 'a')
//      stateA = true;
//    else if (!state_eq && stateA && stateN && *p == 'm')
//      stateM = true;
//    else if (!state_eq && !stateE && stateM && stateA && stateN && *p ==
//    'e')
//      stateE = true;
//    else if (!state_eq && stateE && *p == ' ')
//      continue;
//    else if (!state_eq && stateE && *p == '=')
//      state_eq = true;
//    else if (state_eq && *p == ' ')
//      continue;
//    else if (state_eq && *p != NULL && *p != ';')
//      printf("%c", *p);
//    else if (state_eq && *p != NULL && *p == ';') {
//      stateN = false;
//      stateA = false;
//      stateM = false;
//      stateE = false;
//      state_eq = false;
//      printf("\n");
//    } }
