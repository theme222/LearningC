#include <bits/stdc++.h>
#define r round
using namespace std;int main(){double _;cin>>_;char unit=0;if(_>=1e9){unit = 'B';_/=1e9;}else if(_>=1e6){unit = 'M';_ /= 1e6;}else if (_>=1e3){unit ='K';_/= 1e3;}if(_<10)_=r(_ * 10)/10;else _= r(_);cout<<_;if(unit!=0)cout<<unit;}
