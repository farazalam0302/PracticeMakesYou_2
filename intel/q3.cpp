/*
 * {}{}{}{{{[{{}}
 * and wild card chars like  ***
 *  * tarnslated [{, }]
 *
 *  given string {}{}****
 *  verify this string is balanced
 */
// {*}}
// **{{ -> No
// {{****
bool verifyBalancedParens() {
  //   s1 and s2
  for (int i = 0; i < len(in); ++i) {
    if (in[i] == '{')
      push i To S1;
    else if (in[i] == '*')
      push i To S2;
    else if (in[i] == '}') {
      // fisrt check top of s1
      if (s1.size() > 0)
        s1.pop();
      else if (s2.size() > 0)
        s2.pop();
      else
        return false;
    }
  }

  /// s1 empty and s2 is empty return true

  if (s1 i not empty) {
    if (s2 is empty)
      return false; ///
    else {
      while (s1.empty() == false) {
        int _bIndex = s1.top();
        int _starInd = s2.top();
        if (_bIndex < _starInd) {
          s1.pop();
          s2.pop();
        } else {
          return false;
        }
      }
    }
  }

  if (!s1.empty())
    return false;

  if (s2.size() is odd)
    return false;

  return true;
}
