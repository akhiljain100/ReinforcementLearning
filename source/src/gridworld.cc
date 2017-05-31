#include "../include/gridworld.h"

#include <iomanip>
//state_info **s;

Gridworld::Gridworld()
{
  
}
void Gridworld::initializeModel()
{
  //Check for the starting state, if not found then the model is incomplete 
  if(!start_state.empty())
  {
    // Dynamically assigning 2d structure 
    no_state = ROW * COLUMN;
    //cout << no_state;
    s = (state_info **) malloc(sizeof(state_info *) * no_state);
    for(int i = 0; i < no_state; i++) 
    {
      s[i] = (state_info *) malloc(sizeof(state_info) * no_state);
    }
    for (int i = 0; i < no_state; i++)
      for (int j = 0; j < no_state; j++)
        s[i][j].prob_state = 0;
    // passive initialization of the probabilities of each state 
    for(int i = 0; i< ROW; i++)
    {
      for(int j = 0; j< COLUMN; j++)
      {
        int k = 4;
        vector <int> action_state;
        for (int m = 0; m < 4; m++)
        {
      
          if((i + actions[m][0]) < 0 || (j + actions[m][1])<0 || (i + actions[m][0]) == ROW || (j + actions[m][1]) == COLUMN || grid[i + actions[m][0]][j+actions[m][1]] == 1)
          {
            action_state.push_back(m);
            k--;
          }
        }

        if(grid[i][j] != 1 && grid[i][j] != 3)
         { 
          for (int m = 0; m < 4; m++)
          {
            if(!(find(action_state.begin(), action_state.end(),m)!= action_state.end()))
              { 
                if(m == 0)
                  s[i*COLUMN+j][i*COLUMN+j-COLUMN].prob_state = (double)(1/(double)k);
                else if (m == 1)
                  s[i*COLUMN+j][i*COLUMN+j+COLUMN].prob_state = (double)(1/(double)k);
                else if (m == 2)
                  s[i*COLUMN+j][i*COLUMN+j-1].prob_state = (double)(1/(double)k);
                else 
                  s[i*COLUMN+j][i*COLUMN+j+1].prob_state = (double)(1/(double)k);
                  
                }
              
          }
        
           }
           if(grid[i][j] == 3)
           {
            s[i*COLUMN+j][i*COLUMN+j].prob_state = 1;
           }
      }
    }
  
  }
   
  else 
  {

    cout << " No Start state found";
  }
}

void Gridworld::printPassiveDynamics()
{

    cout<< " \nTransition probabilities of the grid\n\n";
    for (int i = 0; i < no_state; i++)
    {
      cout << " ";
      for (int j = 0; j < no_state; j++)
      {
        cout << "-------";
        }
        cout << "\n";
        
        
      for (int j = 0; j < no_state; j++)
      {
        if(j==0)cout << "| ";
        cout << fixed << setfill ('0')<< setprecision(2) << s[i][j].prob_state << " | ";
      }
      cout << "\n";
      if(i+1 == no_state)
      {
        cout << " ";
        for (int j = 0; j < no_state; j++)
      {cout << "-------";
        }
      }
      
    }
  /*if (!s.Z.empty())
  {
    int rand_value = rand() % 4 ;
    int ns [] = { (s.row +actions[rand_value][0]), s.column +actions[rand_value][1]};
    cout <<"\n"<< s.row<< "\n";
    cout << s.column<< "\n";
    cout << "ns " << ns[0]<< ns[1] << "\n";


    if(ns[0] < 0 || ns[0] == ROW || ns[1] < 0 || ns[1] == COLUMN || grid[ns[0]][ns[1]] == 1)
      {
        cout << "no action";
        ns[0] = s.row;
        ns[1] = s.column;
      }
      else {
        s.row  = ns[0];
        s.column = ns[1];
        cout << "action";
      }

    cout << s.row;
    cout << s.column;
  }
  else {
    cout << "Please initialize the state";
  }*/
}

void Gridworld::readGrid(string filename)
{
  
    string line, word;
    fstream file;
    vector<int> row;
    file.open(filename, ios::in);
    
        
    while( getline(file, line))
    { 
      istringstream iss;
      iss.str(line);
      while (iss >> word)row.push_back(atoi(word.c_str()));
      grid.push_back(row);
      row.clear();       
    }


    ROW= grid.size();
    COLUMN = grid[0].size();
    for (int i = 0; i < grid.size(); i++)
    {
      cout << " ";
      for (int j = 0; j < grid[i].size(); j++)
      {
        cout << "----";
        }
        cout << "\n";
        
        
      for (int j = 0; j < grid[i].size(); j++)
      {
        if(j==0)cout << "| ";
        if(grid[i][j] == 2){ vector<int>m; m.push_back(i); m.push_back(j); start_state.push_back(m);}
        cout <<grid[i][j] << " | ";
      }
      cout << "\n";
      if(i+1 == grid.size())
      {
        cout << " ";
        for (int j = 0; j < grid[i].size(); j++)
      {cout << "----";
        }
      }
      
    }
    cout << "\n";

/*
    cout << "\nStarting state of the grid \n";
    for (int i = 0; i < start_state.size(); i++)
    {
      
      for (int j = 0; j < start_state[i].size(); j++)
      {
        cout << start_state[i][j] << "    ";
      }
      cout << "\n";
    }*/
    file.close();

}