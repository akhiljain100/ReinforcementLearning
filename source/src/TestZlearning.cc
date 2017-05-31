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

} 
