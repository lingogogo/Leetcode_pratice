class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        // if(path[0] !)
        string output = "";
        vector<string> dirvec;
        int cur = 0;
        while(cur < n)
        {
            if(path[cur] == '.'){
                int start = cur;
                int count_dot = 0;
                // cur++;
                // cout << cur << endl;
                // cout << "In the count dot" << endl;
                while(path[cur] == '.' && cur < n)
                {
                    count_dot++;
                    cur++;
                }
                // cout << "count_dot: " << count_dot << endl;
                // cout << cur << endl;
                // path[cur] now is / or character
                if(path[cur] == '/' || cur == n){
                    if(count_dot >2) dirvec.push_back(path.substr(start,cur - start));
                    else if(count_dot == 2){
                        // means that we have to return a directory
                        // cout << dirvec.size() << endl;
                        if(!dirvec.empty()){
                            // cout << dirvec.back() << endl;
                            dirvec.pop_back();
                        }
                           
                    }
                    // count_dot == 1 mean that maintain the current directory or file.
                    // No action
                }else{
                    while(path[cur] != '/' && cur < n){
                        cur++;
                    }
                    dirvec.push_back(path.substr(start,cur - start));
                    // path[cur] now is /
                }
            }else if(path[cur] != '/')
            {
                // the directory or file name
                int start = cur;
                while(path[cur] != '/' && cur < n){
                    cur++;
                }
                // cout << "lower else if" << endl;
                dirvec.push_back(path.substr(start,cur - start));
                // cout << dirvec.back() << endl;
                // path[cur] now is /
            }
            cur++;
        }
        output+='/';
        // cout << output << endl;
        for(int i = 0;i < dirvec.size(); i++)
        {
            output += dirvec[i];
            // cout << output << endl;
            if(i != dirvec.size() - 1) output +='/';
            else break;
            // output +='/';
        }

        return output;
    }
};
