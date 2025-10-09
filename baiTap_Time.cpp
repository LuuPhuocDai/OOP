#include <iostream>
using namespace std;

// lop time.
class time{
	private:
		int second;
		int Time;
	public:
		// khai bao.
		time(){
			second = 0;
			Time = 0;
		}
		
		// nhap time.
		friend istream& operator >>(istream& CIN, time& a){
			cout<<"nhap so giay: "; CIN >> a.second;
			return CIN;
		}
		
		// xuat time.
		friend ostream& operator <<(ostream& COUT, time& a){
			COUT<< a.second <<"s ";
			return COUT;
		}
		
		// cong so giay.
		friend time operator + (time a, time b){
			time c;
			c.second = a.second + b.second;
			return c;
		}
		
		// tang them giay ( 1s).
		void operator ++(){
			second = second + 1;
		}
};

// ham main.
int main(){
	time a, b;
	
	// nhap time.
	cin >> a >> b;
	
	// xuat time.
	cout<<"\ngiay a: "<< a << endl<< "giay b: "<< b << endl;
	
	// cong giay.
	time tong = a + b;
	cout<< endl << a <<"+ "<< b <<"= "<< tong << endl;
	
	// cong them 1s.
	cout<< endl;
	++a;
	cout<<"giay ++a: "<< a << endl;
	++b;
	cout<<"giay ++b: "<< b << endl;
	++tong;
	cout<<"giay ++(a + b): "<< tong << endl;
	
	return 0;
}


