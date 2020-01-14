#define printMat(x)                                                            \
  for (int i = 0; i <= m; i++) {                                               \
    for (int j = 0; j <= n; j++) {                                             \
      cout << x[i][j] << " ";                                                  \
    }                                                                          \
    cout << endl;                                                              \
  }

void printMatrix() {

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      cout << CP[i][j] << " ";
    }

    cout << endl;
  }
}