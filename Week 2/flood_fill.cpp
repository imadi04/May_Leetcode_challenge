class Solution {
public:
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor,int currColor,int r,int c){
         
        if(sr>r || sc>c || sr<0 || sc<0)
            return image;
         if(image[sr][sc]!=currColor)
            return image;
         if(image[sr][sc]==newColor)
             return image;
        image[sr][sc]=newColor;
        floodFill(image,sr-1,sc,newColor,currColor,r,c);
        floodFill(image,sr,sc-1,newColor,currColor,r,c);
        floodFill(image,sr,sc+1,newColor,currColor,r,c);
        floodFill(image,sr+1,sc,newColor,currColor,r,c);
        return image;
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor=image[sr][sc];
        //cout<<currColor;
        int r=image.size()-1;
         int c=image[0].size()-1;
        return floodFill(image,sr,sc,newColor,currColor,r,c);
        
    }
};