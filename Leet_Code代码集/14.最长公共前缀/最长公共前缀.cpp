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
        //����˵�������ַ�������Ϊ��һ���ַ�

        //min��ʾ����ַ������±�
        //int min = 0;
        //min_length��ʾ����ַ����ĳ���
        int min_length = strs[0].size();
        //��������ַ����ļ��ϣ�Ҳ����˵���ǵĳ�����ͬ
        vector<string> min_strs; 
    
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(min_length > strs[i].size())
		    {
			    min_length = strs[i].size();
			    //min = i;
		    }
        }//�����п��Եõ�min��min_length

        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(min_length == strs[i].size())
            {
                min_strs.push_back(strs[i]);        
            }
        }

        //����ַ���
        string min_str;
        //�ַ����ַ�λ��
        int pos_char = 1;
        if(min_strs.size() > 1)
        {
            min_str = min_strs[0];
            for(int i = 0 ; i < min_strs.size() ; i++)
            {
                //ע�⣺��ѭ���ڵ�if���˳�򲻿ɵ���
                if(min_str[pos_char] != min_strs[i][pos_char]) //���ֲ�ͬ�ַ���ѭ���ж�
                {
                    min_str.erase(min_str.begin()+pos_char , min_str.end());
                    break;
                }
                if(i == min_strs.size()-1) //��ǰpos_charû�����⣬�ظ�ѭ����pos_char������һλ
                {
                    pos_char++;
                    i = 0;
                    
                	if(pos_char == min_length) //pos_char������󳤶�min_length
                    	break;
				}
                                 
            }      
        }
        else
        {
            min_str = min_strs[0];
        }

        pos_char = 1; //������ֵ����min_str�����strs�бȽ�
        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(min_str[pos_char] != strs[i][pos_char]) //���ֲ�ͬ�ַ���ѭ���ж�
             {
                min_str.erase(min_str.begin()+pos_char , min_str.end());
                break;
            }
            if(i == strs.size()-1) //��ǰpos_charû�����⣬�ظ�ѭ����pos_char������һλ
            {
                pos_char++;
                i = 0;
                
                if(pos_char == min_length) //pos_char������󳤶�min_length
                    break;
				
            }                        
        }

        return min_str;
    }
};
