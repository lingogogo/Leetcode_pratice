class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;

        for(int i =0; i < dist.size();i++)
        {
            time.push_back(double(dist[i])/double(speed[i]));
        }

        sort(time.begin(),time.end());

        for(int i = 0; i < time.size(); i++)
        {

            if(time[i] <= i) return i;
        }
        //cout << dist[31] << " " <<dist[35] << " " << dist[39] <<endl;
        //cout << speed[31] << " " <<speed[35] << " " << speed[39] <<endl;
        
        return dist.size();
        
    }
};
