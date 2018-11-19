 #include <iostream>
 #include <cstring>
 #include<cstdlib>
 using namespace std;
 void binaryIp()
 {
 	string s;
	int i;
	cout<<"enter an ip address"<<endl;
	cin>>s;
	for( i=0;s[i]!='0' && i<4;i++);
	if(i==4)
	cout<<"E";
	else cout<<char('A'+i);	
	
 }
 void decimalIP()
 {
 	int i;
 	string temp="";
 	string s;
 	cout<<"enter the ip address in decimal format"<<endl;
 	cin>>s;
 	for(i=0; s[i]!='.';i++)
 	{
 		temp+=s[i];
	 }
	 const char *c = temp.c_str();
 	i=atoi(c);
 	cout<<i<<endl;
 	if(i>=0 &&i<=127)
 	{
 		cout<<"belongs to class A";
	 }
 		else if(i>=128 && i<=191)
 		{
 			cout<<"belongs to class B";
		 }
		 	else if(i>191 && i<=224)
 		{
 			cout<<"belongs to class C";
		 }
		 	else if(i<224 && i<=239)
 		{
 			cout<<"belongs to class D";
		 }
		 else if(i>239&&i<=255)
		 cout<<"e";
		 else cout<<"invalid value ";
	 
 }
 int main()
{cout<<"in which mode u wanna enter ip in  input 1 for decimal 2.for binary"<<endl;
int n;
cin>>n;
if(n==1)
{
	decimalIP();
}
else
binaryIp();

	
	return 0;
}
