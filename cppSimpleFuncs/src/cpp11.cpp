// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// one.cpp
int one();
extern "C" SEXP _cppSimpleFuncs_one() {
  BEGIN_CPP11
    return cpp11::as_sexp(one());
  END_CPP11
}
// one.cpp
integers ones(int n);
extern "C" SEXP _cppSimpleFuncs_ones(SEXP n) {
  BEGIN_CPP11
    return cpp11::as_sexp(ones(cpp11::as_cpp<cpp11::decay_t<int>>(n)));
  END_CPP11
}
// one.cpp
double mean_cpp(doubles x);
extern "C" SEXP _cppSimpleFuncs_mean_cpp(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(mean_cpp(cpp11::as_cpp<cpp11::decay_t<doubles>>(x)));
  END_CPP11
}
// one.cpp
bool any_cpp(logicals x);
extern "C" SEXP _cppSimpleFuncs_any_cpp(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(any_cpp(cpp11::as_cpp<cpp11::decay_t<logicals>>(x)));
  END_CPP11
}
// one.cpp
bool all_cpp(logicals x);
extern "C" SEXP _cppSimpleFuncs_all_cpp(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(all_cpp(cpp11::as_cpp<cpp11::decay_t<logicals>>(x)));
  END_CPP11
}
// one.cpp
logicals greater_than(doubles x, double y);
extern "C" SEXP _cppSimpleFuncs_greater_than(SEXP x, SEXP y) {
  BEGIN_CPP11
    return cpp11::as_sexp(greater_than(cpp11::as_cpp<cpp11::decay_t<doubles>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(y)));
  END_CPP11
}
// one.cpp
doubles range_cpp(doubles x);
extern "C" SEXP _cppSimpleFuncs_range_cpp(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(range_cpp(cpp11::as_cpp<cpp11::decay_t<doubles>>(x)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_cppSimpleFuncs_all_cpp",      (DL_FUNC) &_cppSimpleFuncs_all_cpp,      1},
    {"_cppSimpleFuncs_any_cpp",      (DL_FUNC) &_cppSimpleFuncs_any_cpp,      1},
    {"_cppSimpleFuncs_greater_than", (DL_FUNC) &_cppSimpleFuncs_greater_than, 2},
    {"_cppSimpleFuncs_mean_cpp",     (DL_FUNC) &_cppSimpleFuncs_mean_cpp,     1},
    {"_cppSimpleFuncs_one",          (DL_FUNC) &_cppSimpleFuncs_one,          0},
    {"_cppSimpleFuncs_ones",         (DL_FUNC) &_cppSimpleFuncs_ones,         1},
    {"_cppSimpleFuncs_range_cpp",    (DL_FUNC) &_cppSimpleFuncs_range_cpp,    1},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_cppSimpleFuncs(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}