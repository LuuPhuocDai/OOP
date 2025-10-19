#include "iostream"
using namespace std;


// vector 2d.
class vector{
	private:
		int x;
		int y;
		int kq;
	public:
		// khai bao.
		vector(){
			x = 0;
			y = 0;
			kq = 0;
		}
		
		// hai vector cho san
		vector(int a, int b){
			x = a;
			y = b;
		}
		
		// xuat hai vector.
		friend ostream& operator <<(ostream& COUT, vector a){
			COUT<< a.x <<", "<< a.y;
			return COUT;
		}
		
		// xuat ket qua cua tich vo huong (<).
		friend ostream& operator <(ostream& COUT, vector a){
			COUT<< a.kq;
			return COUT;
		}
		
		// cong hai vector.
		friend vector operator +(vector a, vector b){
			vector c;
			c.x = a.x + b.x;
			c.y = a.y + b.y;
			return c;
		}
		
		// tru hai vector.
		friend vector operator -(vector a, vector b){
			vector c;
			c.x = a.x - b.x;
			c.y = a.y - b.y;
			return c;
		}
		
		// tich vo huong.
		friend vector operator *(vector a, vector b){
			vector c;
			c.x = a.x * b.x;
			c.y = a.y * b.y;
			c.kq = c.x + c.y;
			return c;
		}
		
		// so sach hai vector.
		friend bool operator ==(vector a, vector b){
			if(a.x == b.x){
				if(a.y == b.y){
					return true;
				}
			}
			return false;
		}
};

// ham main.
int main(){
	vector a = vector(5, 6);
	vector b = vector(8, 9);
	cout<<"hai vector a va b:"<< endl;
	cout<<"vector a("<< a <<")" << endl <<"vector b("<< b<<")"<< endl;
	
	// phep cong hai vector.
	cout<< endl;
	vector tong = a + b;
	cout<<"vector a + b = ("<< tong <<")" << endl;
	
	// phep tru hai vector.
	cout<< endl;
	vector hieu = a - b;
	cout<<"vector a - b = ("<< hieu <<")" << endl;
	
	// tich vo huong cua vector.
	cout<< endl;
	vector tich = a * b;
	cout<<"tich vo huong vector ab = ";
	cout< tich; // danh cho ket qua cua tich.
	
	// so sanh hai vector.
	cout<< endl << endl;
	if(a == b) cout<<"Hai vector a va b bang nhau.";
	else cout<<"Hai vector a va b khong bang nhau.";
	
	return 0;
}