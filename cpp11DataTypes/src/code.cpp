#include <cpp11.hpp>
#include <iostream>

using namespace cpp11;
using namespace std;

[[cpp11::register]]
void print_df_by_col(cpp11::data_frame df, int which_col){

  // you can extract a column from a data_frame by passing it into
  // a declaration of a doubles vector
  cpp11::doubles column(df[which_col - 1]);

  // cycle through each row in the column and print it out
  for(int i = 0; i < df.nrow(); i++){
    cout << column[i]  << endl;
  }

}

[[cpp11::register]]
void print_df_by_row(cpp11::data_frame df, int which_row){

  // cycle through each column in the df and print the value from the chosen row
  for(int i = 0; i < df.ncol(); i++){
    cpp11::doubles column(df[i]);
    cout << column[which_row-1]  << endl;
  }

}
