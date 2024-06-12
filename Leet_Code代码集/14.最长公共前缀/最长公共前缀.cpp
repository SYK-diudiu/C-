class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin() , strs.end());
        if(strs[0][0] != strs[strs.size()-1][0])
        {
            return "";
        }
        //到此说明公共字符串至少为第一个字符

        //min表示最短字符串的下标
        //int min = 0;
        //min_length表示最短字符串的长度
        int min_length = strs[0].size();
        //所有最短字符串的集合，也就是说它们的长度相同
        vector<string> min_strs; 
    
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(min_length > strs[i].size())
		    {
			    min_length = strs[i].size();
			    //min = i;
		    }
        }//到本行可以得到min、min_length

        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(min_length == strs[i].size())
            {
                min_strs.push_back(strs[i]);        
            }
        }

        //最短字符串
        string min_str;
        //字符串字符位置
        int pos_char = 1;
        if(min_strs.size() > 1)
        {
            min_str = min_strs[0];
            for(int i = 0 ; i < min_strs.size() ; i++)
            {
                //注意：本循环内的if语句顺序不可调换
                if(min_str[pos_char] != min_strs[i][pos_char]) //出现不同字符，循环中断
                {
                    min_str.erase(min_str.begin()+pos_char , min_str.end());
                    break;
                }
                if(i == min_strs.size()-1) //当前pos_char没有问题，重复循环，pos_char进入下一位
                {
                    pos_char++;
                    i = 0;
                    
                	if(pos_char == min_length) //pos_char到达最大长度min_length
                    	break;
				}
                                 
            }      
        }
        else
        {
            min_str = min_strs[0];
        }

        pos_char = 1; //重置数值，将min_str带入大strs中比较
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(min_str[pos_char] != strs[i][pos_char]) //出现不同字符，循环中断
             {
                min_str.erase(min_str.begin()+pos_char , min_str.end());
                break;
            }
            if(i == strs.size()-1) //当前pos_char没有问题，重复循环，pos_char进入下一位
            {
                pos_char++;
                i = 0;
                
                if(pos_char == min_length) //pos_char到达最大长度min_length
                    break;
				
            }                        
        }

        return min_str;
    }
};
