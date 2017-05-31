#ifndef _AGENT_H_
#define _AGENT_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/gridworld.h"
using namespace std;



class Agent {
public:
  
  Agent(const Gridworld& g);
  

  /* Learning the z_value via z iteration. The main focus of this function is to 
   * find out if the z_value converge or not. Also, at what rate does it converge 
   * We have state value matrix (G Matrix) and the transition probability matrix 
   * and we find out z(k+1) = GP z(k).
   */
  void learnAgent();
  /* Saving the z_value and plotting it on heatmap via python matplotlib for which we have 
   * python function 
   */
  void saveZIterationValue();

  /* Random movement of the agent to learn the z_value. We have episodes and steps to
   * control the exploration of the gridworld.
   * TODO:  Make a configuration file to take these inputs (episode and step, also other
   *  parameters)
   */

  void trainZlearning();

  /* Updating the controlled probability and then letting agent move based on it
   * Also, the state value function is calculated so that we know the total reward 
   * after each episode and then we average them out for getting the exact reward the 
   * learning has converged to
   */
  void testZlearning();
  
    int episodes;
    int steps;
    int calpha;
    int no_Ziter;
    Gridworld grid;

    vector<double> z_value;
    double** g_value;

  
  };
  
#endif