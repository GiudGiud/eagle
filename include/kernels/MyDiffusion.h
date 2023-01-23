#pragma once

#include "Kernel.h"

/**
 *
 */
class MyDiffusion : public Kernel
{
public:
  static InputParameters validParams();

  MyDiffusion(const InputParameters & parameters);

protected:

  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

  const Real _diff;
};