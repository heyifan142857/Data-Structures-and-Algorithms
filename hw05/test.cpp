#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#define RI register int
#define CI const int&
using namespace std;
const int N=605;
string Type,Name[N],bits; map <string,int> rst; vector <int> v[N],order; int idx,hasfa[N],fa[N];
inline int getID(const string& name)
{
    if (rst.count(name)) return rst[name];
    return rst[name]=++idx;
}
inline void DFS(CI now)
{
    order.push_back(now); for (auto to:v[now]) bits+="1",DFS(to),bits+="0";
}
int main()
{
    RI i; getline(cin,Type);
    if (Type=="ENCODE")
    {
        string s; while (getline(cin,s))
        {
            int pos; string boss; vector <int> space;
            for (i=0;i<s.size();++i)
            {
                if (s[i]==':') boss=s.substr(0,i);
                if (s[i]==' ') space.push_back(i);
            }
            //cout<<"boss="<<boss<<endl; 
            int now=getID(boss);
            for (i=0;i<space.size();++i)
            {
                string employ=s.substr(space[i]+1,(i+1<space.size()?space[i+1]:s.size())-space[i]-1);
                //cout<<"employ="<<employ<<endl;
                int nxt=getID(employ); v[now].push_back(nxt); hasfa[nxt]=1;
            }
        }
        for (auto [name,id]:rst) Name[id]=name;
        int rt; for (i=1;i<=idx;++i) if (!hasfa[i]) { rt=i; break; }
        DFS(rt); for (auto x:order) cout<<Name[x]<<endl;
        cout<<bits<<endl;
    } else
    {
        string s; int n=0;
        while (cin>>s)
        {
            if (s[0]=='0'||s[0]=='1') break;
            Name[++n]=s;
        }
        int cur=1,now=1; for (i=0;i<s.size();++i)
        if (s[i]=='1') ++cur,v[now].push_back(cur),fa[cur]=now,now=cur; else now=fa[now];
        for (i=1;i<=n;++i) if (!v[i].empty())
        {
            cout<<Name[i]<<":";
            for (auto j:v[i]) cout<<" "<<Name[j];
            cout<<endl;
        }
    }
    
    return 0;
}

