Solution_sack<pair<B, N>>

    unordered_map<B->set(Nuts)>  //
                                 /*
                                  * b1 -> (n4,n2,n3)
                                  *
                                  *
                                 b1->n4

                                 b1 n1

                                 //////////
                                  *
                                  * B
                                  * n1,n2....n5
                                 B == n1  ; -> solution sack
                                 B<n1  -> lessthanBs
                                 B>n1  -> greaterthanBs
                                   B
                                 n1< >n1

                                             B1
                                        /         \
                                  [n3, n2, n1 ]  n6 [ n4 n5   ]

                                 2 B2 < n6  ; > n6


                                  B ->rows N is cols
                                  BXN  = -2

                                  if b==n ; check[b][n] = 0
                                  if b<n   check[b][n] = -1
                                  if b>n   check[b][n] = 1








                                 */
