//https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string str) {

    vector<string>v;
    string res ="";

    for( int i = 0; i < str.length(); i++){
        string path = "";

        //main motive of this loop is to store the char value between 2 '/'
        while(i < str.length() && str[i]!= '/'){
            path+= str[i++];
        }
        if(path =="" or path ==".") continue;

        // in linux .. means back hence we pop();
        else if(path == ".."){
            if(v.size() > 0){
                   v.pop_back();
            }
        }
        else{
            // if the path is a string with file name
            v.push_back(path);
        }
    }

    if(v.size() == 0){
        return "/";
    }
    for( int i = 0; i < v.size(); i++){
        res += "/"+v[i];
    }
    return res;
}    
