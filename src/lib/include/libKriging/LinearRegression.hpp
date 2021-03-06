//
// Created by Pascal Havé on 2019-08-13.
//

#ifndef LIBKRIGING_LINEARREGRESSION_HPP
#define LIBKRIGING_LINEARREGRESSION_HPP

#include <armadillo>
#include "libKriging_exports.h"

/** Basic linear regression
 * @ingroup Regression
 */
class LinearRegression {
 public:
  /** Trivial constructor */
  LIBKRIGING_EXPORT LinearRegression();
  /** True linear regression computation
   * has to find s such that y ~= X * s
   * The accuracy may be evaluated using the returned standard error
   *
   * @param y : rhs vector of size n
   * @param X : matrix of size n * m
   * @return tuple(s,standard error)
   */
  LIBKRIGING_EXPORT std::tuple<arma::colvec, arma::colvec> apply(const arma::vec& y, const arma::mat& X);
};

#endif  // LIBKRIGING_LINEARREGRESSION_HPP
