class Solution
{
    unordered_map<string, set<string>> maptickets; // set is sorted so it gets sorted in lexical order itself
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {                                    // tickets->"abc", "def"
        for (vector<string> t : tickets) // building graph
            maptickets[t[0]].insert(t[1]);

        vector<string> result;
        dfs(result, "JFK");                    // starting from JFK
        reverse(result.begin(), result.end()); // result is created during return time of recursion thus reverse needed
        return result;                         // returning result
    }

    void dfs(vector<string> &result, string source)
    {
        while (!maptickets[source].empty())
        {
            string dest = *maptickets[source].begin();            // declaring iterator for finding dest
            maptickets[source].erase(maptickets[source].begin()); // deleting after travelling
            dfs(result, dest);
        }
        result.push_back(source); // pushing into result
    }
};