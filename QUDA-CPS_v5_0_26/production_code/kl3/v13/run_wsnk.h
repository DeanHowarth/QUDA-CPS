// -*- mode:c++; c-basic-offset:4 -*-
#ifndef INCLUDED_RUN_WSNK_H_KL3
#define INCLUDED_RUN_WSNK_H_KL3

#include <vector>
#include <alg/qpropw.h>
#include "prop_container.h"

// compute wall sink propagator
void run_wall_snk(std::vector<std::vector<cps::WilsonMatrix> > *wsnk,
                  const AllProp &prop);

#endif
