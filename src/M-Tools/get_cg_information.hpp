/*
  Name: Get_CG_Information
  Copyright: 
  Author: Allen Wang
  Date: 07/04/16 08:37
  Description: Load and extract CG information for fitting.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

class _get_CG_information{
      public:
             // The basic information must be loaded before the implementation of these followed getting.
             int Load_File(const char * infilename);
             // Getting Group information
             vector < vector <int> > group_inf();
             // Getting Bond information
             vector < vector <int> > bond_inf();
             // Getting Angle information
             vector < vector <int> > angle_inf();
             // Getting Torsion information
             vector < vector <int> > torsion_inf();
             
      private:
              vector < vector<string> > Inf_Group;
              vector < vector<string> > Inf_Bond;
              vector < vector<string> > Inf_Angle;
              vector < vector<string> > Inf_Torsion;
              vector <int> Line_Group;
              vector <int> Line_Bond;
              vector <int> Line_Angle;
              vector <int> Line_Torsion;
              
      };

int _get_CG_information:: Load_File(const char * infilename){
    ifstream infile(infilename, ifstream::in);
    if (!infile){
                 cout << "Error: Cannot open file : " << infilename << endl;
                 return 0;
                 }
                 
    string buffer;
    vector<string> Per_Inf;
    
    while(getline(infile, buffer)){
                          stringstream strin(buffer);
                          string One_Inf;
                          while(strin >> One_Inf){
                                      Per_Inf.push_back(One_Inf);
                                      }
                          
                          if (Per_Inf[0] == "Group"){
                                         Inf_Group.push_back(Per_Inf);
                                         Line_Group.push_back(Per_Inf.size());
                                         }
                          if (Per_Inf[0] == "Bond"){
                                         Inf_Bond.push_back(Per_Inf);
                                         Line_Bond.push_back(Per_Inf.size());
                                         }
                          if (Per_Inf[0] == "Angle"){
                                         Inf_Angle.push_back(Per_Inf);
                                         Line_Angle.push_back(Per_Inf.size());
                                         }
                          if (Per_Inf[0] == "Torsion"){
                                         Inf_Torsion.push_back(Per_Inf);
                                         Line_Torsion.push_back(Per_Inf.size());
                                         }
                          }
                 
    }

vector < vector <int> > _get_CG_information:: group_inf(){
       vector < vector<int> > Return_Inf;
       vector <int> Middle_Inf;
       for(int i=0; i<Inf_Group.size(); i++){
               for(int j=1; j<Line_Group[i]; j++){
                       Middle_Inf.push_back(atoi(Inf_Group[i][j].c_str()));
                       }
               Return_Inf.push_back(Middle_Inf);
               }
               
       return Return_Inf;
       
       }

vector < vector <int> > _get_CG_information:: bond_inf(){
       vector < vector<int> > Return_Inf;
       vector <int> Middle_Inf;
       for(int i=0; i<Inf_Bond.size(); i++){
               for(int j=1; j<Line_Bond[i]; j++){
                       Middle_Inf.push_back(atoi(Inf_Bond[i][j].c_str()));
                       }
               Return_Inf.push_back(Middle_Inf);
               }
       
       return Return_Inf;
       
       }
vector < vector <int> > _get_CG_information:: angle_inf(){
       vector < vector<int> > Return_Inf;
       vector <int> Middle_Inf;
       for(int i=0; i<Inf_Angle.size(); i++){
               for(int j=1; j<Line_Angle[i]; j++){
                       Middle_Inf.push_back(atoi(Inf_Angle[i][j].c_str()));
                       }
               Return_Inf.push_back(Middle_Inf);
               }
       
       return Return_Inf;
       
       }
vector < vector <int> > _get_CG_information:: torsion_inf(){
       vector < vector<int> > Return_Inf;
       vector <int> Middle_Inf;
       for(int i=0; i<Inf_Torsion.size(); i++){
               for(int j=1; j<Line_Torsion[i]; j++){
                       Middle_Inf.push_back(atoi(Inf_Torsion[i][j].c_str()));
                       }
               Return_Inf.push_back(Middle_Inf);
               }
       
       return Return_Inf;
       
       }

//END, Bye-Bye!!

