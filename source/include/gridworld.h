#ifndef _GRIDWORLD_H_
#define _GRIDWORLD_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/** \file
    Declarations supporting Gridworld */


class Gridworld {
public:

  Gridworld();
  /** A representation of a rectangular grid with interior walls that
    allows users easily to determine available directions of travel in
    each cell.

     The map is loaded from a text file filled with numbers showing the map with the following
    coding for each cell:
    * 0: empty
    * 1: blocked
    * 2: start
    * 3: goal
   
    
    Also, Start states are filled in a 2D vector
    */

  void readGrid(string filename);

  /**
  * Initializing the state with the possible start state, The start state is chosen
  * in a systematic way, i.e, first occurence of the value 2 in the grid
  * ToDo: Make the initialization random so that each time we initialize it 
  * we can start from different start states which are possible in the grid
  * State information: Row and Column for determining the position of state in
  * the grid and the reward it contains.
  */
  void initializeModel();


  /*
  * Random selection of the possible action on the state and then we reward the state
  * depending on the next state.
  */
  void printPassiveDynamics();

  int actions[4][2]={{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
  int ROW, COLUMN;
  int no_state;
  vector<vector<int> > grid;

  vector<vector<int> > start_state;
  struct state_info{

    double prob_state;

  };
  state_info **s;

};
#endif