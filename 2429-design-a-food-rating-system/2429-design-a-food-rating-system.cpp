class FoodRatings {
public:
    map<string, pair<string, int>> foodToCuisineAndRating;
    map<string, map<int, set<string>>> cuisineToRatingAndFoods;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisineAndRating[foods[i]] = {cuisines[i], ratings[i]};
            cuisineToRatingAndFoods[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto foodInfo = foodToCuisineAndRating.find(food);
        string cuisine = foodInfo->second.first;
        int oldRating = foodInfo->second.second;
        foodInfo->second.second = newRating;

        cuisineToRatingAndFoods[cuisine][oldRating].erase(food);
        if (cuisineToRatingAndFoods[cuisine][oldRating].empty())
            cuisineToRatingAndFoods[cuisine].erase(oldRating);

        cuisineToRatingAndFoods[cuisine][newRating].insert(food);
        
    }
    
    string highestRated(string cuisine) {

        return *cuisineToRatingAndFoods[cuisine].rbegin()->second.begin();

        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */