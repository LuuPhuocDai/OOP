#include <iostream>
using namespace std;

// lop time.
class time{
	private:
		int second;
		int minute;
		int hour;
	public:
		// khai bao.
		time(){
			second = 0;
			minute = 0;
			hour = 0;
		}
		
		// ham nhap time gom gio, phut, giay.
		void intPutTime(){
			cout<<"nhap gio: "; cin >> hour;
			cout<<"nhap phut: "; cin >> minute;
		}
		
		// xuat thoiw gian.
		void outPutTime(){
			cout<< hour <<":"<< minute;
		}
		
		// nhap time.
		friend istream& operator >>(istream& CIN, time& a){
			CIN >> a.second;
			return CIN;
		}
		
		// cong so giay.
		friend time operator + (time a, time b){
			time c;
			c.second = a.second + b.second;
			return c;
		}
		
		// chuyen doi gio.
	    void conver(){
	        while(second >= 60) {
	        	minute;
		        ++minute;
		       second -= 60;
	        }
	        while(minute >= 60) {
	        	hour;
		        ++hour;
		       minute -= 60;
	        }
	        while(hour >= 12) {
		       hour -= 12;
	        }
		}
		
		// xuat time.
		friend ostream& operator <<(ostream& COUT, time& a){
			a.conver();
			COUT<<":"<< a.second;
			return COUT;
		}
		
		// tang them giay .( 1s).
		// ++second.
		time& operator ++(){
			++second;
			return *this;
		}
		
		// second++.
		time operator ++(int) {
           time temp = *this;
           second++;
           return temp;
        }
};


// ham main.
int main(){
	time a, b;
	
	// nhap time.
	a.intPutTime();
	cout<<"nhap so giay: ";
	cin >> a;
	
	// xuat thoi gian ban dau.
	cout<<"thoi gian ban dau: ";
	a.outPutTime();
	cout<< a << endl;
	
	// nhap so giay muon them.
	cout<<"\nnhap so giay ban muon cong: "; 
	cin >> b;
	
	// cong so giay.
	time c = a + b;
	cout<<"thoi gian sau khi thay doi: ";
	a.outPutTime();
	cout<< c << endl;
	
	// cong them giay(1s).
	// theo tien to(++time).
	c++;
	cout<<"\n++time: ";
	a.outPutTime();
	cout<< c;
	
	// theo hau to(time++).
	// cong them giay(1s).
	++c;
	cout<<"\ntime++: ";
	a.outPutTime();
	cout<< c;

	return 0;
}


