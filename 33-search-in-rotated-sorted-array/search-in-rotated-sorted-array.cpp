class Solution {
public:
    
    int search(vector<int> &v) {
	    if(v.size()==1) return 0;
	    int i=0;
    	int j=v.size()-1;
	    while(i<=j) {
    		int mid = (i+j)/2;
		    if(mid<v.size()-2 && v[mid] > v[mid+1]) {
	    		return mid+1;
    		}	
		    else if(v[i] <= v[mid]) {
	    		i=mid+1;
    		}
		    else {
	    		j = mid-1;
    		}
	    }
    	if(v[0]<v[v.size()-1]) return 0;
	    return v.size()-1;
    }
    
    int BS(vector<int> v,int i,int j,int target) {
	    while(i<=j) {
		    int mid = (i+j)/2;
	    	if(v[mid] == target) {
    			return mid;
		    }
		    else if(v[mid] > target) {
			    j = mid-1;
    		}
	    	else{
		    	i = mid+1;
		    }
	    }
	    return -1;
    }

    
    int search(vector<int>& v, int target) {
        int ans=0,in = search(v);
        // cout << in << " " << target << " " << v[v.size()-1] << endl;
 		if(target <= v[v.size()-1]) ans = BS(v,in,v.size()-1,target) ;
 		else ans  = BS(v,0,in-1,target);
        return ans;
    }
};