#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t=0;
    cin>>t;
    while(t--){
        int n=0,temp=0,sum=0,k=0,l=0;
        cin>>n>>k>>l;
        vector<int>v(n);
        int input=0;
        for(int i=0;i<n;i++){
            cin>>input;
            v.push_back(input);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        temp=sum;
        for(int i=1;i<=k;i++){
            for(int j=n-i;j<n;j++){
                temp-=2*v[j];
            }
            if(temp>=sum){
                sum=temp;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}