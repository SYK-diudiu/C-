<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <title>设置边框样式</title>
    <style>
      div {
        width: 600px;
        height: 50px;
        line-height: 50px;
        text-align: center;
        margin: 20px;
        border: 8px solid #f00;
      }

      .one {
        border-style: double;
      }
      .two {
        border-style: dotted double;
      }
      .three {
        border-style: solid dotted dashed;
      }
      .four {
        border-style: solid dotted dashed double;
      }
    </style>
  </head>

  <body>
    <div class="one">四条边框相同</div>
    <div class="two">阿巴阿巴阿巴阿巴</div>
    <div class="three">无情铁手</div>
    <div class="four">我给你补个蛋！！！</div>
  </body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                <?xml version="1.0" encoding="UTF-8"?>
<session version="1.0">&#x0A;<refactoring comment="Rename package &apos;第一个&apos; to &apos;第二个&apos;&#x0D;&#x0A;- Original project: &apos;实验报告5&apos;&#x0D;&#x0A;- Original element: &apos;实验报告5/src/第一个&apos;&#x0D;&#x0A;- Renamed element: &apos;实验报告5/src/第二个&apos;&#x0D;&#x0A;- Update references to refactored element&#x0D;&#x0A;- Update textual occurrences in comments and strings" description="Rename package &apos;第一个&apos;" flags="589830" hierarchical="false" id="org.eclipse.jdt.ui.rename.package" input="/src&lt;第一个" name="第二个" qualified="false" references="true" stamp="1713227166319" textual="false" version="1.0"/>&#x0A;<refactoring comment="Rename package &apos;Rectangle&apos; to &apos;第四个&apos;&#x0D;&#x0A;- Original project: &apos;实验报告5&apos;&#x0D;&#x0A;- Original element: &apos;实验报告5/src/Rectangle&apos;&#x0D;&#x0A;- Renamed element: &apos;实验报告5/src/第四个&apos;&#x0D;&#x0A;- Update references to refactored element&#x0D;&#x0A;- Update textual occurrences in comments and strings" description="Rename package &apos;Rectangle&apos;" flags="589830" hierarchical="false" id="org.eclipse.jdt.ui.rename.package" input="/src&lt;Rectangle" name="第四个" qualified="false" references="true" stamp="1713228756888" textual="false" version="1.0"/>
</session>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     		if(index <= 0)
				{
					cout << "���벻�Ϸ�" << endl;
					continue;
				}
				if(L_list[index-1] == NULL) //��λ�ò��������� 
				{
					cout << "Wrong" << endl;
					continue;
				}
				Show_list(L_list[index-1]); 
				break;
			case '7':
				cout << "��������Ҫ��ʾ��������1-10����";
				cin >> index;
				if(index <= 0)
				{
					cout << "���벻�Ϸ�" << endl;
					continue;
				}
				if(L_list[index-1] == NULL) //��λ�ò��������� 
				{
					cout << "Wrong" << endl;
					continue;
				}
				Opposite_list(L_list[index-1]);
				break;
			case '8':
				cout << "��������Ҫ�ϲ�����������λ�ã�1-10����" << endl;
				cout << "��һ��λ�ã�";
				cin >> first;
				cout << "�ڶ���λ�ã�";
				cin >> second;
				if(first <= 0 || second <=0 || first == second)
				{
					cout << "���벻�Ϸ�" << endl;
					continue;
				}
				if(L_list[first-1] == NULL || L_list[second-1] == NULL) //��λ�ò��������� 
				{
					cout << "Wrong" << endl;
					continue;
				}
				Merge_list(L_list[first-1] , L_list[second-1]);
				count--;
				break;
			case '9':
				cout << "�˳��ɹ�" << endl;
				exit(1);
				break;
		}	
	}	
}
