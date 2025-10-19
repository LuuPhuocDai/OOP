#include "iostream"
using namespace std;

class soPhuc{
	private:
		float phanThuc, phanAo;
	public:
		// khai bao.
		soPhuc(){
			phanThuc = 0;
			phanAo = 0;
		}
		
		// ham xuat va ham nhap thong thuong.
		// xuat.
		void outPut(){
			if (phanAo == 0)
               cout << phanThuc << endl;
            else if (phanAo < 0)
                cout << phanThuc << " - " << -phanAo << "i"<< endl;
            else
			    cout << phanThuc << " + " << phanAo << "i"<< endl;
            }
            
        // nhap
		void inPut(){
			cout<<"nhap phan thuc: "; cin >> phanThuc;
			cout<<"nhap phan ao: "; cin >> phanAo;
			cout<< endl;
		}
		
		// ham friend.
		// nhap bang pp operator.
		friend istream& operator >> (istream& CIN, soPhuc& a){
			a.inPut();
			return CIN;
		}
		
		// ham xuat bang  pp operator.
		friend ostream& operator << (ostream& COUT, soPhuc& a){
			a.outPut();
			return COUT;
		}
		
		// ham cong bang pp operator.
		soPhuc operator + (soPhuc a){
			soPhuc result;
			result.phanThuc = this->phanThuc + a.phanThuc;
			result.phanAo = this->phanAo + a.phanAo;
			return result;
		}
		
		// ham tru bang pp operator.
		soPhuc operator - (soPhuc a){
			soPhuc result;
			result.phanThuc = this->phanThuc - a.phanThuc;
			result.phanAo = this->phanAo - a.phanAo;
			return result;
		}
		
		// ham nhan bang pp operator.
		soPhuc operator * (soPhuc a){
			soPhuc result;
			result.phanThuc = (this->phanThuc * a.phanThuc) - (this->phanAo * a.phanAo);
			result.phanAo = (this->phanThuc * a.phanAo) + (this->phanAo * a.phanThuc);
			return result;
		}
};

// ham main.
int main(){
	soPhuc a, b;
	
	// xuat va nhap so phuc.
	cin >> a >> b;
	cout<< a << endl << b << endl;
	
	// phep tinh so phuc.
	// phep cong.
	cout<<"phep cong: "<< endl;
	soPhuc Tong = a + b;
	cout<< Tong << endl;
	
	// phep tru.
	cout<<"phep tru: "<< endl;
	soPhuc hieu = a - b;
	cout<< hieu << endl;
	
	// phep nhan.
	cout<<"phep nhan:"<< endl;
	soPhuc tich = a * b;
	cout<< tich << endl; 
	return 0;
}


