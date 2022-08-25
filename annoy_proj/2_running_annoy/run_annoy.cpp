#include "/home/nic2/cpp/annoy/src/annoylib.h"
#include "/home/nic2/cpp/annoy/src/kissrandom.h"
#include <iostream>

using namespace std;

int main() {

  /*
   * Here is the R code I'm trying to replicate:
    f <- 3

    # create a new Annoy instance of type AnnoyAngular
    # f is the length of the vectors that the Annoy instance will be indexing
    a <- new(AnnoyAngular, f)

    # add item i (e.g. 0) with vector v (e.g. c(0,0,1))
    a$addItem(0, c(0,0,1))
    a$addItem(1, c(0,1,0))
    a$addItem(2, c(1,0,0))

    # build a forest of n_trees trees
    # more trees == higher precision
    # after calling build, no more trees can be added
    a$build(100)


    # Return the n closest items as an integer vector of indices
    a$getNNsByVector(c(3,2,1), 3) # 2 1 0
    a$getNNsByVector(c(1,2,3), 3) # 0 1 2
    a$getNNsByVector(c(2,0,1), 3) # 2 0 1
   *
   */
 

  int f = 3;
  Annoy::AnnoyIndex<int, double, Annoy::Angular, Annoy::Kiss32Random, Annoy::AnnoyIndexSingleThreadedBuildPolicy> a =
    Annoy::AnnoyIndex<int, double, Annoy::Angular, Annoy::Kiss32Random, Annoy::AnnoyIndexSingleThreadedBuildPolicy>(f);

  double vec1[] = {0,0,1};
  double vec2[] = {0,1,0};
  double vec3[] = {1,0,0};

  a.add_item(0,vec1);
  a.add_item(1,vec2);
  a.add_item(2,vec3);

  a.build(100);

  // a.save("test.nn");
  
  double test_vec[] = {1,2,3};

  std::vector<int> neighbor_index;
  std::vector<double> neighbor_dist;

  
  a.get_nns_by_vector(test_vec, 3, -1, &neighbor_index, &neighbor_dist);
  
  for (std::vector<int>::const_iterator i = neighbor_index.begin(); i != neighbor_index.end(); ++i)
      std::cout << *i << ' ';

  cout << endl;
  
  for (std::vector<double>::const_iterator i = neighbor_dist.begin(); i != neighbor_dist.end(); ++i)
      std::cout << *i << ' ';

  cout << endl;

  return 0;
}


