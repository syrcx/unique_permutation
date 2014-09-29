#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Compare {
    string forcomp;
    bool operator() (int i, int j) {
        return forcomp[i] < forcomp[j];
    }
    
    Compare (string s) {
        forcomp = s;
    }
};

class Solution {
public:
    vector<vector<int> > permUnique(string perm_str) {
        vector<vector<int> > result;
        
        vector<int> index;
        for (int i=0; i<perm_str.length(); i++) {
            index.push_back(i+1);
        }
        
        Compare cobj(perm_str);
        sort(index.begin(), index.end(), cobj);
        for (int i=0; i<index.size(); i++) {
            cout << index[i] << " " << perm_str[index[i]-1] << endl;
        }
        
        perm(index, 0, result, perm_str);
        
        return result;
    }
    
    void perm(vector<int> &index, int start, vector<vector<int> > &result, string &perm_str) {
        if (start == index.size()-1) {
            result.push_back(index);
        }
        
        unordered_set<char> charset;
        for (int i=start; i<index.size(); i++) {
            if (charset.find(perm_str[index[i]-1]) != charset.end()) continue;
            
            charset.insert(perm_str[index[i]-1]);
            swap(index[start], index[i]);
            perm(index, start+1, result, perm_str);
            swap(index[start], index[i]);
        }
    }
};

void print(vector<vector<int> > &result) {
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void printstr(vector<vector<int> > &result, string &perm_str) {
    cout << result.size() << endl;
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << perm_str[result[i][j]-1] << " ";
        }
        cout << endl;
    }
}

int main(){
    Solution s;
    string perm_str = "";
    vector<vector<int> > result = s.permUnique(perm_str);
    print(result);
    printstr(result, perm_str);
}