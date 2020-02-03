//
// Created by Hackathon on 2020-02-03.
//

#ifndef LIBKRIGING_KRIGING_HPP
#define LIBKRIGING_KRIGING_HPP

#include <armadillo>
#include "libKriging_exports.h"

/** Basic Kriging
 * @ingroup Regression
 */
class Kriging {
 public:
  /** Trivial constructor */
  LIBKRIGING_EXPORT Kriging();
  /** Kriging
   * has to find s such that y ~= X * s
   * The accuracy may be evaluated using the returned standard error
   *
   * @param y : rhs vector of size n
   * @param X : matrix of size n * m
   * @return tuple(s,standard error)
   */
  LIBKRIGING_EXPORT std::tuple<arma::mat, arma::vec, arma::vec> apply(const arma::vec y, const arma::mat X, const arma::vec theta, const arma::mat Xtest);
};

#endif  // LIBKRIGING_KRIGING_HPP
