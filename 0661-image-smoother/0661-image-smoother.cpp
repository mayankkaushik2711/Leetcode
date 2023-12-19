class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        

        int row=img.size();
        int col=img[0].size();

        vector<vector<int>> naya(row,vector<int>(col,0));

        for(int i=0 ; i<row ; i++){
            int sum=0;
            int cnt=0;
            for(int j=0 ; j<col ; j++){
                //right
                sum +=img[i][j];
                cnt++;
                if(j+1<col){
                    sum=sum+img[i][j+1];
                    cnt++;
                }
                //down
                if(i+1<row){
                    sum=sum+img[i+1][j];
                    cnt++;
                }
                //left
                if(j-1>=0){
                    sum=sum+img[i][j-1];
                    cnt++;
                }
                //top
                if(i-1>=0){
                    sum=sum+img[i-1][j];
                    cnt++;
                }
                //lowleftcorner
                if(i+1<row && j-1>=0){
                    sum=sum+img[i+1][j-1];
                    cnt++;
                }
                //lowrightcorner
                if(i+1<row && j+1<col){
                    sum=sum+img[i+1][j+1];
                    cnt++;
                }
                //uprightcorner
                if(i-1>=0 && j+1<col){
                    sum=sum+img[i-1][j+1];
                    cnt++;
                }
                //upleftcorner
                if(i-1>=0 && j-1>=0){
                    sum=sum+img[i-1][j-1];
                    cnt++;
                }
                sum=sum/cnt;
                naya[i][j]=sum;
                sum=0;
                cnt=0;

            }
        }
        return naya;

        
    }

};