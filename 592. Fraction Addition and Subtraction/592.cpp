class Solution {
public:
    int lcm(int a,int b)
    {
        return (a/gcd(a,b))*b;
    }
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
    string fractionAddition(string expression) 
    {
        if(expression[0]!='-')
        {
            expression.insert(0,"+");
        }
        vector<pair<int,int>>numden;
        bool leave=false,ispos=true;
        int tempnum;
        int i=0;
        pair<int,int>temp;
        while(1)
        {
            tempnum=0;
            if(expression[i]=='+')
            {
                ispos=true;
                i++;
            }
            else if(expression[i]=='-')
            {
                ispos=false;
                i++;
            }
            while(expression[i]<='9' && expression[i]>='0')
            {
                tempnum*=10;
                tempnum+=(int)(expression[i]-'0');
                i++;
                if(expression[i]=='/')
                {
                    i++;
                    break;
                }
            }
            if(ispos)
            {
                temp.first=tempnum;
            }
            if(!ispos)
            {
                temp.first=-tempnum;
            }
            tempnum=0;
            while(expression[i]<='9' && expression[i]>='0')
            {
                tempnum*=10;
                tempnum+=(int)(expression[i]-'0');
                i++;
                if(i==expression.size())
                {
                    leave=true;
                    break;
                }
                if(expression[i]=='+' || expression[i]=='-')
                {
                    break;
                }
            }
            temp.second=tempnum;
            numden.push_back(temp);
            if(leave)
            {
                break;
            }
        }
        string ans;
        for(i=0;i<numden.size();i++)
        {
            int GCD=gcd(abs(numden[i].first),abs(numden[i].second));
            numden[i].first/=GCD;
            numden[i].second/=GCD;
        }
        int LCM=numden[0].second;
        for(i=1;i<numden.size();i++)
        {
            LCM=lcm(LCM,numden[i].second);
        }
        int deno=LCM;
        int nume=0;
        for(i=0;i<numden.size();i++)
        {
            nume+=(LCM*numden[i].first)/numden[i].second;
        }
        if(nume<0)
        {
            ans.push_back('-');
            nume=-nume;
        }
        int GCD=gcd(nume,deno);
        nume/=GCD;
        deno/=GCD;
        string numerator,denominator;
        if(nume==0)
        {
            numerator="0";
        }
        while(nume!=0)
        {
            numerator.push_back((char)(nume%10+48));
            nume/=10;
        }
        reverse(numerator.begin(),numerator.end());
        if(deno==0)
        {
            denominator="0";
        }
        while(deno!=0)
        {
            denominator.push_back((char)(deno%10+48));
            deno/=10;
        }
        reverse(denominator.begin(),denominator.end());
        ans.append(numerator);
        ans.push_back('/');
        ans.append(denominator);
        return ans;
    }
};