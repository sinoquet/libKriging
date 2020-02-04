#include <RcppArmadillo.h>
#include "libKriging/LinearRegression.hpp"

// [[Rcpp::export]]
Rcpp::List linear_regression(arma::vec y, arma::mat X) {
  LinearRegression rl;
  auto ans = rl.apply(y, X);
  return Rcpp::List::create(Rcpp::Named("coefficients") = std::get<0>(ans),
                            Rcpp::Named("stderr") = std::get<1>(ans));
}

#include "libKriging/Kriging.hpp"

// [[Rcpp::export]]
Rcpp::List KrigingFit(arma::vec y, arma::mat X, arma::vec theta, arma::mat Xtest) {
  Kriging km;
  auto ans = km.apply(y, X, theta, Xtest);
  return Rcpp::List::create(Rcpp::Named("hyperparam") = std::get<0>(ans),
                            Rcpp::Named("theta") = std::get<1>(ans),
							Rcpp::Named("prediction") = std::get<2>(ans));
}