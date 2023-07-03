
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};






















// class Solution {
// public:
//     bool buddyStrings(string s, string goal) {
//         if(s.size()!= goal.size()){
//             return false;

//         }

//         if(s==goal){
//             vector<int> frequency(26,0);
//             for(auto& ch : s){
//                frequency[ch - 'a'] += 1;
//                if(frequency[ch - 'a'] == 2){
//                    return true;
//                }
//             }
//             return false;
//         }
//         int fInd = -1;
//         int sInd = -1;
        
//         for(int i=0; i<s.size(); ++i){
//             if(s[i] != goal[i]){
//                 if(fInd == -1){
//                     fInd = i;
//                 } else if(sInd == -1 ){
//                     sInd = i;
//                 }else{
//                     return false;
//                 }
//             }
//         }

//         if(sInd == -1){
//             return false;
//         }

//         return s[fInd] == goal[sInd] && s[sInd] == goal[fInd];

//     }
// };