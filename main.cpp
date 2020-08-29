#include <iostream>

int main() {
  Graph G;
  Matching M;
  read_graph(G);
  compute_matching(G, M);
  write_matching(M);
}

void comute_matching(graph& G, matching& M) {
  M.init();  // make sure M is empty
  G.init_dual_vars();
  bool augmented = true;
  while (augmented) {
    augmented = find_augmenting_path(G, M);
  }
   




}