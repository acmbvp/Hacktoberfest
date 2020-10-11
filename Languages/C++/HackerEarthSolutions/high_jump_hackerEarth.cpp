#include<bits/stdc++.h>

//unsolved

using namespace std;

int main()
{
    int i,fg=0;
    float n,m,l,a,p,h,l1,l2,height;
    float x,y;
    float c,start,mid;

    vector< pair<float,float> > obs;

    obs.push_back(make_pair(0,0));

    cin>>n>>m>>l>>a;



    for(i=1;i<=n;i++)
    {
        cin>>p>>h;
        obs.push_back(make_pair(p,h));
    }

    vector< pair<float,float> >::iterator it = obs.begin();
    it++;

    start=0;


    for(i=1;i<=n;i++)
    {
        y = it->second;
        x= it->first;

        c = (y*1.0)/(a*1.0/x);
         if(it->first - c >=start)
            start = it->first + c;
         else
         {
           l1 = (it-1)->second;
           l2 =  it->second;
           mid = ((it->first * 1.0) + ((it-1)->first *1.0))/2.0;

           it->first = mid;

           if(l1>l2)
           {
                 y = (it-1)->second;
                 x= (it-1)->first;

                 c = (y*1.0)-(a*1.0*x);

                 height = a*mid + c;

                 if(height>m)
                    {
                        fg=1;
                    }
                 else
                 {
                     it->first=mid;
                     it->second=height;
                 }
           }
           else
            {
                 y = it->second;
                 x= it->first;

                 c = (y*1.0)+(a*1.0*x);

                 height = a*mid + c;

                 if(height>m)
                    {
                        fg=1;
                    }
                 else
                 {
                     it->first=mid;
                     it->second = height;
                 }
           }
           if(mid-c>=0 && c>0)
           start = mid + c;
           else if(mid - (-1)*c >=0 )
           {
               start = mid + c;
           }
           else
           {
               fg=1;
           }
         }

        it++;
    }
    if(fg)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}
