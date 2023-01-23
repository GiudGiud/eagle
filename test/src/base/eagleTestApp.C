//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "eagleTestApp.h"
#include "eagleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
eagleTestApp::validParams()
{
  InputParameters params = eagleApp::validParams();
  return params;
}

eagleTestApp::eagleTestApp(InputParameters parameters) : MooseApp(parameters)
{
  eagleTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

eagleTestApp::~eagleTestApp() {}

void
eagleTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  eagleApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"eagleTestApp"});
    Registry::registerActionsTo(af, {"eagleTestApp"});
  }
}

void
eagleTestApp::registerApps()
{
  registerApp(eagleApp);
  registerApp(eagleTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
eagleTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  eagleTestApp::registerAll(f, af, s);
}
extern "C" void
eagleTestApp__registerApps()
{
  eagleTestApp::registerApps();
}
