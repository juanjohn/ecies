#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
#define gc getchar_unlocked
using namespace std;

void inp(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

struct point{
	ll x;
	ll y;
};

ll modul(ll a,ll b){
	a=a%b;
	if(a<0)
		a+=b;
	return a;
}

ll EGCD(ll a, ll b, ll& u, ll &v){ 
	u = 1; 
	v = 0; 
	ll g = a; 
	ll u1 = 0;
	ll v1 = 1; 
	ll g1 = b; 
	while (g1 != 0){
		ll q = g/g1;
		ll t1 = u - q*u1;
		ll t2 = v - q*v1;
		ll t3 = g - q*g1;
		u = u1; v = v1; g = g1;
		u1 = t1; v1 = t2; g1 = t3;
	}              
	return g;
}

ll invMod(ll x,ll n){
	x = modul(x,n);
	ll u,v,g,z;
	g = EGCD(x,n,u,v);
	if (g != 1){
		z = 0;
    }
    else{
    	z = modul(u,n);
    }
    return z;
}

ll slope(point A,point B,ll a,ll p){
	ll s;
	if(A.x==B.x && A.y==B.y){
		s=(3*A.x*A.x+a)*invMod(2*A.y,p);
	}
	else{
		s=(B.y-A.y)*invMod(B.x-A.x,p);
	}
	return modul(s,p);
}

point pointSum(point A,point B,ll a,ll p){
	ll m=slope(A,B,a,p);
	point R;
	R.x=modul(m*m-A.x-B.x,p);
	R.y=modul(m*(A.x-R.x)-A.y,p);
	return R;
}

int main(){
	ll i,j,a,b,n,p;
	point A,B,R;
	p=17;
	a=2;b=2;
	A.x=5;A.y=1;
	R.x=5;R.y=1;
	for(i=0;i<24;i++){
		R=pointSum(A,R,a,p);
		printf("%lld %lld %lld\n",i+2,R.x,R.y);
	}
	return 0;
}