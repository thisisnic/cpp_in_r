// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// code.cpp
void print_df_by_col(cpp11::data_frame df, int which_col);
extern "C" SEXP _cpp11DataTypes_print_df_by_col(SEXP df, SEXP which_col) {
  BEGIN_CPP11
    print_df_by_col(cpp11::as_cpp<cpp11::decay_t<cpp11::data_frame>>(df), cpp11::as_cpp<cpp11::decay_t<int>>(which_col));
    return R_NilValue;
  END_CPP11
}
// code.cpp
void print_df_by_row(cpp11::data_frame df, int which_row);
extern "C" SEXP _cpp11DataTypes_print_df_by_row(SEXP df, SEXP which_row) {
  BEGIN_CPP11
    print_df_by_row(cpp11::as_cpp<cpp11::decay_t<cpp11::data_frame>>(df), cpp11::as_cpp<cpp11::decay_t<int>>(which_row));
    return R_NilValue;
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_cpp11DataTypes_print_df_by_col", (DL_FUNC) &_cpp11DataTypes_print_df_by_col, 2},
    {"_cpp11DataTypes_print_df_by_row", (DL_FUNC) &_cpp11DataTypes_print_df_by_row, 2},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_cpp11DataTypes(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}