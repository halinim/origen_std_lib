#ifndef ORIGEN_TEST_METHOD_DC_MEASUREMENT_INCLUDED
#define ORIGEN_TEST_METHOD_DC_MEASUREMENT_INCLUDED

#include "base.hpp"
#include "mapi.hpp"
#include "rdi.hpp"
#include "LevelSetup.h"

using namespace std;

namespace Origen {
namespace TestMethod {

class DCMeasurement : public Base {
  void serialProcessing(int site);

  int _applyShutdown;
  string _shutdownPattern;
  int _checkShutdown;
  string _measure;
  double _settlingTime;
  string _pin;
  string _port;
  double _forceValue;
  double _iRange;
  int _processResults;
  int _badc;
  LevelSetup* _lvlSet;
  bool _lvlSetup_defined;

 public:
  DCMeasurement();
  virtual ~DCMeasurement();
  void SMC_backgroundProcessing();

  DCMeasurement& applyShutdown(int v);
  DCMeasurement& shutdownPattern(string v);
  DCMeasurement& checkShutdown(int v);
  DCMeasurement& measure(string v);
  DCMeasurement& settlingTime(double v);
  DCMeasurement& pin(string v);
  DCMeasurement& port(string v);
  DCMeasurement& forceValue(double v);
  DCMeasurement& iRange(double v);
  DCMeasurement& processResults(int v);
  DCMeasurement& badc(int v);
  DCMeasurement& setLevelSetup(LevelSetup* lvlsetup);
  DCMeasurement& setLevelSetup_defined(bool lvlsetup_defined);
  
 protected:
  typedef DCMeasurement super;
  DCMeasurement& getThis();
  void _setup();
  void _execute();

  string label;
  vector<int> funcResultsPre;
  vector<int> funcResultsPost;
  vector<double> results;
};
}
}
#endif
