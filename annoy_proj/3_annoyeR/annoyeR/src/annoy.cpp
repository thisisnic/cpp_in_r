#include <cpp11/declarations.hpp>
#include "cpp11/doubles.hpp"
#include "cpp11/matrix.hpp"
#include "cpp11/as.hpp"
#include "Rmath.h"
#include "./annoy/src/annoylib.h"
#include "./annoy/src/kissrandom.h"
#include <iostream>

using namespace std;
using namespace cpp11;

[[cpp11::register]]
integers annoy_euclidean(cpp11::doubles_matrix<cpp11::by_row> mat, cpp11::doubles_matrix<cpp11::by_row> test_vec, int n_trees){

  int f = mat.ncol();
  Annoy::AnnoyIndex<int, double, Annoy::Euclidean, Annoy::Kiss32Random, Annoy::AnnoyIndexSingleThreadedBuildPolicy> a =
    Annoy::AnnoyIndex<int, double, Annoy::Euclidean, Annoy::Kiss32Random, Annoy::AnnoyIndexSingleThreadedBuildPolicy>(f);

  int index = 0;

  for (auto row : mat) {
    double dbl_row[f];
    for(int i = 0; i < f; i++){
      dbl_row[i] = row[i];
    }
    a.add_item(index, dbl_row);
    index = index + 1;
  }

  a.build(n_trees);

  std::vector<int> neighbor_index;
  std::vector<double> neighbor_dist;

  // this is the line which isn't working as we need a pointer to a double array
  // from a doubles_matrix
  //const double input_vec[] = cpp11::as_cpp<doubles_matrix>(test_vec);

  double test_row[f];

  // This loops too many times somewhere
  for (auto row : test_vec) {
    for(int i = 0; i < f; i++){
      test_row[i] = row[i];
    }
  }

  a.get_nns_by_vector(test_row, f, -1, &neighbor_index, &neighbor_dist);

  return cpp11::as_sexp(neighbor_index);
}


integers annoy_euclidean_hardcoded(int n_trees){

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
