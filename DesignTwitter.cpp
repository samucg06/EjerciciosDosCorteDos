#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Twitter {
private:
    vector<tuple<int,int,int>> listaTweets;
    map<int, set<int>> siguiendo;
    int tiempo;

public:
    Twitter() {
        tiempo = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        listaTweets.push_back(make_tuple(userId, tweetId, tiempo));
        tiempo++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> resultado;
        
        for(int i = listaTweets.size() - 1; i >= 0 && resultado.size() < 10; i--) {
            
            int usuario = get<0>(listaTweets[i]);
            int tweet = get<1>(listaTweets[i]);
            
            if(usuario == userId || siguiendo[userId].count(usuario)) {
                resultado.push_back(tweet);
            }
        }
        
        return resultado;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            siguiendo[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        siguiendo[followerId].erase(followeeId);
    }
};
