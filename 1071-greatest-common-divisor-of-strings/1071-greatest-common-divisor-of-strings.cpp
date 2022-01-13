class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length() > str2.length())
            swap(str1,str2);
        for(int i = str1.length();i>=1;i--)
        {
            if(str1.length()%i != 0)
                continue;
            if(str2.length()%i != 0)
                continue;
            
            string s = str1.substr(0,i);
            int flag1 = 0;
            for(int j=0;j<str1.length();j+=i)
            {
                if(str1.substr(j,i) != s)
                {
                    flag1 = 1;
                    break;
                }
            }
            int flag2 = 0;
            for(int j=0;j<str2.length();j+=i)
            {
                if(str2.substr(j,i) != s)
                {
                    flag2 = 1;
                    break;
                }
            }
            
            if(!flag1 && !flag2)
                return s;
        }
        
        return "";
    }
};