#include<iostream>
#include<fstream>
#include<string>

using namespace std;
char letter[27];
struct Word       //定义结构体
{
    string word;
    size_t length;
    Word* next;
    int repnum;//repeat number 重复次数
    bool ifdel;//if delete 是否被删除
    Word(string _word, size_t _lendth = 0, Word* _next = NULL, int _repnum = 1, bool _ifdel = false) :
        word(_word), length(_lendth), next(_next), repnum(_repnum), ifdel(_ifdel){}
};

Word *head = NULL, *tail = NULL;
int size = 0;  //链表长度，即单词总个数
int delsum = 0;//delete sum 被删除的总个数

void Push(const string& str, const size_t& len)   //形成链表
{
    if (NULL == head)
    {
        head = tail = new Word(str, len, NULL, 1, false);
    }
    else
    {
        tail->next = new Word(str, len, NULL, 1, false);
        tail = tail->next;
    }
    size++;
}

void Destory()   //delete new
{
    Word* ptr = head;
    while (ptr)
    {
        Word* pt = ptr;
        ptr = ptr->next;
        delete pt;
    }
    head = tail = NULL;
    size = 0;
}

void Readin(string& mystr)   //read in  读入
{
    string temps;

    for (size_t i = 0; i < mystr.length(); i++)
    {
        if (mystr[i] >= 'a'&&mystr[i] <= 'z'  )
        {
            temps += mystr[i];
        }
		else if(mystr[i] >= 'A'&&mystr[i] <= 'Z')
		{
			temps += mystr[i]+32;
		}
        else
        {
            if (!temps.empty())//不空的时候返回0
            {

                Push(temps, temps.length());
                temps.erase(temps.begin(), temps.end());
            }
        }
    }
}
void DeSame()      //delete the same 删除相同的单词（不是真删，只是做标记）
{
    Word* p = head;
    while (p&&p->next)
    {
        while (p->ifdel&&p->next)
        {
            p = p->next;
        }
        Word* pt = p->next;
        while (pt)
        {
            if (!pt->ifdel&&pt->word == p->word)
            {
                p->repnum++;
                pt->ifdel = true;
                delsum++;
            }
            pt = pt->next;
        }
        p = p->next;
    }
}

void Inputp(Word* warr[])   //input point 将未被“删除”的结点的指针传入数组
{
    int i = 0;
    Word* pt = head;
    while (pt)
    {
        if (!pt->ifdel)
        {
            warr[i] = pt;
            i++;
        }
        pt = pt->next;
    }
}

void Sort(Word** warr, int start, int end)   //将指针按其指向的结点的repnum从大到小排序，快排实现
{
    int i = 0, j = 0;
    Word* key = NULL;
    key = warr[start];
    i = start;
    j = end;
    while (i<j)
    {
        while (warr[j]->repnum <= key->repnum&&i<j)j--;
        warr[i] = warr[j];
        while (warr[i]->repnum >= key->repnum&&i<j)i++;
        warr[j] = warr[i];
    }
    warr[i] = key;
    if (i - 1>start)Sort(warr, start, i - 1);
    if (end > i + 1)Sort(warr, i + 1, end);
}

void Show(Word** warr, int len)
{
    for (int i = 0; i < len; i++)
    {
			cout << warr[i]->word << "  " << warr[i]->repnum << endl; 
    }
}

void Calculate(string& mystr)
{
	 string temps;
    for (size_t i = 0; i < mystr.length(); i++)
    {
		switch (mystr[i])
		{
				  case 'A':case 'a':letter[0]++;break;
				  case 'b':case 'B':letter[1]++;break;
				  case 'c':case 'C':letter[2]++;break;
                  case 'd':case 'D':letter[3]++;break;
                  case 'e':case 'E':letter[4]++;break;
                  case 'f':case 'F':letter[5]++;break;
                  case 'g':case 'G':letter[6]++;break;
                  case 'h':case 'H':letter[7]++;break;
                  case 'i':case 'I':letter[8]++;break;
                  case 'j':case 'J':letter[9]++;break;
                  case 'k':case 'K':letter[10]++;break;
                  case 'l':case 'L':letter[11]++;break;
                  case 'm':case 'M':letter[12]++;break;
                  case 'n':case 'N':letter[13]++;break;
                  case 'o':case 'O':letter[14]++;break;
                  case 'p':case 'P':letter[15]++;break;
                  case 'q':case 'Q':letter[16]++;break;
                  case 'r':case 'R':letter[17]++;break;
                  case 's':case 'S':letter[18]++;break;
                  case 't':case 'T':letter[19]++;break;
                  case 'u':case 'U':letter[20]++;break;
                  case 'v':case 'V':letter[21]++;break;
                  case 'w':case 'W':letter[22]++;break;
                  case 'x':case 'X':letter[23]++;break;
                  case 'y':case 'Y':letter[24]++;break;
                  case 'z':case 'Z':letter[25]++;break;
		default:
			break;
		}
    }
	int sum=0;
	for(int i=0;i<26;i++)
	{
		sum+=letter[i];
	
	}
	int accura[27];
	for(int i = 0; i < 26; i++)
		accura[i] =i;
	 for (int i = 0; i < 26 - 1; i++) 
	 {
        for (int j = 0; j < 26 - i - 1; j++) 
		{
			if (letter[accura[j]] < letter[accura[j+1]]) {

				int temp = accura[j];

                accura[j] = accura[j + 1];

                accura[j + 1] = temp;

            }

        }

    }

	for(int i=0;i<26;i++)
	{
		printf("%c:  ",accura[i]+65);
		printf("%.2f\n",(double)letter[accura[i]]/sum*100);
	}

	//全部字母个数
}

int main(int argc, char* argv[])
{

	if (argc != 3)
    {
        printf("输入参数有误");
        return 0;
    }
	 ifstream readfile(argv[2]);
    if (!readfile){ cout << "程序出现异常，自动退出！" << endl; return 0; }
    string str, str1;
    while (!readfile.eof())
    {
        getline(readfile, str1);
        str += str1;
        str += ' ';
    }
    readfile.close();
    Readin(str);

	DeSame();
    Word** wdarr = new Word*[size - delsum];
    Inputp(wdarr);


	  if ((**(argv + 1)) == '-')
    {
        switch (*(*(argv + 1) + 1))//等效于*(argv[1] + 1)
        {
        case 'c':
			Calculate(str);
            break;
		case 'f':
			Sort(wdarr, 0, size - delsum - 1);
			Show(wdarr, size - delsum);
			break;
		
		}
	  } 
    delete[]wdarr;
    Destory();
    return 0;
}