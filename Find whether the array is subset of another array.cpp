string isSubset(int a1[], int a2[], int n, int m) {
    int count=0;
    string ans=" ";
    //store elements of a1[] in map
	unordered_map<int,int> M;
    
    if(m>n)
    {
        ans="No";
        return ans;
    }
    else if(m<=n)
    {
        
        for(int i=0;i<n;i++)
        {
            int value=1;
            int key=a1[i];
            M.insert({key,value});
        }
        
        //now iterate a2[]and check if all elements of a2[] are there in a1[]
        for(int j=0;j<m;j++)
        {
            int key=a2[j];
            //dekho kitne elements present hai
            if(M.find(key)!=M.end())
            {
                count++;
            }
        }
        if(count==m)
        {
        	ans="Yes";
            return ans;
        }
        else if(count!=m)
        {
            ans="No";
            return ans;
        }
        
    }
    
}
