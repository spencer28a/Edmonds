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

bool find_augmenting_path(graph& G, matching M) {
  bool found_it = false;
  while (!found_it) {
    Edge min_edge;
    pseudo_node min_red_z;
    int bb_min = find_bb_min(G, min_edge);
    int bu_min = find_bu_min(G, min_edge);
    int z_min = find_z_min(G, min_red_z);
    if (bu_min <= bb_min && bu_min <= z_min {
      uncolored_2_blue(min_edge, G);
    } else if (bb_min <= bu_min && bb_min <= z_min) {
      found_it = augment_path_or_collapse_blossom(min_edge, G, M)
    } else {
      expand_pseudo_node(min_red_z);
    }
  }
  return found_it;
}