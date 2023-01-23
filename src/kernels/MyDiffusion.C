#include "MyDiffusion.h"

registerMooseObject("eagleApp", MyDiffusion);

InputParameters
MyDiffusion::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addClassDescription("My diffusion kernel with a diffusion coefficient");
  params.addParam<Real>("diffusion_coef", 1, "Diffusion coefficient");

  return params;
}

MyDiffusion::MyDiffusion(const InputParameters & parameters)
  : Kernel(parameters),
  _diff(getParam<Real>("diffusion_coef"))
{
}

Real
MyDiffusion::computeQpResidual()
{
    return _diff * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
MyDiffusion::computeQpJacobian()
{
  return _diff * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}