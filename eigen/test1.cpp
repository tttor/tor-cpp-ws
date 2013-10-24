#include <iostream>
#include <Eigen/Dense>

#include <vector>

using Eigen::MatrixXd;

int main()
{
  using namespace std;
  using namespace Eigen;  
  
//  MatrixXd m(2,2);
////  m(0,0) = 3;
////  m(1,0) = 2.5;
////  m(0,1) = -1;
////  m(1,1) = m(1,0) + m(0,1);
//  std::cout << m << std::endl;

//  MatrixXd m2;
//  m2 = m2 + m2;
//  std::cout << m2 << std::endl;
  
//  MatrixXd  z = MatrixXd::Zero(3,3);
//  cout << z << endl;
//  
//  MatrixXd  o = MatrixXd::Ones(3,3);
//  cout << o << endl;
//    
//  MatrixXd  i = MatrixXd::Identity(3,3);
//  cout << i << endl;

//  // Algebraic ops on vector vs. vector
//  Vector3d v(1,2,3);
//  Vector3d w(1,0,0);
//  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;

  // to std::vector
  Vector3d v(1,2,3);
  cout << v(0) << endl;
  cout << "v.size()= " << v.size() << endl;
  
//  std::vector<double> v_stl;
//  v_stl = v;
}
