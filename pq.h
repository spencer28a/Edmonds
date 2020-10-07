#pragma once
// leftist trees with lazy insertion.
// use when enough tmore insertions than deletion are expected, so making
// insertion run in O(1) amortized time is imortant.  Other operations still run
// on O(log n) amortized time

// priority_t is assumned to have a method 
//  int evaluate()
// bad things might happen if priority_t's copy constructor or desructor are non-trivial
#include <vector>
#include <queue>

template <typename priority_t>

class lazy_insert_leftist {
  private:
    class lt_node {
      public:
      priority_t priority;
      lt_node* left;
      lt_node* right;
      int depth;
      lt_node(priority_t pri) : priority(pri), left(NULL), right(NULL), depth(1) {}
    };

    lt_node* root;
    std::vector<priority_t> unprocessed;

    lt_node* unite(lt_node* t1, lt_node* t2){
      if (t1 == NULL) return t2;
      if (t2 == NULL) return t1;
      if (t2->priority.evaluate() < t1->priority.evaluate()) {
        lt_node* t3 = t2;
        t2 = t1;
        t1 = t3;
      }
      t1->right = unite(t1->right, t2);
      if (t1->right != NULL && 
          (t1->left == NULL) ||(t1->right->depth > t1->left->depth)) {
        lt_node* tt = t1->right;
        t1->right = t1->left;
        t1->left = tt;
      }
      if (t1->right == NULL) {
        t1->depth = 1;
      } else {
        t1->depth = t1->right->depth+1;
      }
    }

    lt_node* make_lt_node(priority_t priority) {
      return new lt_node(priority);
    
    }


  public:
    lazy_insert_leftist() : root(NULL) { }
    void insert(priority_t new_item) {
      unprocessed.push_back(new_item);
    }

    priority_t find_min() {
      if (empty()) {
        printf("!!! error find_min of empty PQ\n");
      }
      std::queue<lt_node*> temp_trees;
      for (int index =0; index < unprocessed.size(); ++index) {
        temp_trees.push(make_lt_node(unprocessed[index]));
      }
      unprocessed.clear();
      while (temp_trees.size() > 1) {
        lt_node* t1;
        lt_node* t2;
        t1 = temp_trees.front();
        temp_trees.pop();
        t2 = temp_trees.front();
        temp_trees.pop();
        temp_trees.push(unite(t1, t2));
      }
      if (!temp_trees.empty())  {
        root = unite(root, temp_trees.front());
      }
      if (root != NULL) {
        return root->priority;
      } else {
        printf("Impossible thing happened\n");
      }
    }

    void delete_min() {
      (void) find_min();
      lt_node* old_root = root;
      root = unite(root->left, root->right);
      delete (old_root);
    }

    bool empty() {
      return unprocessed.empty() && root == NULL;
    }

    bool check_invarient() {
      return check_invarientw(root);
    }

    bool check_invarientw(lt_node* node) {
      if (node->left == NULL) {
        if (node->right !=NULL || node->depth != 1) {
          printf("error bad leaf node");
          return false;
        }
        return true;
      } 
      if (node->priority.evaluate() > node->left->priority.evaluate()) {
        printf("error: left child is less than parent");
        return false;
      }
      if (!check_invarientw(node->left)) {
        printf("Error: problem in left child");
        return false;
      }
      if (node->right == NULL) {
        if (node->depth != 1) {
          printf("Error: leaf node's depth computed incorrectly");
          return false;
        }
        return true;
      }
      if (node->depth != node->right->depth+1) {
        printf("error node's depth computed incorrectly");
        return false;
      }
      // neither child is NULL
      if (!check_invarientw(node->right)) {
        printf("Error: problem in right child");
        return false;
      }
       if (node->priority.evaluate() > node->right->priority.evaluate()) {
        printf("error: right child is less than parent");
        return false;
      }
      if (node->right->depth > node->left->depth) {
        printf("Error: badly shaped tree-right child is higher than left");
        return false;
      }
      return true;
    }
};

class base_priority {
  virtual int evaluate() = 0;
  // virtual bool is_less (const base_priority& other)=0;


};

#if 0
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





class int_priority : base_priority {
  public:
  int value;

  int evaluate() {
    return value;
  }
  
  


};
#endif