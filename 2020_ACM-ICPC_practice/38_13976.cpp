#include<cstdio>
int main(){
	long long n,mod=1000000007,a[2][2]={{0,1},{1000000006,4}},b[2][2]={{1,0},{0,1}};
	scanf("%lld",&n);
	if(n%2) printf("0\n");
	else if(n==2) printf("3\n");
	else{
		n=n/2-1;
		while(n){
			if(n%2){
				long long t[2][2]={
					{(a[0][0]*b[0][0]+a[0][1]*b[1][0])%mod,(a[0][0]*b[0][1]+a[0][1]*b[1][1])%mod},
					{(a[1][0]*b[0][0]+a[1][1]*b[1][0])%mod,(a[1][0]*b[0][1]+a[1][1]*b[1][1])%mod}
				};
				b[0][0]=t[0][0],b[0][1]=t[0][1],b[1][0]=t[1][0],b[1][1]=t[1][1];
			}
			long long t[2][2]={
				{(a[0][0]*a[0][0]+a[0][1]*a[1][0])%mod,(a[0][0]*a[0][1]+a[0][1]*a[1][1])%mod},
				{(a[1][0]*a[0][0]+a[1][1]*a[1][0])%mod,(a[1][0]*a[0][1]+a[1][1]*a[1][1])%mod}
			};
			a[0][0]=t[0][0],a[0][1]=t[0][1],a[1][0]=t[1][0],a[1][1]=t[1][1];
			n>>=1;
		}
		printf("%lld\n",(b[1][0]+b[1][1]*3)%mod);
	}
}
/*
| dp[i-2] | = |0  1| | dp[i-4] |
| dp[i]   |   |-1 4| | dp[i-2] |
*/
