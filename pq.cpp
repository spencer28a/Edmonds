#include "pq.h"

template <typename priority_t>
  void insert(priority_t new_item) {
    unprocessed.push_back(new_item);


  }
    
  priority_t lazy_insert_leftist::find_min() {
    queue<lt_node*> temp_trees;
    for (int index =0; index < unprocessed.size(); ++index) {
      temp_trees.push_back(make_lt_node(unprocessed[i]));
    }
    unprocessed.clar();
    while (temp_trees.size() > 1) {
      lt_node* t1;
      lt_node* t2;
      t1 = temp_trees.front();
      temp_trees.pop_front();
      t2 = temp_trees.front();
      temp_trees.pop_front();
      temp_trees.push_back(unite(t1, t2));
    }
    if (!temp_trees.empty())  {
      root = unite(root, temp_trees.front());
      temp_trees.clear();
      return root->priority;
    }
  }

  bool lazy_insert_leftist::empty() {
    return unprocessed.empty() && root == NULL;
  }

  void lazy_insert_leftist::insert(priority_t new_elem) {
    unprocessed.push_back(new_elem);
  }

  


  void lazy_insert_leftist::delete_min() {
    (void) find_min();
    lt_node* old_root = root;
    root = unite(root->left, root->right);
    delete (old_root);
  }



