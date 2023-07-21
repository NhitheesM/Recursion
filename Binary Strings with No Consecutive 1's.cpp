void binaryGenerator(vector<string> &ans,int n){
    if(n==0){
        return;
    }
    vector<string> temp(begin(ans), end(ans));
    ans.clear();
    for(int i=0;i<temp.size();i++){
        string tempStr=temp[i];
        if(tempStr[tempStr.size()-1]=='0'){
            ans.push_back(tempStr+"0");
            ans.push_back(tempStr+"1");
        }
        else{
            ans.push_back(tempStr+"0");
        }
    }
    binaryGenerator(ans,n-1);
}
vector<string> generateString(int N) {
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    binaryGenerator(ans,N-1);
    return ans;
}