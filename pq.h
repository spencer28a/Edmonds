#pragma once
// leftist trees with lazy insertion.
// use when enough tmore insertions than deletion are expected, so making
// insertion run in O(1) amortized time is imortant.  Other operations still run
// on O(log n) amortized time
#include <vector>

template <typename priority_t>

class lazy_insert_leftist {
  private:
    class lt_node {
      priority_t priority;
      lt_node* left;
      lt_node* right;
      int depth;
    };

    lt_node* root;
    std::vector<lt_node*> unprocessed;

  public:
    insert(priority_t new_item);
    priority_t find_min();
    void delete_min();
    bool empty();
};