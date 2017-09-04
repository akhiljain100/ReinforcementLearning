#include "../include/TestQlearning.h"
#include <iomanip>
TestQlearning::TestQlearning()
{

  
}

void TestQlearning::printQPathAgent(Agent& a)
{
	
	

	for (int i = 0; i < a.grid.ROW; i++)
	{
		vector <string> fillRow;
    	for (int j = 0; j < a.grid.COLUMN; j++)
      {
	 if(a.grid.grid[i][j] == 3 || a.grid.grid[i][j] == 2 )
      	fillRow.push_back("\e[1m * ");
      	//pathQAgent[i][j]= ;
      else if (a.grid.grid[i][j] == 1 )
      	fillRow.push_back("\e[0m x ");
      	
      //pathQAgent[i][j]= " X ";
      else {
      	fillRow.push_back("\e[0m o ");
      	
      	//pathQAgent[i][j]= " o ";
      }
      }
      pathQAgent.push_back(fillRow);
      }











int agentState;
int step = 0;
int row,column;
agentState = a.grid.start_state[0][0]*a.grid.COLUMN+a.grid.start_state[0][1];
row = (agentState / a.grid.COLUMN);
column =  agentState -  row* a.grid.COLUMN ;


while (step < a.steps && a.grid.grid[row][column] != 3)
{


pathQAgent[row][column] = "\e[1m * ";
//cout<<"no of step" << step << "\n\n";

//finding out the next possible states 

int max= 0;
cout << "\nAgent state" << agentState;
max= a.findActionMaxElement(agentState);
cout << "\nNext Action " << max;
if(max == 0){agentState=agentState-1; }
else if (max == 1){agentState=agentState+1;}
else if (max == 2){agentState= agentState-a.grid.COLUMN;}
else{agentState= agentState+a.grid.COLUMN;}  

cout << "\n Next State" << agentState;
   

row = (agentState / a.grid.COLUMN);
column =  agentState -  row* a.grid.COLUMN ;
//agentState = max;
step = step + 1;

}
cout <<"\n Number of steps after training " << step << "\n";

cout << "\n Q learning trained path ";







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
        cout  << pathQAgent[i][j] << " | ";
     

      	
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


