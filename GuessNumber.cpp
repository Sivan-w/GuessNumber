#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<random>

using namespace std;

class answer
{
public:
    int answ[4];
    answer()
    {
        answ[0] = getRandom();
        do
        {
            answ[1] = getRandom();
        } while (answ[1] == answ[0]);
        do
        {
            answ[2] = getRandom();
        } while (answ[2] == answ[0] || answ[2] == answ[1]);
        do
        {
            answ[3] = getRandom();
        } while (answ[3] == answ[0] || answ[3] == answ[1] || answ[3] == answ[2]);
    }
    int getRandom()
    {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist6(0, 9); // distribution in range [0,9]
        return dist6(rng);
    }
};

bool decideSringIsNum(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        int tmp = (int)str[i];
        if (tmp >= 48 && tmp <= 57)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void begin()
{
    //初始化
    answer Ans;
    int A[8] = { 0 };
    int B[8] = { 0 };
    int triedNum[8];
    string str;
    int round = 0;
    //游戏中
    for(; round <= 7; str.clear())
    {
        cout <<endl<< "请输入数字：";
        cin >> str;
        if (str == "3")
        {
            return;
        }
        else if (str.length() != 4)
        {
            cout << "输入有误！请输入四位不重复数字！！" << endl;
            str.clear();
            continue;
        }
        else if (!decideSringIsNum(str))
        {
            cout << "输入有误！请输入四位不重复数字！！" << endl;
            str.clear();
            continue;
        }
        stringstream numStr(str);
        numStr >> triedNum[round];
        for (int i = 0; i < 4; i++)
        {
            if (triedNum[round] / 1000 == Ans.answ[i])
            {
                if (i == 0)
                    A[round]++;
                else
                    B[round]++;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (triedNum[round]%1000/100 == Ans.answ[i])
            {
                if (i == 1)
                    A[round]++;
                else
                    B[round]++;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (triedNum[round] %100/10 == Ans.answ[i])
            {
                if (i == 2)
                    A[round]++;
                else
                    B[round]++;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (triedNum[round] % 10 == Ans.answ[i])
            {
                if (i == 3)
                    A[round]++;
                else
                    B[round]++;
            }
        }
        system("cls");
        for (int i = 0; i < round + 1; i++)
        {
            cout << endl << i+1 << "   " << triedNum[i] / 1000
                << " " << triedNum[i] % 1000 / 100
                << " " << triedNum[i] % 100 / 10
                << " " << triedNum[i] % 10 << "   "
                << A[i] << "A" << " " << B[i] << "B";
        }
        if (A[round] == 4)
        {
            cout << endl << "你赢了ヾ(≧▽≦*)o" << endl;
            return;
        }
        round++;
    }
    cout << endl << "你输了＞﹏＜" << endl<<"答案：";
    for (int i = 0; i < 4; i++)
        cout << Ans.answ[i];
    return;
}

int main()
{
    while (1)
    {
        cout << "1 开始游戏" << endl;

        cout << "2 退出" << endl << ":";
        int flag = 0;
        cin >> flag;
        switch (flag)
        {
            case 1:
            {
                begin();
                break;
            }
            case 2:
            {
                return 0;
            }

            default: 
            {
                cout << "输入不规范，请重新输入！";
                break;
            }
        }
    }
}
