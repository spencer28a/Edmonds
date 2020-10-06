#pragma once
#include "pq.h"
// pure vitual class representing a vertex in the graph with blossoms collapsed.
class Node {


  
};

// a vertex in the original graph (no blossoms collapsed)
class Vertex : public Node {




};

// a collapsed blossom
class PseudoNode : public Node {



};

class Edge {



};

class bbRec: public base_priority {
  bool is_less (const base_priority& other) {
    return true;
  }
  int evaluate() {
    return 1;
  }

};

class buRec: public base_priority {
  bool is_less (const base_priority& other) {
    return true;
  }
  int evaluate() {
    return 1;

  }

};

class zRec : public base_priority {
  bool is_less (const base_priority& other) {
    return true;
  }
  int evaluate() {
    return 1;
  }

};

typedef lazy_insert_leftist<bbRec> bbPQ_t;
typedef lazy_insert_leftist<buRec> buPQ_t;
typedef lazy_insert_leftist<zRec> redZPQ_t;
class Graph {
  bbPQ_t bbPQ;
  buPQ_t buPQ;
  redZPQ_t redZPQ;
  public:
  int find_bb_min(Edge& min_edge) {
  //  return bbPQ.find_min(min_edge);
  }
  void init_dual_variables();


};


class Matching {
public:
  void init();


};