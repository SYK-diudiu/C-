#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs[0] == "")
            return "";
        sort(strs.begin() , strs.end());
        if(strs[0][0] != strs[strs.size()-1][0])
        {
            return "";
        }
        //到此说明公共字符串至少为第一个字符

        int pos = 0;
        //max_length表示最短字符串的长度
        int max_length = strs[0].size();
        //所有最短字符串的集合，也就是说它们的长度相同
    
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(max_length < strs[i].size())
		    {
			    max_length = strs[i].size();
			    pos = i;
		    }
        }//到本行可以得到max_length


        //最长字符串
        string max_str = strs[pos];
        //字符串字符位置
        int pos_char = 1;
        if(max_str.size() > 1)
        {
            for(int i = 0 ; i < strs.size() ; i++)
            {
                if(max_str[pos_char] != strs[i][pos_char]) //出现不同字符，循环中断
                {
                    max_str.erase(max_str.begin()+pos_char , max_str.end());
                    break;s 
                }
                if(i == strs.size()-1) //当前pos_char没有问题，重复循环，pos_char进入下一位
                {
                    pos_char++;
                    i = 0;
                    
                    if(pos_char == max_length) //pos_char到达最大长度max_length
                        break;
                }                        
            }
            return max_str;
        }
        else
        {
            return max_str;
        }
        
    }
};

int main()
{
	
}
