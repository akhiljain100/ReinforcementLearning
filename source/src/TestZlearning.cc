#include "../include/TestZlearning.h"
#include <iomanip>
TestZlearning::TestZlearning()
{

  
}

void TestZlearning::calControlProb(const Agent& a)
{
	cs = (controlled_state **) malloc(sizeof(controlled_state *) * a.grid.no_state);
    for(int i = 0; i < a.grid.no_state; i++) 
    {
      cs[i] = (controlled_state *) malloc(sizeof(controlled_state) * a.grid.no_state);
    }
    for (int i = 0; i < a.grid.no_state; i++)
    {
    	double norm = 0;
       for(int k=0;k<a.grid.no_state;k++)
		{
  		if(a.grid.s[i][k].prob_state > 0)
  		{
  			norm += (a.grid.s[i][k].prob_state * a.z_value[k]);
  		}
		}
      for (int j = 0; j < a.grid.no_state; j++)
      {
      	if(a.grid.s[i][j].prob_state!= 0)
      		{
      			cs[i][j].control_prob = 	double(a.grid.s[i][j].prob_state * double(a.z_value[j]/double(norm)));
      		}
      	else
	      	{
	        cs[i][j].control_prob = 0;
	        }
	    }
	 }

/*
	 cout<< " \nControl probability of the grid\n\n";
    for (int i = 0; i < a.grid.no_state; i++)
    {
      cout << " ";
      for (int j = 0; j < a.grid.no_state; j++)
      {
        cout << "-------";
        }
        cout << "\n";
        
        
      for (int j = 0; j < a.grid.no_state; j++)
      {
        if(j==0)cout << "| ";
       // cout << fixed << setfill ('0')<< setprecision(2) << cs[i][j].control_prob << " | ";
      cerr << cs[i][j].control_prob << " | ";
      }
      cout << "\n";
      if(i+1 == a.grid.no_state)
      {
        cout << " ";
        for (int j = 0; j < a.grid.no_state; j++)
      {cout << "-------";
        }
      }
      
    }
    */

}

void TestZlearning::printPathAgent(const Agent& a)
{
	
	

	for (int i = 0; i < a.grid.ROW; i++)
	{
		vector <string> fillRow;
    	for (int j = 0; j < a.grid.COLUMN; j++)
      {
	 if(a.grid.grid[i][j] == 3 || a.grid.grid[i][j] == 2 )
      	fillRow.push_back("\e[1m * ");
      	//pathAgent[i][j]= ;
      else if (a.grid.grid[i][j] == 1 )
      	fillRow.push_back("\e[0m x ");
      	
      //pathAgent[i][j]= " X ";
      else {
      	fillRow.push_back("\e[0m o ");
      	
      	//pathAgent[i][j]= " o ";
      }
      }
      pathAgent.push_back(fillRow);
      }











int agentState;
int step = 0;
int row,column;
agentState = a.grid.start_state[0][0]*a.grid.COLUMN+a.grid.start_state[0][1];
row = (agentState / a.grid.COLUMN);
column =  agentState -  row* a.grid.COLUMN ;


while (step < a.steps && a.grid.grid[row][column] != 3)
{


pathAgent[row][column] = "\e[1m * ";
//cout<<"no of step" << step << "\n\n";

//finding out the next possible states 
int max = 0;
for(int i=0;i<a.grid.no_state;i++)
{

  if(cs[agentState][i].control_prob > cs[agentState][max].control_prob)
  {
  	max = i;
  }
}
agentState = max;
row = (agentState / a.grid.COLUMN);
column =  agentState -  row* a.grid.COLUMN ;
step = step + 1;

}
cout <<"\n Number of steps after training " << step << "\n";


cout << "\n Z learning trained path ";






      cout << "\n";
	for (int i = 0; i < a.grid.ROW; i++)
    {
      cout << " ";
      for (int j = 0; j < a.grid.COLUMN; j++)
      {
        cout << "------";
        }
        cout << "\n";
        
        
      for (int j = 0; j < a.grid.COLUMN; j++)
      {
        if(j==0)cout << "| ";
        cout  << pathAgent[i][j] << " | ";
     

      	
      }

      
      cout << "\n";
      if(i+1 == a.grid.ROW)
      {
        cout << " ";
        for (int j = 0; j < a.grid.COLUMN; j++)
      {cout << "------";
        }
      }
      
    }
}


