#include <cpp11/declarations.hpp>
#include "./annoy/src/annoylib.h"
#include "./annoy/src/kissrandom.h"
#include <iostream>

using namespace std;
using namespace cpp11;

[[cpp11::register]]
integers annoy_euclidean(int n_trees){

  int f = 3;
  Annoy::AnnoyIndex<int, double, Annoy::Angular, Annoy::Kiss32Random, Annoy::AnnoyIndexSingleThreadedBuildPolicy> a =
    Annoy::AnnoyIndex<int, double, Annoy::Angular, Annoy::Kiss32Random, Annoy::AnnoyIndexSingleThreadedBuildPolicy>(f);

  double vec1[] = {0,0,1};
  double vec2[] = {0,1,0};
  double vec3[] = {1,0,0};

  a.add_item(0,vec1);
  a.add_item(1,vec2);
  a.add_item(2,vec3);

  a.build(n_trees);

  double test_vec[] = {1,2,3};

  std::vector<int> neighbor_index;
  std::vector<double> neighbor_dist;

  a.get_nns_by_vector(test_vec, 3, -1, &neighbor_index, &neighbor_dist);

  return cpp11::as_sexp(neighbor_index);

}
