// my method(TLE)
// disadvantage: The bad condition for search function is O(t) t is all the shop with moive
// drop and rent find out the result with O(n) due to for loop.
// if we use the function in the set, map (red black tree), with fast search and delete O(n)
// std::set::find() 的時間複雜度是 O(logn)。
// std::set::insert() 的時間複雜度是 O(logn)。
// std::set::erase() 的時間複雜度是 O(logn)。
class MovieRentingSystem {
// private:
    // thought we need a data structure for search to find out the cheapest 5 shops of a given movie
    unordered_map<int,set<tuple<int,int,bool>>> movietoshop; // set<prices,shop,rented bool>
    set<tuple<int,int,int>> rented; // prices,shops,movie
    int totalshop = 0;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        totalshop = n;
        for(int i = 0;i < entries.size();i++)
        {
            movietoshop[entries[i][1]].insert({entries[i][2],entries[i][0],false});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> cheapestmovie;
        int count = 0;
        for(auto it = movietoshop[movie].begin(); it!=movietoshop[movie].end();it++)
        {
            const auto& [price, shop, rented_status] = *it;
            if(!rented_status)
            {
                cheapestmovie.push_back(shop);
                count++;
            }

            if(count == 5) return cheapestmovie;
        }

        return cheapestmovie;
    }
    
    void rent(int shop, int movie) {
        for(auto it = movietoshop[movie].begin(); it!= movietoshop[movie].end();it++)
        {
            const auto [price, shopit, rented_status] = *it;
            if(shopit == shop && !rented_status)
            {
                movietoshop[movie].insert({price, shop,true});
                it = movietoshop[movie].erase(it);
                // it.third = true;
                rented.insert({price,shop,movie});// prices,shops,movie
                break;
            }
        }


    }
    
    void drop(int shop, int movie) {
        for(auto it = movietoshop[movie].begin(); it!= movietoshop[movie].end();it++)
        {
            const auto [price, shopit, rented_status] = *it;
            if(shopit == shop && rented_status)
            {
                // it.third = false;
                movietoshop[movie].insert({price, shop, false});
                it = movietoshop[movie].erase(it);

                auto find = rented.find({price,shop,movie});
                if(find != rented.end())
                    rented.erase(find);// prices,shops,movie
                break;
            }
        }
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for(auto it = rented.begin();it!=rented.end();it++)
        {
            const auto [price, shop, movie] = *it;
            res.push_back({shop,movie});
            count++;
            if(count == 5) return res;
        }

        return res;

    }
};

// /**
//  * Your MovieRentingSystem object will be instantiated and called as such:
//  * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
//  * vector<int> param_1 = obj->search(movie);
//  * obj->rent(shop,movie);
//  * obj->drop(shop,movie);
//  * vector<vector<int>> param_4 = obj->report();
//  */

// source: https://leetcode.com/problems/design-movie-rental-system/solutions/7209904/begineer-friendly-intuitive-solution-self-explanatory-code-c-java-python
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

class MovieRentingSystem {
private:
    // Maps movie ID to a sorted set of {price, shop} pairs for available movies.
    map<int, set<pair<int, int>>> available_movies;

    // A sorted set of {price, shop, movie} tuples for all rented movies.
    set<tuple<int, int, int>> rented_movies;

    // Maps {shop, movie} pair to its price for quick lookups.
    map<pair<int, int>, int> prices;

public:
    /**
     * @brief Initializes the system with shops and movie entries.
     */
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            prices[{shop, movie}] = price;
            available_movies[movie].insert({price, shop});
        }
    }

    /**
     * @brief Finds the cheapest 5 shops for an unrented movie.
     */
    vector<int> search(int movie) {
        vector<int> result;
        if (available_movies.count(movie)) {
            auto& shops = available_movies.at(movie);
            int count = 0;
            for (const auto& p : shops) {
                if (count >= 5) break;
                result.push_back(p.second); // p.second is shop_id
                count++;
            }
        }
        return result;
    }

    /**
     * @brief Rents a movie from a specific shop.
     */
    void rent(int shop, int movie) {
        int price = prices.at({shop, movie});
        
        // Move from available to rented
        available_movies.at(movie).erase({price, shop});
        rented_movies.insert({price, shop, movie});
    }

    /**
     * @brief Drops off a rented movie at a shop.
     */
    void drop(int shop, int movie) {
        int price = prices.at({shop, movie});

        // Move from rented back to available
        rented_movies.erase({price, shop, movie});
        available_movies.at(movie).insert({price, shop});
    }

    /**
     * @brief Reports the cheapest 5 rented movies.
     */
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (const auto& t : rented_movies) {
            if (count >= 5) break;
            // Report contains {shop, movie}
            result.push_back({get<1>(t), get<2>(t)});
            count++;
        }
        return result;
    }
};
