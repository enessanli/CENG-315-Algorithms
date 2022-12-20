#include "the5.h"

/* 
    in the5.h "struct Room" is defined as below:
    
    struct Room {
        int id;
        char content;
        vector<Room*> neighbors;
    };

*/
vector<int> yol;
int treasure=1;

vector<int> maze_trace1(vector<Room*> maze, int gelen, Room* roomum,vector<int> &path)
{
        path.push_back(roomum->id);
    yol.push_back(roomum->id);
    
    if(roomum->content=='*'){treasure=0;}
    
    
    
    for(int i = 0; i <roomum->neighbors.size();i++){
        int giren=0;
        int index=0;
        index=0;
        giren=0;
        for(int j=0;j<yol.size();j++){
            if(yol[j]==roomum->neighbors[i]->id){ giren=1; break;} //komşu geldiği yoldaysa ele
            
        }
        
        for(int k=0;k<maze.size();k++){
            if(maze[k]->id==roomum->neighbors[i]->id){ index=k;}
            
            
            
            
        }
        
        
        
        
        
        
        
        if(!giren)
        {   
            if(treasure){
            maze_trace1(maze,roomum->neighbors[i]->id,maze[index],path);
                                                path.push_back(gelen);

                
            }
        }
        
        
        
        
        
        
    }       // if(yol.size()!=0) yol.pop_back();

    return path;
    
}

vector<int> maze_trace(vector<Room*> maze) { 




    vector<int> path;
 
 
    path=maze_trace1(maze,maze[0]->id,maze[0],path);
    

    return path; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}


