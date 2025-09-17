class FoodRatings {
public:
unordered_map<string,int>foodratings;
unordered_map<string,set<pair<int,string>>>cusfood;
unordered_map<string,string>foodcus;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n= foods.size();
        for(int i=0;i<n;i++){
            foodratings[foods[i]]=-ratings[i];
            cusfood[cuisines[i]].insert({-ratings[i],foods[i]});
            foodcus[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldrating=foodratings[food];
        string cus=foodcus[food];
        cusfood[cus].erase({oldrating,food});
        foodratings[food]=-newRating;
        cusfood[cus].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cusfood[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */