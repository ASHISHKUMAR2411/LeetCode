template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, greater<T>>
{
  public:

      bool remove(const T& value) {
          auto it = std::find(this->c.begin(), this->c.end(), value);
       
          if (it == this->c.end()) {
              return false;
          }
          if (it == this->c.begin()) {
              // deque the top element
              this->pop();
          }    
          else {
              // remove element and re-heap
              this->c.erase(it);
              std::make_heap(this->c.begin(), this->c.end(), this->comp);
         }
         return true;
     }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<pair<int,int>> v;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto o : mp){
            v.push_back({o.second, o.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        vector<int> ans;
        for(int i = 0 ; i  < k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};