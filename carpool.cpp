class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
                
        auto dropOff(trips);
        int currCap = 0;

        // Number of rows; 
        int m = trips.size(); 
  
        // Number of columns (Assuming all rows 
        // are of same size).  We can have different 
        // sizes though (like Java). 
        int n = trips[0].size();                       
  
        std::sort(trips.begin(),
            trips.end(),
            [] (const std::vector<int> &a, const std::vector<int> &b)
            {
                return a[1] < b[1];
            });
        std::sort(dropOff.begin(),
            dropOff.end(),
            [] (const std::vector<int> &a, const std::vector<int> &b)
            {
                return a[2] < b[2];
            });

        
        int curCap = 0;
        bool flag = false;
        
        for( int i = 0; i<trips.size();i++ ){
            curCap+=trips[i][0];
            for( int j = 0; j<dropOff.size();j++ ){
                if(flag){
                    j=0;
                }
                if(dropOff[j][2]<=trips[i][1]){
                    curCap-=dropOff[j][0];
                    dropOff.erase(dropOff.begin()+j);
                    flag = true;
                    
                }else{
                    break;
                }
            }
                            
            if(curCap > capacity){
                cout<<"Here: "<<curCap<<endl;
                return false;
            }
        }
        return true;
    }
};
