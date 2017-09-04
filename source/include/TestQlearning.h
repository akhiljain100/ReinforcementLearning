#ifndef _TESTQLEARNING_H_
#define _TESTQLEARNING_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/agent.h"

using namespace std;



class TestQlearning{
public:
 
  TestQlearning();
  
  void printQPathAgent(Agent& a);
  
  private:
    
    vector<vector<string> > pathQAgent;
  
  };
  
#endif