
#include "../include/gridworld.h"
#include "../include/agent.h"
#include "../include/TestZlearning.h"
#include "../include/TestQlearning.h"
#include <iomanip>
#include <map>
#include <string>
#include <iostream>

using namespace std;

/* The LoadConfig function loads the configuration file given by filename
     It returns a map of key-value pairs stored in the conifuration file */
std::map<std::string,std::string> LoadConfig(std::string filename)
{
	std::ifstream input(filename);
    std::map<std::string,std::string> ans; //A map of key-value pairs in the file
    while(input) //Keep on going as long as the file stream is good
    {
        std::string key; //The key
        std::string value; //The value
        std::getline(input, key, ':'); //Read up to the : delimiter into key

        std::getline(input, value, '\n'); 
        ans[key] = value;
    }
    input.close(); //Close the file stream
    return ans; //And return the result
}

int main(
    int    argc,
    char** argv
)
{
	std::map<std::string,std::string> conf = LoadConfig("../source/config/config.txt");
	
	std::cout << "Building the grid world\n\n";
	
	string filename="../source/gridworldmaps/grid.txt";
	

	Gridworld g;
	g.readGrid(filename);
	g.initializeModel();
	//g.printPassiveDynamics();
	
	Agent a(g);
	a.episodes=atoi(conf["episodes"].c_str());
	a.steps = atoi(conf["steps"].c_str());
	a.calpha = atoi(conf["calpha"].c_str());
	a.no_Ziter= atoi(conf["no_Ziter"].c_str());

	a.learnAgent();
	a.saveZIterationValue();
	//a.greedyZlearning();
	a.randomQlearning();
	
	TestQlearning qtest;
	qtest.printQPathAgent(a);
	//TestZlearning test;
	//test.calControlProb(a);
	//test.printPathAgent(a);
   

    return 0;
}


