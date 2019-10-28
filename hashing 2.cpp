#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;

class hash
{
	string key[MAX];
	string value[MAX];
	int flag[MAX];
	int chain[MAX];

public:
	hash()
	{
		for(int i=0;i<MAX;i++)
		{
			key[i]="#";
			value[i]="#";
			flag[i]=-1;
			chain[i]=-1;
		}
	}

	void display()
	{
		for(int i=0;i<MAX;i++)
		{
			cout<<"\nkey: "<<key[i]<<"\tValue: "<<value[i]<<"\tChain: "<<chain[i];
		}
	}

	int hashf(string key)
	{
		int ascii=0;
		for(int i=0;i<key.length();i++)
			ascii=ascii+key[i];
		return ascii%MAX;
	}

	void insertwor()
	{
		string word,mean;
		cout<<"Enter the key: ";
		cin>>word;
		cout<<"Enter the meaning: ";
		cin>>mean;

		int index=hashf(word);

		if(flag[index]==-1)
		{
			key[index]=word;
			value[index]=mean;
			flag[index]=0;
			return;
		}

		else if(hashf(key[index])==index)
		{
			int ind2=index;
			while(chain[ind2]!=-1)
			{
				ind2=chain[ind2];
			}

			for(int i=ind2+1;i!=ind2;i=(i+1)%MAX)
			{
				if(flag[i]==-1)
				{
					key[i]=word;
					value[i]=mean;
					flag[i]=0;
					chain[ind2]=i;
					return;
				}
			}
			cout<<"Table full.\n";
			return;
		}
		else{
			int index2;
			for(int i=index+1;i!=index;i=(i+1)%MAX)
			{
				if(index==hashf(key[i]))
				{
					if(chain[i]==-1)
					{
						index2=i;
					}
					else{
						int ind=i;
						while(chain[ind]!=-1)
						{
							ind=chain[ind];
						}
						index2=ind;
					}
				}
			}


			for(int i=index+1;i!=index;i=(i+1)%MAX)
			{
				if(flag[i]==-1)
				{
					key[i]=word;
					value[i]=mean;
					flag[i]=0;
					chain[index2]=i;
					return;
				}
			}

			cout<<"Table full.\n";
			return;
		}

	}

	void insertr()
	{
		string word,mean;
		cout<<"Enter the key: ";
		cin>>word;
		cout<<"Enter the meaning: ";
		cin>>mean;

		int index=hashf(word);

		if(flag[index]==-1)
		{
			key[index]=word;
			value[index]=mean;
			flag[index]=0;
			return;
		}

		else if(hashf(key[index])==index)
		{
			int ind2=index;
			while(chain[ind2]!=-1)
			{
				ind2=chain[ind2];
			}

			for(int i=ind2+1;i!=ind2;i=(i+1)%MAX)
			{
				if(flag[i]==-1)
				{
					key[i]=word;
					value[i]=mean;
					flag[i]=0;
					chain[ind2]=i;
					return;
				}
			}
			cout<<"Table full.\n";
			return;
		}
		else{

			string tempk=key[index];
			string tempv=value[index];
			key[index]=word;
			value[index]=mean;

			int index2=hashf(tempk);

			while(chain[index2]!=-1 && chain[index2]!=index)
			{
				index2=chain[index2];
			}

			chain[index2]=chain[index];
			chain[index]=-1;

			while(chain[index2]!=-1)
			{
				index2=chain[index2];
			}

			for(int i=index2+1;i!=index2;i=(i+1)%MAX)
			{
				if(flag[i]==-1)
				{
					key[i]=tempk;
					value[i]=tempv;
					flag[i]=0;
					chain[index2]=i;
					return;
				}
			}

			cout<<"Table full.\n";
			return;
		}

	}

};


int main()
{
	hash H;
	H.display();
	H.insertr();
	H.display();
	H.insertr();
	H.display();
	H.insertr();
	H.display();
	H.insertr();
	H.display();
}
