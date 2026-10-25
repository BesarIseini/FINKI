#include <iostream>
#include <cstring>

using namespace std;

class Podcast {
protected:
	char name[100];
	char url[1000];
	float cost;
	int discount;
public:
	Podcast(char * name = "", char * url = "", float cost = 0.0, int discount = 0) {
		strcpy(this->name, name);
		strcpy(this->url, url);
		this->cost = cost;
		this->discount = discount;
	}
	~Podcast() {
	}

	bool operator==(const Podcast &p) {
		return !strcmp(url, p.url);
	}

	virtual void print(ostream &os) const {
		os << "Podcast: " << name << endl;
		os << "URL: " << url << endl;
		os << "regular price: $" << cost;
		if (discount) os << ", bought on discount";
	}


	friend ostream & operator<<(ostream &os, const Podcast &p) {
		p.print(os);
		return os;
	}
	friend istream &operator>>(istream &is, Podcast &p) {
		is.get();
		is.getline(p.name, 100);
		is.getline(p.url, 1000);
		is >>p.cost >> p.discount;

		return is;
	}

	virtual float get_price(){
		return cost * (1.0 - (this->discount/100.0));
	}


};

class StreamingPodcast: public Podcast {
	float monthlyFee;
	int month, year;
public:
	StreamingPodcast(char * name = "", char * url = "", float cost = 0.0, int discount = 0, float monthlyFee = 0, int month = 0, int year = 0):
	Podcast(name, url, cost, discount) {
		this->monthlyFee = monthlyFee;
		this->month = month;
		this->year = year;
	}

	~StreamingPodcast() {

	}

	void print(ostream &os) const override {
		Podcast::print(os);
		os << ", monthly fee: $" << monthlyFee
		   << ", purchased: " << month << "-" << year;
	}

	friend ostream & operator<<(ostream &os, const StreamingPodcast &sp) {
		sp.print(os);
		return os;
	}
	friend istream &operator>>(istream &is, StreamingPodcast &sp) {
		is.get();
		is.getline(sp.name, 100);
		is.getline(sp.url, 1000);
		is >>sp.cost >> sp.discount >> sp.monthlyFee >> sp.month >> sp.year;
		return is;
	}

	float get_price(){
		float p = Podcast::get_price();

		int months=0;
		if (year<2018){
			months = (12 - this->month) + (2017 - year)*12 + 5;
		}
		else {
			months = 5 - this->month;
		}

		p += months * monthlyFee;

		return p;
	}
};
class ExistingPodcast {
	char text[50];
public:
	ExistingPodcast(char *text) {
		strcpy(this->text, text);
	}
	void message() {
		cout << text << endl;
	}
};

class Playlist {
	char name[100];
	Podcast ** podcasts;
	int n;
public:

	Playlist(char * name = "", Podcast ** podcasts = nullptr, int n = 0) {
		strcpy(this->name, name);
		this->podcasts = new Podcast * [n];
		for (int i = 0; i < n; i++) {
			this->podcasts[i] = podcasts[i];
		}
		this->n = n;
	}
	~Playlist() {
		delete [] podcasts;
	}
	Playlist & operator+=(Podcast &p) {
		Podcast **temp = new Podcast * [n + 1];
		for (int i = 0; i < n; i++) {
			if ((*(podcasts[i])) == p) {
				throw ExistingPodcast("The podcast is already in the collection");
			}
			temp[i] = podcasts[i];
		}
		StreamingPodcast * sg = dynamic_cast< StreamingPodcast* >(&p);

		if(sg){

			temp[n] = new StreamingPodcast(*sg);
		}
		else {
			temp[n] = new Podcast(p);
		}

		n++;
		delete [] this->podcasts;
		this->podcasts = temp;
	}

	float total_spent() {
		float sum = 0.0;
		for (int i = 0; i < n; i++) {
			sum += podcasts[i]->get_price();
		}
		return sum;
	}

	friend ostream & operator<<(ostream &os, const Playlist & p) {
		os << endl << "Playlist: " << p.name << endl;
		for (int i = 0; i < p.n; i++) {

			os << *p.podcasts[i] << endl;
		}
		os << endl;
		return os;
	}
};

int main() {
  int test_case_num;

  cin>>test_case_num;

  // for Podcast
  char podcast_name[100];
  char podcast_url[1000];
  float podcast_price;
  int podcast_discount;

  // for StreamingPodcast
  float sub_podcast_monthly_fee;
  int sub_podcast_month, sub_podcast_year;

  // for Playlist
  char name[100];
  int num_podcasts_in_playlist;

  if (test_case_num == 1){
    cout<<"Testing class Podcast and operator&lt;&lt; for Podcast"<<std::endl;
    cin.get();
    cin.getline(podcast_name,100);
    cin.getline(podcast_url, 1000);
    //cin.get();
    cin>>podcast_price>>podcast_discount;

    Podcast p(podcast_name, podcast_url, podcast_price, podcast_discount);

    cout<<p;
  }
  else if (test_case_num == 2){
    cout<<"Testing class StreamingPodcast and operator&lt;&lt; for StreamingPodcast"<<std::endl;
    cin.get();
    cin.getline(podcast_name,100);
    cin.getline(podcast_url, 1000);
    //cin.get();
    cin>>podcast_price>>podcast_discount;

    cin>>sub_podcast_monthly_fee;
    cin>>sub_podcast_month>>sub_podcast_year;

    StreamingPodcast sp(podcast_name, podcast_url, podcast_price, podcast_discount, sub_podcast_monthly_fee, sub_podcast_month, sub_podcast_year);
    cout<<sp;
  }
  else if (test_case_num == 3){
    cout<<"Testing operator&gt;&gt; for Podcast"<<std::endl;
    Podcast p;

    cin>>p;

    cout<<p;
  }
  else if (test_case_num == 4){
    cout<<"Testing operator&gt;&gt; for StreamingPodcast"<<std::endl;
    StreamingPodcast sp;

    cin>>sp;

    cout<<sp;
  }
  else if (test_case_num == 5){
    cout<<"Testing class Playlist and operator+= for Playlist"<<std::endl;
    cin.get();
    cin.getline(name,100);
    Playlist u(name);

    int num_user_podcasts;
    int podcast_type;
    cin >>num_user_podcasts;

    try {

      for (int i=0; i<num_user_podcasts; ++i){

        cin >> podcast_type;

        Podcast *g;
        // 1 - Game, 2 - SubscriptionGame
        if (podcast_type == 1){
          cin.get();
          cin.getline(podcast_name, 100);
          cin.getline(podcast_url, 1000);

          cin>>podcast_price>>podcast_discount;
          g = new Podcast(podcast_name, podcast_url, podcast_price, podcast_discount);
        }
        else if (podcast_type == 2){
          cin.get();
          cin.getline(podcast_name, 100);
          cin.getline(podcast_url, 1000);

          cin>>podcast_price>>podcast_discount;

          cin>>sub_podcast_monthly_fee;
          cin>>sub_podcast_month>>sub_podcast_year;
          g = new StreamingPodcast(podcast_name, podcast_url, podcast_price, podcast_discount, sub_podcast_monthly_fee, sub_podcast_month, sub_podcast_year);
        }

        //cout<<(*g);


        u+=(*g);
      }
    }catch(ExistingPodcast &ex){
      ex.message();
    }

    cout<<u;

  }
  else if (test_case_num == 6){
      cout<<"Testing exception ExistingPodcast for Playlist"<<std::endl;
      cin.get();
      cin.getline(name,100);
      Playlist u(name);

      int num_podcasts_in_playlist;
      int podcast_type;
      cin >>num_podcasts_in_playlist;

      for (int i=0; i<num_podcasts_in_playlist; ++i){

          cin >> podcast_type;

          Podcast *g;
          // 1 - Game, 2 - SubscriptionGame
          if (podcast_type == 1){
            cin.get();
            cin.getline(podcast_name, 100);
            cin.getline(podcast_url, 1000);

            cin>>podcast_price>>podcast_discount;
            g = new Podcast(podcast_name, podcast_url, podcast_price, podcast_discount);
          }
          else if (podcast_type == 2){
            cin.get();
            cin.getline(podcast_name, 100);
            cin.getline(podcast_url, 1000);

            cin>>podcast_price>>podcast_discount;

            cin>>sub_podcast_monthly_fee;
            cin>>sub_podcast_month>>sub_podcast_year;
            g = new StreamingPodcast(podcast_name, podcast_url, podcast_price, podcast_discount, sub_podcast_monthly_fee, sub_podcast_month, sub_podcast_year);
          }

          //cout<<(*g);

          try {
            u+=(*g);
          }
          catch(ExistingPodcast &ex){
            ex.message();
          }
        }

      cout<<u;
  }
  else if (test_case_num == 7){
      cout<<"Testing total_spent method() for Playlist"<<std::endl;
      cin.get();
      cin.getline(name,100);
      Playlist u(name);

      int num_podcasts_in_playlist;
      int podcast_type;
      cin >>num_podcasts_in_playlist;

      for (int i=0; i<num_podcasts_in_playlist; ++i){

          cin >> podcast_type;

          Podcast *g;
          // 1 - Game, 2 - SubscriptionGame
          if (podcast_type == 1){
            cin.get();
            cin.getline(podcast_name, 100);
            cin.getline(podcast_url, 1000);

            cin>>podcast_price>>podcast_discount;
            g = new Podcast(podcast_name, podcast_url, podcast_price, podcast_discount);
          }
          else if (podcast_type == 2){
            cin.get();
            cin.getline(podcast_name, 100);
            cin.getline(podcast_url, 1000);

            cin>>podcast_price>>podcast_discount;

            cin>>sub_podcast_monthly_fee;
            cin>>sub_podcast_month>>sub_podcast_year;
            g = new StreamingPodcast(podcast_name, podcast_url, podcast_price, podcast_discount, sub_podcast_monthly_fee, sub_podcast_month, sub_podcast_year);
          }

          //cout<<(*g);

          try {
            u+=(*g);
          }
          catch(ExistingPodcast &ex){
            ex.message();
          }
        }

      cout<<u;

      cout<<"Total money spent: $"<<u.total_spent()<<endl;
  }
}