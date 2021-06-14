Stock span problem
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.

Example:
Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6

Solution:
class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n) {
        vector<int> v;
        stack<pair<int,int>>s;
        for(int i=0; i<n; i++) {
            if(s.size()==0){
                v.push_back(-1);
            }
            else if (s.size()>0 && s.top().first>price[i]) {
                v.push_back(s.top().second);
            }
            else if (s.size()>0 && s.top().first<=price[i]) {
                while(s.size()>0 && s.top().first<=price[i]) {
                    s.pop();
                }
                if (s.size() == 0) {
                    v.push_back(-1);
                }
                else {
                    v.push_back(s.top().second);
                }
            }
            s.push({price[i],i});
        }
        for(int i=0; i<v.size(); i++) {
            v[i]=i-v[i];
        }
        return v;
    }
};
