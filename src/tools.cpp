#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {
}

Tools::~Tools() {
}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
		const vector<VectorXd> &ground_truth) {
	/**
	 TODO:
	 * Calculate the RMSE here.
	 */
	/*initilising the rmse vector*/
	VectorXd rmse(4);
	/* Initialising the rmse vector */
	for (unsigned int i = 0; i < rmse.size(); ++i) {
		rmse[i] = 0;
	}

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
		return rmse;
	}

	//accumulate squared residuals

	cout << "size of estimations array : " << estimations.size() << endl;
	for (unsigned int i = 0; i < estimations.size(); ++i) {
		VectorXd residual = estimations[i] - ground_truth[i];
		//coefficient-wise multiplication

		residual = residual.array() * residual.array();
		rmse += residual;
	}

	//calculate the mean
	rmse = rmse / estimations.size();

	//calculate the squared root
	rmse = rmse.array().sqrt();

	//return the result
	return rmse;
}
