#include "eagleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
eagleApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

eagleApp::eagleApp(InputParameters parameters) : MooseApp(parameters)
{
  eagleApp::registerAll(_factory, _action_factory, _syntax);
}

eagleApp::~eagleApp() {}

void
eagleApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"eagleApp"});
  Registry::registerActionsTo(af, {"eagleApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
eagleApp::registerApps()
{
  registerApp(eagleApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
eagleApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  eagleApp::registerAll(f, af, s);
}
extern "C" void
eagleApp__registerApps()
{
  eagleApp::registerApps();
}
