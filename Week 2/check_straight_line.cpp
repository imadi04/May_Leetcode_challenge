class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double m=0;
        double num=coordinates[1][1]-coordinates[0][1];
        double den=coordinates[1][0]-coordinates[0][0];
        m=(num/den);
        double c=(coordinates[0][1]-(m*coordinates[0][0]));
        
        for(int i=2;i<coordinates.size();i++)
        {
            if((coordinates[i][1]-(m*coordinates[i][0]))!=c)
                return false;
        }
        
        return true;
    }
};