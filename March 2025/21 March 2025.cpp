/*
Find All Possible Recipes from Given Supplies
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
Return a list of all the recipes that you can create. You may return the answer in any order.
Note that two recipes may contain each other in their ingredients.
*/
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes,
                                      vector<vector<string>>& ingredients,
                                      vector<string>& supplies) {
            vector<string> possibleRecipes;
            // Track if ingredient/recipe can be made
            unordered_map<string, bool> canMake;
            // Map recipe name to its index in ingredients list
            unordered_map<string, int> recipeToIndex;

            // Mark all initial supplies as available
            for (const string& supply : supplies) {
                canMake[supply] = true;
            }

            // Create recipe to index mapping
            for (int idx = 0; idx < recipes.size(); idx++) {
                recipeToIndex[recipes[idx]] = idx;
            }

            // Try to make each recipe using DFS
            for (const string& recipe : recipes) {
                unordered_set<string> visited;
                checkRecipe(recipe, ingredients, visited, canMake, recipeToIndex);
                if (canMake[recipe]) {
                    possibleRecipes.push_back(recipe);
                }
            }

            return possibleRecipes;
        }

    private:
        void checkRecipe(const string& recipe, vector<vector<string>>& ingredients,
                         unordered_set<string>& visited,
                         unordered_map<string, bool>& canMake,
                         unordered_map<string, int>& recipeToIndex) {
            // Return if we already know if recipe can be made
            if (canMake.find(recipe) != canMake.end()) {
                return;
            }

            // Not a valid recipe or cycle detected
            auto idxIt = recipeToIndex.find(recipe);
            if (idxIt == recipeToIndex.end() || visited.count(recipe)) {
                canMake[recipe] = false;
                return;
            }

            visited.insert(recipe);

            // Check if we can make all required ingredients
            for (const string& ingredient : ingredients[idxIt->second]) {
                checkRecipe(ingredient, ingredients, visited, canMake,
                            recipeToIndex);
                if (!canMake[ingredient]) {
                    canMake[recipe] = false;
                    return;
                }
            }

            // All ingredients can be made
            canMake[recipe] = true;
        }
    };