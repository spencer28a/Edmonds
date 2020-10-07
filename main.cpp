#include <iostream>
#include "graph.h"

#if 0
void read_graph(Graph& G);

void write_matching(const Matching& M);


bool find_augmenting_path(Graph& G, Matching& M) {
  bool found_it = false;
  while (!found_it) {
    Edge min_edge;
    PseudoNode min_red_z;
    /*
    int bb_min = G.find_bb_min(G, min_edge);
    int bu_min = G.find_bu_min(G, min_edge);
    int z_min = G.find_z_min(G, min_red_z);
    
    if (bu_min <= bb_min && bu_min <= z_min){
      uncolored_2_blue(min_edge, G);
    } else if (bb_min <= bu_min && bb_min <= z_min) {
      found_it = augment_path_or_collapse_blossom(min_edge, G, M)
    } else {
      expand_pseudo_node(min_red_z);
    }
    */
  }
  return found_it;
};
  

void compute_matching(Graph& G, Matching& M) {
  M.init();  // make sure M is empty
  G.init_dual_variables();
  bool augmented = true;
  while (augmented) {
    augmented = find_augmenting_path(G, M);
  }
}


int main() {
  Graph G;
  Matching M;
  read_graph(G);
  compute_matching(G, M);
  write_matching(M);
}
#endif

class int_priority : public base_priority {
  int value;
  public:
  int evaluate() {
    return value;
  }
  int_priority(int v) : value(v) {}
};
int main() {
  printf("starting smoke test\n");
  // smoke test
  lazy_insert_leftist<int_priority> PQ;
  PQ.insert(int_priority(3));
  PQ.insert(int_priority(1));
  PQ.insert(int_priority(4));
  PQ.insert(int_priority(1));
  PQ.insert(int_priority(5));
  PQ.insert(int_priority(9));
  PQ.insert(int_priority(2));
  PQ.insert(int_priority(6));
  PQ.insert(int_priority(7));
  PQ.insert(int_priority(8));
  while (not PQ.empty()) {
    int ele = PQ.find_min().evaluate();
    PQ.check_invarient();
    PQ.delete_min();
    std::cout << ele << std::endl;
  }

}
