#if 0
/* C++ implementation to Check if
two strings after processing
backspace character are equal or not*/

#include <bits/stdc++.h>
using namespace std;

// function to compare the two strings
bool compare(string s, string t) {
  int ps, pt, i;

  /* the index of character in string which
  would be removed when
  backspace is encountered*/
  ps = -1;

  for (i = 0; i < s.size(); i++) {
    /* checks if a backspace is encountered or not.
            In case the first character is #,
            no change in string takes place*/
    if (s[i] == '#' && ps != -1) ps -= 1;

    /* the character after the # is added
    after the character at position rem_ind1 */
    else if (s[i] != '#') {
      s[ps + 1] = s[i];
      ps += 1;
    }
  }

  pt = -1;

  for (i = 0; i < t.size(); i++) {
    /* checks if a backspace is encountered or not */
    if (t[i] == '#' && pt != -1)
      pt -= 1;

    else if (t[i] != '#') {
      t[pt + 1] = t[i];

      pt += 1;
    }
  }

  /* check if the value of
          rem_ind1 and rem_ind2
          is same, if not then
          it means they have different
          length */
  if (pt != ps) return false;

  /* check if resultant strings are empty */
  else if (ps == -1 && pt == -1)

    return true;

  /* check if each character in the resultant
  string is same */
  else {
    for (i = 0; i <= pt; i++) {
      if (s[i] != t[i]) return false;
    }
    return true;
  }
}

// Driver code
int main() {
  // initialise two strings
  string s = "equ#ual";// "geee#e#ks";
  string t = "equaa#l";//"gee##eeks";

  if (compare(s, t))

    cout << "True";
  else

    cout << "False";
}

#endif

#if 1
#include <bits/stdc++.h>
using namespace std;

bool compareTwoStringsWithBackSpace(string a, string b) {
  int na = a.size();
  int nb = b.size();
  int pA = -1;
  int pB = -1;
  for (int i = 0; i < na; ++i) {
    if (pA != -1 && a[i] == '#') {
      pA -= 1;
    } else if (a[i] != '#') {
      a[pA + 1] = a[i];
      pA += 1;
    }
  }

  pB = -1;

  for (int i = 0; i < nb; ++i) {
    if (pB != -1 && b[i] == '#') {
      pB -= 1;
    } else if (b[i] != '#') {
      b[pB + 1] = b[i];
      pB += 1;
    }
  }

  for (int i = 0; i <= pB; ++i) {
    //      if (a[i] != b[i]) return false;
    cout << a[i] << " | " << b[i] << endl;
  }

  if (pA != pB)
    return false;
  else if (pA == -1 && pB == -1)
    return true;
  else {
    for (int i = 0; i <= pB; ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
}

int main() {
  string s = "equ##ual";  // "geee#e#ks";
  string t = "eq#uaal#";  //"gee##eeks";

  compareTwoStringsWithBackSpace(s, t)
      ? cout << "Yes!, " << s << " and " << t
             << " are Same after backspace considered\n"
      : cout << "No!, " << s << " and " << t
             << " are Different after backspace considered\n";
  cout << endl;

  return 0;
}
#endif
