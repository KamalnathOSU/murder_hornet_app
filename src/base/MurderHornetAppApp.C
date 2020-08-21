#include "MurderHornetAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MurderHornetAppApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

MurderHornetAppApp::MurderHornetAppApp(InputParameters parameters) : MooseApp(parameters)
{
  MurderHornetAppApp::registerAll(_factory, _action_factory, _syntax);
}

MurderHornetAppApp::~MurderHornetAppApp() {}

void
MurderHornetAppApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MurderHornetAppApp"});
  Registry::registerActionsTo(af, {"MurderHornetAppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MurderHornetAppApp::registerApps()
{
  registerApp(MurderHornetAppApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MurderHornetAppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MurderHornetAppApp::registerAll(f, af, s);
}
extern "C" void
MurderHornetAppApp__registerApps()
{
  MurderHornetAppApp::registerApps();
}
