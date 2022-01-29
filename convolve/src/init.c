#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

SEXP _convolve_convolve2(SEXP input_sexp);

static const R_CallMethodDef CallEntries[] = {
  {"_convolve_convolve2", (DL_FUNC) &_convolve_convolve2, 2},
  {NULL, NULL, 0}
};

void R_init_convolve(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
