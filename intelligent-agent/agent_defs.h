#ifndef AGENT_DEFS_H
#define AGENT_DEFS_H

extern "C" {
#include <router_defs.h>
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

#include <CAgntBase.h>

#endif /* AGENT_DEFS_H */
