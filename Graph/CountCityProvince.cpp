

/**
 * Number of Provinces.
 */

class Solution {
    void visit(int city,bool visited[],vector<vector<int>> & connected,int & totalCities){
        visited[city] = true;

        for(int nextCity = 0 ; nextCity < totalCities ; nextCity++){
            if(connected[city][nextCity] && visited[nextCity]==false){
                visit(nextCity,visited,connected,totalCities);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int totalCities = isConnected.size();

        bool visited[totalCities];
        for(int i = 0; i < totalCities; i++){
            visited[i] = false;
        }

        int provinces = 0;

        for(int city = 0 ; city < totalCities ; city++){
            
            if(visited[city]== false){
                visit(city,visited,isConnected,totalCities);
                provinces++;
            }
        }

        return provinces;
    }
};