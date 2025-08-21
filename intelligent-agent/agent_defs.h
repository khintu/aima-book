#ifndef AGENT_DEFS_H
#define AGENT_DEFS_H

extern "C" {
#include <router_defs.h>
#include <pthread.h>
}

#include <iostream>
#include <string>

using namespace std;

namespace AI {

  class Exception {
      string err;
  public:
    Exception(const string& e) : err(e) {} // Mark constructor as explicit
        
    // read chaining at call from left to right
    friend ostream& operator<<(ostream& o, const Exception& e) {
      o << e.err;
      return o;
    }
  };
}

/* --- Class headers by order of hierarchy --- */
#include <CAgntBase.h>
#include <CSimpleSearching.h>
#include <CThrdBase.h>
#include <CThrdAgent.h>
#include <CAbstractFactory.h>
#include <CThreadFactory.h>
#include <CVacuumWorld.h>

#endif /* AGENT_DEFS_H */
