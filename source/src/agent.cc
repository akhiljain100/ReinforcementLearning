#include "../include/agent.h"
#include <iomanip>
//#include <math.h>
#include <Eigen/Dense>
using namespace Eigen;

Agent::Agent(const Gridworld& g)
{
  
  grid = g;

  for (int i = 0; i< grid.no_state; i++)
  { 
    
    z_value.push_back(1);
  }

  g_value = new double*[grid.no_state];
  for(int i = 0; i < grid.no_state; ++i)
    g_value[i] = new double[grid.no_state];


    for (int i = 0; i < grid.no_state; i++)
      {for (int j = 0; j < grid.no_state; j++)
       {
        g_value[i][j] = 0;
       }
      }
  


   for (int i = 0; i< grid.ROW; i++)
  { 
    for(int j = 0; j< grid.COLUMN; j++)
    {
      if(grid.grid[i][j] == 3)
        g_value[i*grid.COLUMN+j][i*grid.COLUMN+j] = exp(-0);
       // row.push_back(exp(-1));
      else if(grid.grid[i][j] == 0 || grid.grid[i][j] == 2)
         g_value[i*grid.COLUMN+j][i*grid.COLUMN+j] = exp(-1);
      
      // row.push_back(exp(0.001));
      else
         g_value[i*grid.COLUMN+j][i*grid.COLUMN+j] = exp(-5);
      
      //  row.push_back(exp(1));
    }
   // g_value.push_back(row);
  }




}

void Agent::learnAgent()
{

double dotmatrix[grid.no_state][grid.no_state];
  /*cout << "\n\n G Matrix exp(-q(i)) \n\n";
   for (int i = 0; i < grid.no_state; i++)
    {
      cout << " ";
      for (int j = 0; j < grid.no_state; j++)
      {
        cout << "-------";
        }
        cout << "\n";
        
        
      for (int j = 0; j < grid.no_state; j++)
      {
        if(j==0)cout << "| ";
        size_t save_prec = cout.precision();
        cout << fixed << setfill ('0')<< setprecision(2) << g_value[i][j] << " | ";
        cout.precision(save_prec);
      }
      cout << "\n";
      if(i+1 == grid.no_state)
      {
        cout << " ";
        for (int j = 0; j < grid.no_state; j++)
      {cout << "-------";
        }
      }
      
    }*/
  for(int i=0;i<grid.no_state;i++){
for(int j=0;j<grid.no_state;j++){
        dotmatrix[i][j]=0;
        for(int k=0;k<grid.no_state;k++){
dotmatrix[i][j]+=(g_value[i][k] * grid.s[k][j].prob_state);
}
}
}
/*
cout << "\n\n GP Matrix \n\n";
   for (int i = 0; i < grid.no_state; i++)
    {
      cout << " ";
      for (int j = 0; j < grid.no_state; j++)
      {
        cout << "-------";
        }
        cout << "\n";
        
        
      for (int j = 0; j < grid.no_state; j++)
      {
        if(j==0)cout << "| ";
        cout << fixed << setfill ('0')<< setprecision(2) << dotmatrix[i][j] << " | ";
      }
      cout << "\n";
      if(i+1 == grid.no_state)
      {
        cout << " ";
        for (int j = 0; j < grid.no_state; j++)
      {cout << "-------";
        }
      }
      
    }
*/

double temp_z = 0.0;
vector<double> vector_z;
for (int n= 0; n< no_Ziter; n++){
  //cout << "\n";
  z_value = vector_z;
  vector_z.clear();
 for(int i=0;i<grid.no_state;i++){
  temp_z=0.0;
for(int j=0;j<grid.no_state;j++){
       
temp_z +=z_value[j]*dotmatrix[i][j];

}
vector_z.push_back(temp_z);
}
/*
for(int i=0;i<grid.no_state;i++){
  cerr<< "   " << z_value[i];
}*/
}
}



void Agent::saveZIterationValue()
{
ofstream outfile("../Result/z_iteration.txt");
for(int i=0;i<grid.ROW;i++){

for(int j=0;j<grid.COLUMN;j++){
    outfile << -log(z_value[i*grid.COLUMN+j]) << " ";
}
outfile << "\n";
}
outfile.close();
}
void Agent::trainZlearning()
{ z_value.clear();
  for (int i = 0; i< grid.no_state; i++)
  { 
    
    z_value.push_back(1);
  }

int nextstate = 0;
int row, column, agentState;
vector<int> nextPossibleState;
double alpha;
int step = 0;
vector<vector<double> > zvalueAftereachepisode;
for (int episode = 0; episode < episodes ; episode++ )
{
 // Recomputing from the start state, right now we are just using the first start state
 // Todo: computing with random start state, expecting interesting result 
step = 0;
agentState = grid.start_state[0][0]*grid.COLUMN+grid.start_state[0][1];
row = (agentState / grid.COLUMN);
column =  agentState -  row* grid.COLUMN ;
//cout << steps <<grid.grid[row][column]<<step;
// Computing the z_value for state in each step based on the next state agent takes
while (step < steps && grid.grid[row][column] != 3)
{
row = (agentState / grid.COLUMN);
column =  agentState -  row* grid.COLUMN ;
//cout<<"no of step" << step << "\n\n";

//finding out the next possible states 
for(int i=0;i<grid.no_state;i++)
{
  if(grid.s[agentState][i].prob_state > 0)
  {
    nextPossibleState.push_back(i);
  }
}
/*
for(int k= 0; k< nextPossibleState.size(); k++)
{
  cout << nextPossibleState[k] << "state possible \n";
}
*/

// Random selection of the next state 
nextstate = nextPossibleState[rand() % nextPossibleState.size()];

// Clearing the vector so that we can reuse this vector for next states
nextPossibleState.clear();

alpha =  (double)calpha/(double)(calpha+step);

//cerr << "\nalpha " << alpha << "\n";
z_value[agentState] = (1-alpha)*z_value[agentState] + alpha* g_value[agentState][agentState]* z_value[nextstate];
agentState = nextstate;
step = step + 1;
}
//cout << "\n\n" << "no of episode " << episode << "\n\n";
zvalueAftereachepisode.push_back(z_value);
/*for(int i=0;i<grid.no_state;i++)
{
  cerr << "        " << z_value[i];

}
cout << "\n\n";*/
}

ofstream outfileZvalue("../Result/randomz_iteration_zvalue.txt");
for(int i=0;i<zvalueAftereachepisode.size();i++){

for(int j=0;j<zvalueAftereachepisode[i].size();j++){
  row = (j / grid.COLUMN);
column =  j -  row* grid.COLUMN ;
if(grid.grid[row][column] == 1)
{
  outfileZvalue << -log(0) << " ";
}
else{
    outfileZvalue << -log(zvalueAftereachepisode[i][j]) << " ";
    }
}

outfileZvalue << "\n";
}

ofstream outfile("../Result/randomz_iteration.txt");
for(int i=0;i<grid.ROW;i++){

for(int j=0;j<grid.COLUMN;j++){
    outfile << -log(z_value[i*grid.COLUMN+j]) << " ";
}
outfile << "\n";
}
outfile.close();
outfileZvalue.close();
}
void Agent::testZlearning()
{


}