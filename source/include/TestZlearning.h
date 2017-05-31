#ifndef _TESTZLEARNING_H_
#define _TESTZLEARNING_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/agent.h"

using namespace std;



class TestZlearning{
public:
 
  TestZlearning();
  
  void calControlProb(const Agent& a);
  
  private:
    struct controlled_state{

    double control_prob;

    };
    controlled_state **cs;
  
  };
  
#endif