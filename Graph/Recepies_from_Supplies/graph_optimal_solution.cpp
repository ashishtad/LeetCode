
/*

Optimal Topological Sort using Graph 
======================================

1. Build a dependency graph

    If a recipie A is dependent on ingredient which itself is a recipie B then add edge from B to A.
    Why graph is formed for a recipie which is dependent on an ingredient which is only a recipie ?
    This is because Supplies are always available from the start — no processing needed.
    But if an ingredient is itself a recipe, it must be built first before it can be used in another recipe.

2. Place recipies and supplies in a unordered_set for quick loop.

3. Form the indegree map

    For each recipe, count how many ingredients it still needs (i.e., ingredients not in the supplies set).
    This is the in-degree for that recipe.
    Now for recipie having indegree 0 (all the ingredients available in supply) we know that we can make this recipe immediately

4. So push the recipie with 0 indegree to queue for processing.
    
    Pop and add the recipie to result list.

5. Reduce the indegree value for the processed recipie's neighbour in graph. Neighbours are basically the recipies dpendent on the recipie which processed at #4.
6. If any recipie indegree becomes 0 push into queue and repeat step 4. 

7. Return result list.
*/


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        
        unordered_set<string> recipies_set(recipes.begin(), recipes.end());
        unordered_set<string> supply_set(supplies.begin(), supplies.end());
        /* Graph formation */
        unordered_map<string, vector<string>> recipie_dep;
        unordered_map<string,int> recipie_indegree;
        for(int i=0; i<recipes.size(); ++i) {
            for(const string &ingredient: ingredients[i]) {
                if(supply_set.find(ingredient) == supply_set.end() && 
                recipies_set.find(ingredient) != recipies_set.end()) recipie_dep[ingredient].push_back(recipes[i]);

                if(supply_set.find(ingredient) == supply_set.end()) recipie_indegree[recipes[i]]++;
            }
        }
        /* Those recipies which are not part of indegree map yet , that means they have all the ingredients supplied .
           These recipie(s) can be processed now.
        */
        queue<string> q;
        for( const string &recipie: recipes) {
            if(recipie_indegree.count(recipie)==0) q.push(recipie); 
        }
        vector<string> result;
        while(!q.empty()) {
            string process_recipie = q.front();
            q.pop();
            result.push_back(process_recipie);
            for( const string &recipie: recipie_dep[process_recipie]) {
                --recipie_indegree[recipie];
                if(recipie_indegree[recipie] ==0) q.push(recipie);
            }
        }
        return result;
    }
};