//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MurderHornetAppTestApp.h"
#include "MurderHornetAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MurderHornetAppTestApp::validParams()
{
  InputParameters params = MurderHornetAppApp::validParams();
  return params;
}

MurderHornetAppTestApp::MurderHornetAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MurderHornetAppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MurderHornetAppTestApp::~MurderHornetAppTestApp() {}

void
MurderHornetAppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MurderHornetAppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MurderHornetAppTestApp"});
    Registry::registerActionsTo(af, {"MurderHornetAppTestApp"});
  }
}

void
MurderHornetAppTestApp::registerApps()
{
  registerApp(MurderHornetAppApp);
  registerApp(MurderHornetAppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MurderHornetAppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MurderHornetAppTestApp::registerAll(f, af, s);
}
extern "C" void
MurderHornetAppTestApp__registerApps()
{
  MurderHornetAppTestApp::registerApps();
}
