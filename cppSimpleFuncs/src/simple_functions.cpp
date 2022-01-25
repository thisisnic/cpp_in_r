#include "cpp11/declarations.hpp"

[[cpp11::register]]
int one() {
  return 1;
}

[[cpp11::register]]
integers ones(int n) {
  writable::integers out(n);
  for(int i = 0; i < n; ++i) {
    out[i] = 1;
  }
  return out;
}

[[cpp11::register]]
double mean_cpp(doubles x) {
  int n = x.size();
  double y = 0;

  for(int i = 0; i < n; ++i) {
    y += x[i] / n;
  }
  return y;
}


[[cpp11::register]]
bool any_cpp(logicals x) {
  int n = x.size();

  for(int i = 0; i < n; ++i) {
    if (x[i]) return true;
  }
  return false;
}

[[cpp11::register]]
bool all_cpp(logicals x) {
  int n = x.size();

  for (int i = 0; i < n; ++i) {
    if (!x[i]) return false;
  }
  return true;
}

[[cpp11::register]]
logicals greater_than(doubles x, double y) {

  int n = x.size();
  writable::logicals out(n);

  for (int i = 0; i < n; i++) {
    if(x[i] > y){
      out[i] = true;
    } else {
      out[i] = false;
    }
  }

  return out;
}

[[cpp11::register]]
doubles range_cpp(doubles x) {
  double omin = x[0], omax = x[0];
  int n = x.size();

  if (n == 0) stop("`length(x)` must be greater than 0.");

  for (int i = 1; i < n; i++) {
    omin = std::min(x[i], omin);
    omax = std::max(x[i], omax);
  }

  writable::doubles out(2);
  out[0] = omin;
  out[1] = omax;
  return out;
}
