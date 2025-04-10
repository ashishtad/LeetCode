
/*

Brute force Approach
=====================

1. Data Preparation:

    Build a map:
    unordered_map<string, vector<string>> recipeToIngredients
    This links each recipe to its required ingredients.

    Build a set:
    unordered_set<string> suppliesSet
    For fast O(1) lookups to check whether a supply is available.

2. Initial Check for Recipes That Can Be Immediately Made:

    For each recipe:
    Check if all its ingredients exist in suppliesSet.

    If yes:
    Add the recipe to:
    result list.
    suppliesSet (since it becomes a new supply).

    If no:
    Add it to a unvisited list of recipes.

3.Iteratively Check Unvisited Recipes:

    Repeat this process:

    For each recipe in unvisited:
    Check if all its ingredients are now in suppliesSet.

    If yes:
    Add it to result and suppliesSet.
    Remove it from unvisited.

    Continue this loop until no more recipes can be added in a full pass.

4. Return the result vector containing all the recipes that can be formed using the initial supplies and recursively buildable recipes.

*/


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        unordered_map<string, vector<string>> recipeToIngredients;
        for(int i=0; i<recipes.size(); ++i) {
            recipeToIngredients.emplace(recipes[i], ingredients[i]);
        }
        unordered_set<string> supplySet(supplies.begin(), supplies.end());

        vector<string> result; 
        unordered_set<string> unmadeRecipe;
        /* Check recipes that can be made with available supplie set */
        for(const auto &[recipe, ingredients] : recipeToIngredients) {
            bool found = true;
            for( const auto &ingredient: ingredients) {
                if(supplySet.find(ingredient) == supplySet.end()) {
                    found = false;
                    break;
                }
            }
            if(found) {
                result.push_back(recipe);
                supplySet.insert(recipe);
            } else {
                unmadeRecipe.insert(recipe);
            }
        }
        /* This determines that from unmade recipes yet a new recipe is formed
           and added to supply set so scan the unamdeRecipe list again */
        bool newSupAdded = true;
         /* Iterate the unmade receipes yet */
        while(newSupAdded) {
            newSupAdded = false;
            vector<string> toErase;
            for( const string &recipe: unmadeRecipe) {
                bool found = true;
                for( const auto  &ingredient: recipeToIngredients[recipe]) {
                    
                    if(supplySet.find(ingredient) == supplySet.end()) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    result.push_back(recipe);
                    supplySet.insert(recipe);
                    /* New supply added to supply set, scan unmade recipes to check if any recipe can be made*/
                    newSupAdded = true;
                    toErase.push_back(recipe);
                }
            }
            for( const string &eraseRecipe: toErase) unmadeRecipe.erase(eraseRecipe);
        }
        return result;

    }
};