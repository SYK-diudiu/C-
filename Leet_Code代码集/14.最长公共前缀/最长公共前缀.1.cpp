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
        //����˵�������ַ�������Ϊ��һ���ַ�

        int pos = 0;
        //max_length��ʾ����ַ����ĳ���
        int max_length = strs[0].size();
        //��������ַ����ļ��ϣ�Ҳ����˵���ǵĳ�����ͬ
    
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(max_length < strs[i].size())
		    {
			    max_length = strs[i].size();
			    pos = i;
		    }
        }//�����п��Եõ�max_length


        //��ַ���
        string max_str = strs[pos];
        //�ַ����ַ�λ��
        int pos_char = 1;
        if(max_str.size() > 1)
        {
            for(int i = 0 ; i < strs.size() ; i++)
            {
                if(max_str[pos_char] != strs[i][pos_char]) //���ֲ�ͬ�ַ���ѭ���ж�
                {
                    max_str.erase(max_str.begin()+pos_char , max_str.end());
                    break;s 
                }
                if(i == strs.size()-1) //��ǰpos_charû�����⣬�ظ�ѭ����pos_char������һλ
                {
                    pos_char++;
                    i = 0;
                    
                    if(pos_char == max_length) //pos_char������󳤶�max_length
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
