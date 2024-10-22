for (unsigned i = 0; i < n; ++i) {
  //   d[i] = a[i + 1];
  tt = a[i] = b[i] + c[i];
  // }
  // for (unsigned i = 0; i < n; ++i) {
  d[i] = tt;
}

// ==>  Loop fused

//  N1     N2         N` fused
// a[i]    d[i]   a[i] d[i]
