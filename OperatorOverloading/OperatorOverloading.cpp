#include <iostream>
#include <list>
using namespace std;

struct YoutubeChannel {
    string Name;
    int SubscribersCount;
	
    YoutubeChannel(string name, int subscribersCount) {
		Name = name;
		SubscribersCount = subscribersCount;
	}

	bool operator==(const YoutubeChannel& yc) const	{
		if (this->Name == yc.Name) return true;
		else return false;
	}
};

ostream& operator<<(ostream& COUT, YoutubeChannel& yc) {
	COUT << "Name: " << yc.Name << endl;
	COUT << "Subscribers: " << yc.SubscribersCount << endl;
	return COUT;
}


struct MyCollection
{
	list<YoutubeChannel>myChannels;

	void operator+=(YoutubeChannel& yc)
	{
		this->myChannels.push_back(yc);
	}
	void operator-=(YoutubeChannel& yc)
	{
		this->myChannels.remove(yc);
	}
};

ostream& operator<<(ostream& COUT, MyCollection& mc) {
	for (YoutubeChannel ytChannel:mc.myChannels)
	{
		COUT << ytChannel << endl;
	}
	return COUT;
}


int main()
{
    YoutubeChannel yt1 = YoutubeChannel("KTUCENG", 1000);
    YoutubeChannel yt2 = YoutubeChannel("KTUEEE", 500);
    cout << yt1;

	MyCollection myCollection;
	myCollection += yt1;
	myCollection += yt2;
	myCollection -= yt2;

	cout << myCollection;	
}

