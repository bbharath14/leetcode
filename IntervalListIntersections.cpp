class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        std::sort(A.begin(),A.end());
        std::sort(B.begin(),B.end());
        std::vector<vector<int>> res;
        for(int i=0,j=0;i<A.size() && j<B.size();){
            int s = max(A[i][0],B[j][0]);
            int e = min(A[i][1],B[j][1]);
            if(s<=e){
                res.push_back({s,e});
            }
            if(A[i][1]<B[j][1]){
                i++;
            }else if(A[i][1]>B[j][1]){
                j++;
            }else{
                if(A[i][0]<B[j][0]){
                    i++;
                }else{
                    j++;
                }
            }
        }
        return res;
    }
};
